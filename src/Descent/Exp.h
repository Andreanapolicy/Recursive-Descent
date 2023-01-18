#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeExp(std::string& data)
{
	removeBlanks(data);

	auto const tHandler = getHandler(non_terminal_symbols::T);
	if (!tHandler(data))
	{
		return false;
	}

	while (data.length() > 0)
	{
		if (data.at(0) != terminal_symbols::PLUS)
		{
			break;
		}

		data = data.substr(1);
		if (!tHandler(data))
		{
			return false;
		}
	}

	return true;
}
