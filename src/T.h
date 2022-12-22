#pragma once
#include "Common/TerminalSymbols.h"
#include "F.h"

bool executeT(std::string& data)
{
	auto const pos = data.find(terminal_symbols::MULTIPLY);
	if (pos == std::string::npos)
	{
		return false;
	}

	auto newTPart = data.substr(0, pos);
	auto fPart = data.substr(pos);

	return executeT(newTPart) && executeF(fPart) || executeF(data);
}
