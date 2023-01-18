#include "Parser.h"
#include "Descent/Common/IFunction.h"
#include "Descent/Common/NonTerminalSymbols.h"

void Parser::Parse(std::string& data)
{
	auto const handler = getHandler(non_terminal_symbols::PROG);
	if (!handler(data))
	{
		throw std::runtime_error("Program is not correct");
	}
}
