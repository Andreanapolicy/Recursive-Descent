#pragma once
#include "./Common/IFunction.h"
#include "./Common/TerminalSymbols.h"
#include "./Common/NonTerminalSymbols.h"
#include <string>

// int|float|bool|string

bool executeType(std::string& data)
{
    if (data.starts_with(terminal_symbols::INT))
	{
		data.erase(0, terminal_symbols::INT.size());
		return true;
	}

	if (data.starts_with(terminal_symbols::FLOAT))
	{
		data.erase(0, terminal_symbols::FLOAT.size());
		return true;
	}

	if (data.starts_with(terminal_symbols::BOOL))
	{
		data.erase(0, terminal_symbols::BOOL.size());
		return true;
	}

	if (data.starts_with(terminal_symbols::STRING))
	{
		data.erase(0, terminal_symbols::STRING.size());
		return true;
	}

	return false;
}