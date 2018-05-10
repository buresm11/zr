#include <iostream>
#include <fstream>
#include <string>

#include "llvm.h"
#include "jit.h"
#include "CompileException.h"
#include "llvm.h"
#include "antlr4-runtime.h"
#include "zrLexer.h"
#include "zrParser.h"
#include "Compiler.h"

int main(int argc, char const * argv[])
{
	llvm::InitializeNativeTarget();
	llvm::InitializeNativeTargetAsmPrinter();
	llvm::InitializeNativeTargetAsmParser();
	
	bool optimalize = false;
	bool verbose = false;
	std::ifstream inputFile;

	if(argc == 4)
	{
		if (strncmp(argv[1], "-o", 2) == 0)
			optimalize = true;

		if (strncmp(argv[2], "-v", 2) == 0)
			verbose = true;

		inputFile=std::ifstream(argv[3]);
	}
	else
	{
		std::cout << "USAGE: [-o|-n] [-v|-s] filename" << std::endl;
		return -1;
	} 

	if (!inputFile.is_open())
	{
		std::cout << "file could not be opened" << std::endl;
		return -1;
	}

	antlr4::ANTLRInputStream input(inputFile);
	zrLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	tokens.fill();

	zrParser parser(&tokens);
	antlr4::tree::ParseTree *tree = parser.parse();

	inputFile.close();

	if(parser.getNumberOfSyntaxErrors() > 0)
	{	
		std::cout << "ERRORS" << std::endl << tree->toStringTree(&parser) << std::endl;
		return 1;
	}

	Compiler compiler;

	try
	{
		llvm::Module * m = compiler.compile(tree);
		llvm::Function *f = m->getFunction("main");

		if(f == NULL) 
			throw CompileException("Missing main function");

		if(verbose)
		{
			m->dump();
			std::cout << std::endl;
			std::cout << std::endl;
		}

		JIT::run(f, optimalize, verbose)();
	    
	}
	catch (std::exception & e)
	{
    	std::cerr << e.what() << std::endl;
    	return 1;
	}

	return 0;
}