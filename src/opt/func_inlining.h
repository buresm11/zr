
#pragma once

#include <iostream>

#include "llvm.h"
#include "Compiler.h"

class Vertex
{

public:
	std::string name; // debug only

    llvm::Function * function;
    bool main;
	int loc;
	int call_inst;
	int branches_inst;
	int recursive_inst;
	
	std::map<Vertex *, int> incoming;
	std::map<Vertex *, int> outgoing;
    std::map<Vertex *, int> calls;


	Vertex(std::string name, llvm::Function * func) : name(name), function(func)
	{
		loc = 0;
		call_inst = 0;
		branches_inst = 0;
		recursive_inst = 0;
	}

	void print()
	{
        std::cout << std::endl;
        std::cout << "***************" << std::endl;
		std::cout << name <<  "  LOC:" << loc << "  Branched: " << branches_inst << " rec:  " << recursive_inst << "   call: " << call_inst << std::endl;

		std::cout << std::endl;
		std::cout << "incoming::" << std::endl;

		std::map<Vertex *, int>::iterator it;
		for (it = incoming.begin(); it != incoming.end(); it++)
		{
			std::cout << it->first->name << "  " << it->second << std::endl;
		}

		std::cout << std::endl;

		std::cout << "outgoing::" << outgoing_size() << std::endl;

		std::map<Vertex *, int>::iterator itx;
		for (itx = outgoing.begin(); itx != outgoing.end(); itx++)
		{
			std::cout << itx->first->name << "  " << itx->second << std::endl;
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
};

class func_inliningT
{
	bool changed;
	llvm::Module * module;

	std::vector<Vertex *> graph;
    std::map<llvm::Function *, Vertex *> vertexes;  
    std::vector<llvm::Function *> inline_order;

	int lines_of_code;

public:
	func_inliningT()
	{
		lines_of_code = 0;
	}

	bool inline_F(llvm::Module * m)
	{
		module = m;
		
		auto function_iter = module->begin();
    	while(function_iter != module->end())
    	{
    		if(function_iter->getName().lower() == "print_" ||
    		   function_iter->getName().lower() == "scan_" ||
    		   function_iter->getName().lower() == "printb_" ||
               function_iter->getName().lower() == "main") //TODO case sensitive
    		{
    			++function_iter;
    			continue;
    		}

    		Vertex * v = new Vertex(function_iter->getName().lower(), function_iter);
            graph.push_back(v);
    		vertexes[function_iter] = v;

    		++function_iter;
    	}

    	analysis();

    	std::map<llvm::Function *, Vertex *>::iterator itx;
		for (itx = vertexes.begin(); itx != vertexes.end(); itx++)
		{
			itx->second->print();
		}

		linear();

		for(int i=0;i<inline_order.size();i++)
        {
            std::cout << "ORDER::" << inline_order.at(i)->getName().lower() << ", ";
        }
        std::cout << std::endl;

        inline_functions();

    }

    void inline_functions()
    {
        std::vector<llvm::Function *>::iterator it = inline_order.begin();
        while (it != inline_order.end()) // ignore recursive function
        {
            inline_function(*it);

            ++it;
        }
    }

    void inline_function(llvm::Function * function)
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

                        if(called_func == function)
                        {
                            replace_call(function_iter,inst,function);
                            return;
                        }
                    }
                    ++instruction_iter;
                }
                ++basic_block_iter;
            }
            ++function_iter;
        }
    }

    bool replace_call(llvm::Function * caller_func, llvm::CallInst * call_inst, llvm::Function * callee_func)
    {
        std::cout << "TTT:::" << std::endl;

        std::map<llvm::Value *, llvm::Value *> val_to_val;
        std::vector<llvm::BasicBlock *> new_bb;
            
        int bb_first = true;

        auto basic_block_iter = callee_func->begin(); 
        while(basic_block_iter != callee_func->end())
        {
            llvm::BasicBlock * bb = llvm::BasicBlock::Create(Compiler::llvm_context, "copied", caller_func);
            new_bb.push_back(bb);
            val_to_val[basic_block_iter] = bb; 

            auto instruction_iter = basic_block_iter->begin();
            if(bb_first) //func header
            {
                int args_size = callee_func->arg_size();
                
                for(int i=0;i < args_size * 2; i++)
                {
                    if(i % 2 == 0)
                    {
                        llvm::Instruction * copy = instruction_iter->clone();
                        bb->getInstList().push_back(copy);
                        val_to_val[instruction_iter] = copy;
                    }
                    else
                    {
                        llvm::StoreInst * si = new llvm::StoreInst(call_inst->getArgOperand(i/2), args.at(i), false, prev);
                    } 

                    ++instruction_iter;
                }
            }

            /*while(instruction_iter != basic_block_iter->end())
            {
                llvm::Instruction * copy = instruction_iter->clone();
                bb->getInstList().push_back(copy);
                val_to_val[instruction_iter] = copy;

                ++instruction_iter;
            }*/

            ++basic_block_iter;
            bb_first = false;
        }
        
       /* for(int i=0; i < new_bb.size() ; i++)
        {
            std::cout << "coolSS:" << new_bb.size() << std::endl;

            auto instruction_iter = new_bb.at(i)->begin();
            while(instruction_iter != new_bb.at(i)->end())
            {
                auto operand_iter = instruction_iter->op_begin();
                while (operand_iter != instruction_iter->op_end())
                {
                    llvm::Value * val = operand_iter->get();
                    
                    if(val_to_val.find(val) == val_to_val.end())
                    {
                        ++operand_iter;
                        continue;
                    } 
                    *operand_iter = val_to_val[val];

                    ++operand_iter;
                }
                ++instruction_iter;
            }
        }*/

        return false;
    }

    void linear()
    {
    	std::vector<Vertex *>::iterator it = graph.begin();
		while (it != graph.end()) // ignore recursive function
		{
            Vertex * vertex = (*it);

			if((*it)->recursive_inst > 0)
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

            //DEBUG
            for (it = graph.begin(); it != graph.end(); it++)
            {
                (*it)->print();
            }
		}
    }

    bool cut_off_vertex_edges()
    {
        std::cout << "edges" << std::endl;

        std::vector<Vertex *>::iterator it = graph.begin();

        Vertex * vertex_to_cut = (*it);
        int lines_of_code = vertex_to_cut->loc;

        ++it;

        while (it != graph.end()) // ignore recursive function
        {
            if(inline_vertex(*it) && (*it)->loc < vertex_to_cut->loc)
            {
                vertex_to_cut = (*it);
            }
            ++it;
        }

        inline_order.push_back(vertex_to_cut->function);

        vertex_to_cut->remove();

        graph.erase( std::remove( graph.begin(), graph.end(), vertex_to_cut ), graph.end());

        return true; 
    }

    bool cut_off_vertex_no_edges()
    {
        std::cout << "no edges" << std::endl;

    	std::vector<Vertex *>::iterator it = graph.begin();
        while (it != graph.end()) // ignore recursive function
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
    	return true;
    }

	void analysis()
	{
    	auto function_iter = module->begin();
    	while(function_iter != module->end())
    	{
    		llvm::Function * func = &(*function_iter);;

    		if(vertexes.find(func) == vertexes.end()) // runtime functions
    		{
    			++function_iter;
    			continue;
    		}

    		analysis_function(func);
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
    					{
    						recursive_inst++;
    					}
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
        		{
        			branches_inst++;
        		}

        		loc++;
    			++instruction_iter;
    		}
    		++basic_block_iter;
    	}

		vertex_F->loc = loc;
		vertex_F->call_inst = call_inst;
		vertex_F->branches_inst = branches_inst;
		vertex_F->recursive_inst = recursive_inst;
    	lines_of_code += loc;
	}
};


/*
class func_inlining_analysis : public llvm::FunctionPass
{
	std::map<llvm::Function *, bool> cool_to_inline;
	std::map<llvm::Function *, int> function_called;
	int instruction_count;
	int branch_instruction_count;

public:
	static char ID;

	func_inlining_analysis() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "FunctionCallInlineAnalysis";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const
    {
    	//Info.addRequired<tail_call_analysis>();
    }

    bool is_function_cool_to_inline(llvm::Function * function)
    {
    	return cool_to_inline.find(function) != cool_to_inline.end();
    }

	bool runOnFunction(llvm::Function & F)
    {
    	std::cout << F.getName().lower() << "analysis" << std::endl;
    	return false;

    	for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	instruction_count++;

            	if(llvm::BranchInst * inst = llvm::dyn_cast<llvm::BranchInst>(i))
        		{
        			branch_instruction_count++;
        		}

        		++i;
            }
        }

        cool_to_inline[&F] = true;

        return false;
    }
};

class func_inlining : public llvm::FunctionPass
{

public:
	static char ID;

	func_inlining() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "FunctionCallInline";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const override
    {
    	Info.addRequired<func_inlining_analysis>();
    }

	bool runOnFunction(llvm::Function & F) override
    {
    	std::cout << F.getName().lower() << "run" << std::endl;
    	return false;

    	bool changed = false;

    	func_inlining_analysis & a = getAnalysis<func_inlining_analysis>();

    	if(!a.is_function_cool_to_inline(&F)) return false;

    	llvm::Module * module = F.getParent();

    	auto function_iter = module->begin();
    	while(function_iter != module->end())
    	{
    		llvm::Function * f = function_iter;
    		if(f == &F)
    		{
    			++function_iter;
    			continue;
    		}

    		auto basic_block_iter = function_iter->begin();

    		while(basic_block_iter != function_iter->end())
    		{
    			auto instruction_iter = basic_block_iter->begin();
    			while(instruction_iter != basic_block_iter->end())
    			{
    				std::cout << "i" << std::endl;
    				if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
        			{
        				std::cout << "ckonej" << std::endl;

        				 llvm::Function * called_func = inst->getCalledFunction();

        				 if(called_func != &F)
        				 {
        				 	++instruction_iter; continue;
        				 }

        				 std::cout << "konej" << std::endl;

        				 changed =  replace_call(function_iter, inst, called_func);
        			}
    				++instruction_iter;
    			}
    			++basic_block_iter;
    		}
    		++function_iter;
    	}

    	return changed;
    }

    
};
*/