#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeExp(std::string& data)
{
	removeBlanks(data);

	auto const plusPos = data.find(terminal_symbols::PLUS);
	auto const multiplyPos = data.find(terminal_symbols::MULTIPLY);

	auto const tHandler = getHandler(non_terminal_symbols::T);
	if (plusPos == std::string::npos || multiplyPos < plusPos)
	{
		return tHandler(data);
	}

	auto newExpPart = data.substr(0, plusPos);
	auto tPart = data.substr(plusPos + 1);
	auto dataCopy = data;
	data.clear();

	return executeExp(newExpPart) && tHandler(tPart) || tHandler(dataCopy);
}
