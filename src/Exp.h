#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeExp(std::string& data)
{
	auto const pos = data.find(terminal_symbols::PLUS);
	if (pos == std::string::npos)
	{
		return false;
	}

	auto newExpPart = data.substr(0, pos);
	auto tPart = data.substr(pos);

	auto const tHandler = getHandler(non_terminal_symbols::T);

	return executeExp(newExpPart) && tHandler(tPart) || tHandler(data);
}
