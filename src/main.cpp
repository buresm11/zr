#include <iostream>
#include <fstream>
#include <string>

#include "llvm.h"
#include "antlr4-runtime.h"
#include "zrLexer.h"
#include "zrParser.h"
#include "Visitor.h"

int main(int argc, char const * argv[])
{
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
		std::cout << "ERRORS" << tree->toStringTree(&parser) << std::endl;
	}

	Visitor visitor;

	llvm::Module * m = visitor.compile(tree);

	std::error_code error;
    llvm::raw_fd_ostream o("text", error, llvm::sys::fs::OpenFlags::F_None);
    llvm::WriteBitcodeToFile(m, o);

    m->dump();

	return 1;
}
