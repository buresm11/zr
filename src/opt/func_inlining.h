
#pragma once

#include <iostream>

#include "llvm.h"
#include "Compiler.h"

#define MAX_LOC_MUL 5
#define MAX_LOC_TO_INLINE 50

class Vertex
{

public:
    llvm::Function * function;
    bool main;
	int loc;
	int call_inst;
	int branches_inst;
	int recursive_inst;
	
	std::map<Vertex *, int> incoming;
	std::map<Vertex *, int> outgoing;
    std::map<Vertex *, int> calls;


	Vertex(llvm::Function * func) : function(func)
	{
		loc = 0;
		call_inst = 0;
		branches_inst = 0;
		recursive_inst = 0;
        main = false;
	}

	void print()  //DEBUG
	{
        std::cout << std::endl;
        std::cout << "***************" << std::endl;
		std::cout << get_name() <<  "  LOC:" << loc << "  Branched: " << branches_inst << " rec:  " << recursive_inst << "   call: " << call_inst << std::endl;

		std::cout << std::endl;
		std::cout << "incoming::" << std::endl;

		std::map<Vertex *, int>::iterator it;
		for (it = incoming.begin(); it != incoming.end(); it++)
		{
			std::cout << it->first->get_name() << "  " << it->second << std::endl;
		}

		std::cout << std::endl;

		std::cout << "outgoing::" << outgoing_size() << std::endl;

		std::map<Vertex *, int>::iterator itx;
		for (itx = outgoing.begin(); itx != outgoing.end(); itx++)
		{
			std::cout << itx->first->get_name() << "  " << itx->second << std::endl;
		}
		std::cout << "***************" << std::endl;
	}

	void remove()
	{
		std::map<Vertex *, int>::iterator it;
		for (it = incoming.begin(); it != incoming.end(); it++)
		{
			it->first->remove_vertex(this);
		}

		std::map<Vertex *, int>::iterator itx;
		for (itx = outgoing.begin(); itx != outgoing.end(); itx++)
		{
			itx->first->remove_vertex(this);
		}
	}

	void remove_vertex(Vertex * v)
	{
		incoming.erase(v);
		outgoing.erase(v);
	}

	void add_incoming(Vertex * v)
	{
		if(incoming.find(v) == incoming.end())
		{
			incoming[v] = 1;
		}
		else incoming[v]++;
	}

	void add_outgoing(Vertex * v)
	{
		if(outgoing.find(v) == outgoing.end())
		{
			outgoing[v] = 1;
            calls[v] = 1;
		}
		else 
        {
            outgoing[v]++;
            calls[v]++;
        }
	}

	int outgoing_size()
	{
		return outgoing.size();
	}

    bool calls_func(Vertex * vertex)
    {   
        return calls.find(vertex) != calls.end(); 
    }

    std::string get_name() // DEBUG ONLY, not safe to use
    {
        return function->getName().lower();
    }
};

class func_inliningT
{
	llvm::Module * module;

	std::vector<Vertex *> graph;
    std::map<llvm::Function *, Vertex *> vertexes;  
    std::vector<llvm::Function *> inline_order;

	int origin_lines_of_code;
    int actual_lines_of_code;

public:
	func_inliningT()
	{
		origin_lines_of_code = 0;
        actual_lines_of_code = 0;
	}

	bool inline_F(llvm::Module * M)
	{
		module = M;
		
        create_vertexes();
    	analysis();
		linear();
        inline_functions();
        delete_vertexes();
    }

    void create_vertexes()
    {
        auto function_iter = module->begin();
        while(function_iter != module->end())
        {
            if(function_iter->getName() == "print_" || function_iter->getName() == "scan_" || function_iter->getName() == "printb_")
            {
                ++function_iter;
                continue;
            }

            Vertex * v = new Vertex(function_iter);
            graph.push_back(v);
            vertexes[function_iter] = v;

            ++function_iter;
        }
    }

    void delete_vertexes()
    {
        auto it = vertexes.begin();

        while(it != vertexes.end())
        {
            delete it->second;
            ++it;
        }
    }

    void analysis()
    {
        auto function_iter = module->begin();
        while(function_iter != module->end())
        {
            if(vertexes.find(function_iter) == vertexes.end()) // do not care about functions which we did not create vertex for
            {
                ++function_iter;
                continue;
            }

            analysis_function(function_iter);
            ++function_iter;
        }
    }

    void analysis_function(llvm::Function * F)
    {
        int loc = 0;
        int call_inst = 0;
        int branches_inst = 0;
        int recursive_inst = 0;

        Vertex * vertex_F = vertexes[F];

        if(F->getName() == "main") vertex_F->main = true;

        auto basic_block_iter = F->begin();
        while(basic_block_iter != F->end())
        {
            auto instruction_iter = basic_block_iter->begin();
            while(instruction_iter != basic_block_iter->end())
            {
                if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
                {
                    llvm::Function * called_func = inst->getCalledFunction();

                    if(vertexes.find(called_func) != vertexes.end()) // not a runtime functions
                    {
                        if(called_func == F)
                            recursive_inst++;
                        else
                        {
                            Vertex * vertex = vertexes[called_func];

                            vertex_F->add_outgoing(vertex);
                            vertex->add_incoming(vertex_F);
 
                            call_inst++;
                        }
                    }
                }
                else if(llvm::BranchInst * inst = llvm::dyn_cast<llvm::BranchInst>(instruction_iter))
                    branches_inst++;

                loc++;
                ++instruction_iter;
            }
            ++basic_block_iter;
        }

        vertex_F->loc = loc;
        vertex_F->call_inst = call_inst;
        vertex_F->branches_inst = branches_inst;
        vertex_F->recursive_inst = recursive_inst;
        origin_lines_of_code += loc;
        actual_lines_of_code = origin_lines_of_code;
    }

    void linear()
    {
        std::vector<Vertex *>::iterator it = graph.begin();
        while (it != graph.end()) // ignore recursive functions and main function
        {
            if((*it)->recursive_inst > 0 || (*it)->main)
            {
                (*it)->remove();
                it = graph.erase(it);
            }
            else ++it;
        }

        while(!graph.empty())
        {
            if(!cut_off_vertex_no_edges())
                cut_off_vertex_edges();
        }
    }

    bool cut_off_vertex_edges()
    {
        Vertex * vertex_cut = graph.at(0);
        int index = 0;

        for(int i=1;i < graph.size(); i++)
        {
            Vertex * v = graph.at(i);
            if(inline_vertex(v) && v->loc < vertex_cut->loc)
            {
                vertex_cut = v;
                index = i;
            }
        }

        inline_order.push_back(vertex_cut->function);
        vertex_cut->remove();
        graph.erase(graph.begin() + index);

        return true; 
    }

    bool cut_off_vertex_no_edges()
    {
        std::vector<Vertex *>::iterator it = graph.begin();
        while (it != graph.end())
        {
            if(inline_vertex(*it) && (*it)->outgoing_size() == 0)
            {
                inline_order.push_back((*it)->function);

                (*it)->remove();
                graph.erase(it);

                return true;
            }
            ++it;
        }

        return false;
    }

    bool inline_vertex(Vertex * v)
    {
        return v->loc <= MAX_LOC_TO_INLINE;
    }

    void inline_functions()
    {
        std::vector<llvm::Function *>::iterator it = inline_order.begin();
        while (it != inline_order.end()) // ignore recursive function
        {
            while(inline_function(*it)) { }

            ++it;
        }
    }

    bool inline_function(llvm::Function * F)
    {
        auto function_iter = module->begin();
        while(function_iter != module->end())
        {
            auto basic_block_iter = function_iter->begin();

            while(basic_block_iter != function_iter->end())
            {
                auto instruction_iter = basic_block_iter->begin();
                while(instruction_iter != basic_block_iter->end())
                {
                    if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
                    {
                        llvm::Function * called_func = inst->getCalledFunction();

                        if(called_func == F)
                        {
                            Vertex * called_vertex = vertexes[called_func];
                            Vertex * current_vertex = vertexes[function_iter]; 

                            // make sure that non recursive stay non recursive and not exceed maximum lines of code
                            if(!called_vertex->calls_func(current_vertex) 
                                && actual_lines_of_code + called_vertex->loc < MAX_LOC_MUL * origin_lines_of_code)
                            {
                                actual_lines_of_code += called_vertex->loc;
                                current_vertex->loc += called_vertex->loc;

                                replace_call(function_iter,inst,F);
                                return true;
                            }
                        }
                    }
                    ++instruction_iter;
                }
                ++basic_block_iter;
            }
            ++function_iter;
        }

        return false;
    }

    void replace_call(llvm::Function * caller_func, llvm::CallInst * call_inst, llvm::Function * callee_func)
    {
        std::map<llvm::Value *, llvm::Value *> val_to_val;
        std::vector<llvm::BasicBlock *> new_bb;

        llvm::Value * result;
            
        llvm::BasicBlock * first_bb;
        llvm::BasicBlock * after_call_bb = call_inst->getParent()->splitBasicBlock(call_inst->getNextNode());
        after_call_bb->setName("after_call_" + callee_func->getName().lower()); // DEBUG

        auto basic_block_iter = callee_func->begin(); 
        while(basic_block_iter != callee_func->end()) // copy all instruction 
        {
            std::string bb_name = basic_block_iter->getName().lower() + "_inlined"; // DEBUG
            llvm::BasicBlock * bb = llvm::BasicBlock::Create(Compiler::llvm_context, bb_name, caller_func);

            new_bb.push_back(bb);
            val_to_val[basic_block_iter] = bb; 

            auto instruction_iter = basic_block_iter->begin();
            if(basic_block_iter == callee_func->begin()) // copy func header
            {
                if(callee_func->getReturnType() != Compiler::t_void)
                {
                    result = new llvm::AllocaInst(callee_func->getReturnType(), "result", bb);
                }

                first_bb = bb;

                int args_size = callee_func->arg_size();
                for(int i=0;i < args_size * 2; i++)
                {
                    llvm::Instruction * copy_alloca;
                    if(i % 2 == 0)
                    {
                        copy_alloca = instruction_iter->clone();
                        bb->getInstList().push_back(copy_alloca);
                        val_to_val[instruction_iter] = copy_alloca;
                    }
                    else
                    {
                        llvm::StoreInst * si = new llvm::StoreInst(call_inst->getArgOperand(i/2), copy_alloca, false, bb);
                    } 

                    ++instruction_iter;
                }
            }

            while(instruction_iter != basic_block_iter->end())
            {
                llvm::Instruction * copy = instruction_iter->clone();
                bb->getInstList().push_back(copy);
                val_to_val[instruction_iter] = copy;

                ++instruction_iter;
            }

            ++basic_block_iter;
        }
        
        for(int i=0; i < new_bb.size() ; i++) // fix all operands
        {
            auto instruction_iter = new_bb.at(i)->begin();
            while(instruction_iter != new_bb.at(i)->end())
            {
                int operand_num = 0;
                auto operand_iter = instruction_iter->op_begin();
                while (operand_iter != instruction_iter->op_end())
                {
                    llvm::Value * val = operand_iter->get();

                    if(val_to_val.find(val) == val_to_val.end())
                    {
                        ++operand_iter;
                        operand_num++;
                        continue;
                    } 

                    instruction_iter->setOperand(operand_num,val_to_val[val]);

                    ++operand_iter;
                    operand_num++;
                }
                ++instruction_iter;
            }
        }

        std::vector<llvm::Instruction *> to_delete;  // replace return with store and jump
        for(int i=0; i < new_bb.size() ; i++)
        {
            auto instruction_iter = new_bb.at(i)->begin();
            while(instruction_iter != new_bb.at(i)->end())
            {
                if(llvm::ReturnInst * inst = llvm::dyn_cast<llvm::ReturnInst>(instruction_iter))
                {
                    if(inst->getReturnValue() == NULL)
                    {
                        llvm::BranchInst::Create(after_call_bb, inst);
                        to_delete.push_back(inst);
                    }
                    else
                    {
                        new llvm::StoreInst(inst->getReturnValue(), result, false, inst);
                        llvm::BranchInst::Create(after_call_bb, inst);
                        to_delete.push_back(inst);
                    }
                }
                ++instruction_iter;
            }
        }

        for(int i=0;i < to_delete.size(); i++)
        {
            to_delete.at(i)->eraseFromParent();
        }

        if(callee_func->getReturnType() != Compiler::t_void)
        {
            llvm::Value * v = new llvm::LoadInst(result, "", &after_call_bb->front());
            call_inst->replaceAllUsesWith (v);
        }

        call_inst->getParent()->getTerminator()->setSuccessor(0, first_bb);
        call_inst->eraseFromParent();
    }	
};