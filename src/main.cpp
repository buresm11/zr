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

	std::ifstream inputFile (argv[1]);

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

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "------NONOPTIMALIZED-----" << std::endl;
		m->dump();
		std::cout << "------NONOPTIMALIZED-----" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "------RUN-----" << std::endl;
		JIT::run(f)();
		std::cout << "------RUN-----" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	    
	}
	catch (std::exception & e)
	{
    	std::cerr << e.what() << std::endl;
    	return 1;
	}

	return 0;
}
