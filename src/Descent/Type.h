#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"
#include <string>

// int|float|bool|string

bool executeType(std::string& data)
{
	removeBlanks(data);
	if (data.starts_with(terminal_symbols::INT))
	{
		// "int"
		data.erase(0, terminal_symbols::INT.size());
		return true;
	}
	removeBlanks(data);

	if (data.starts_with(terminal_symbols::FLOAT))
	{
		// "float"
		data.erase(0, terminal_symbols::FLOAT.size());
		return true;
	}
	removeBlanks(data);

	if (data.starts_with(terminal_symbols::BOOL))
	{
		// "bool"
		data.erase(0, terminal_symbols::BOOL.size());
		return true;
	}
	removeBlanks(data);

	if (data.starts_with(terminal_symbols::STRING))
	{
		// "string"
		data.erase(0, terminal_symbols::STRING.size());
		return true;
	}

	return false;
}
