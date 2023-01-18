#pragma once

#include "Common/TerminalSymbols.h"
#include <string>

//<READ> -> READ (<IDLIST>);

bool executeRead(std::string& data)
{
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::READ))
	{
		throw std::runtime_error("Cannot find `READ` in read");
	}
	data.erase(0, terminal_symbols::READ.size());
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::OPENING_BRACE))
	{
		throw std::runtime_error("Cannot find opening brace in read");
	}
	data.erase(0, 1);

	auto const bracePos = data.find(terminal_symbols::CLOSING_BRACE);
	if (bracePos == std::string::npos)
	{
		throw std::runtime_error("Cannot find closing brace in read");
	}

	auto idList = data.substr(0, bracePos);
	if (!getHandler(non_terminal_symbols::IDLIST)(idList))
	{
		throw std::runtime_error("Id list is not correct in read");
	}
    data.erase(0, bracePos + 1);
	if (!data.starts_with(terminal_symbols::SEMICOLON))
	{
		throw std::runtime_error("Cannot find semicolon in read");
	}
    data.erase(0, terminal_symbols::SEMICOLON.size());
	removeBlanks(data);

	return data.empty();
}
