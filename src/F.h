#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool numOrId(std::string& data)
{
	std::string identifier;
	std::size_t i = 0;

	if (data.at(0) == '-')
	{
		data = data.substr(1);
	}

	while (i < data.length() && std::isalpha(data.at(i)))
	{
		identifier += data.at(i++);
	}

	if (identifier == "num" || identifier == "id")
	{
		data = data.substr(identifier.length());
		return true;
	}

	return false;
}

bool executeF(std::string& data)
{
	removeBlanks(data);

	if (data.at(0) == '(')
	{
		auto const expHandler = getHandler(non_terminal_symbols::EXP);

		data = data.substr(1);
		if (!expHandler(data))
		{
			return false;
		}

		if (!data.empty() && data.at(0) == ')')
		{
			data = data.substr(1);
			return true;
		}
		else
		{
			return false;
		}
	}

	return numOrId(data);
}
