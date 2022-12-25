#pragma once
#include "Common/TerminalSymbols.h"
#include <string>

//<WRITE> -> WRITE (<IDLIST>);

bool executeWrite(std::string& data)
{
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::WRITE))
	{
		return false;
	}
	data.erase(0, terminal_symbols::WRITE.size());
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::OPENING_BRACE))
	{
		return false;
	}
	data.erase(0, terminal_symbols::OPENING_BRACE.size());

	auto const pos = data.find(terminal_symbols::CLOSING_BRACE);
	if (pos == std::string::npos || !data.ends_with(terminal_symbols::SEMICOLON))
	{
		return false;
	}

	return true;
}
