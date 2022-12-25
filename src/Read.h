#pragma once
#include "Common/TerminalSymbols.h"
#include <string>

//<READ> -> READ (<IDLIST>);

bool executeRead(std::string& data)
{
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::READ))
	{
		return false;
	}
	data.erase(0, terminal_symbols::READ.size());
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::OPENING_BRACE))
	{
		return false;
	}
	data.erase(0, terminal_symbols::OPENING_BRACE.size());

	auto const bracePos = data.find(terminal_symbols::CLOSING_BRACE);
	if (bracePos == std::string::npos)
	{
		return false;
	}

	auto idList = data.substr(0, bracePos);
	if (!getHandler(non_terminal_symbols::IDLIST)(idList))
	{
		return false;
	}

	if (!data.starts_with(terminal_symbols::SEMICOLON))
	{
		return false;
	}

	removeBlanks(data);

	return data.empty();
}
