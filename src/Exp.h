#pragma once
#include "Common/TerminalSymbols.h"
#include "T.h"

bool executeExp(std::string& data)
{
	auto const pos = data.find(terminal_symbols::PLUS);
	if (pos == std::string::npos)
	{
		return false;
	}

	auto newExpPart = data.substr(0, pos);
	auto tPart = data.substr(pos);

	return executeExp(newExpPart) && executeT(tPart);
}
