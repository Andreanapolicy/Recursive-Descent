#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeT(std::string& data)
{
	auto const pos = data.find(terminal_symbols::MULTIPLY);
	if (pos == std::string::npos)
	{
		return false;
	}

	auto newTPart = data.substr(0, pos);
	auto fPart = data.substr(pos);

	auto const fHandler = getHandler(non_terminal_symbols::F);

	return executeT(newTPart) && fHandler(fPart) || fHandler(data);
}
