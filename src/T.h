#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeT(std::string& data)
{
	removeBlanks(data);

	auto const fHandler = getHandler(non_terminal_symbols::F);
	if (!fHandler(data))
	{
		return false;
	}

	while (data.length() > 0)
	{
		if (data.at(0) != terminal_symbols::MULTIPLY)
		{
			break;
		}

		data = data.substr(1);
		if (!fHandler(data))
		{
			return false;
		}
	}

	return true;
}
