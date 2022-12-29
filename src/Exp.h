#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeExp(std::string& data)
{
	auto const pos = data.find(terminal_symbols::PLUS);
	auto const tHandler = getHandler(non_terminal_symbols::T);
	if (pos == std::string::npos)
	{
		return tHandler(data);
	}

	auto newExpPart = data.substr(0, pos);
	auto tPart = data.substr(pos + 1);
	auto dataCopy = data;
	data.clear();

	return executeExp(newExpPart) && tHandler(tPart) || tHandler(dataCopy);
}
