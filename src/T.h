#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeT(std::string& data)
{
	removeBlanks(data);

	auto const plusPos = data.find(terminal_symbols::PLUS);
	auto const multiplyPos = data.find(terminal_symbols::MULTIPLY);

	auto const fHandler = getHandler(non_terminal_symbols::F);
	if (multiplyPos == std::string::npos || multiplyPos > plusPos)
	{
		return fHandler(data);
	}

	auto newTPart = data.substr(0, multiplyPos);
	auto fPart = data.substr(multiplyPos + 1);
	auto dataCopy = data;
	data.clear();

	return executeT(newTPart) && fHandler(fPart) || fHandler(dataCopy);
}
