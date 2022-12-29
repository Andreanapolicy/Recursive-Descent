#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeT(std::string& data)
{
	auto const pos = data.find(terminal_symbols::MULTIPLY);
	auto const fHandler = getHandler(non_terminal_symbols::F);
	if (pos == std::string::npos)
	{
		return fHandler(data);
	}

	auto newTPart = data.substr(0, pos);
	auto fPart = data.substr(pos + 1);
	auto dataCopy = data;
	data.clear();

	return executeT(newTPart) && fHandler(fPart) || fHandler(dataCopy);
}
