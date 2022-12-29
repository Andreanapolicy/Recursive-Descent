#pragma once
#include "Common/TerminalSymbols.h"
#include <string>

//<WRITE> -> WRITE (<IDLIST>);

bool executeWrite(std::string& data)
{
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::WRITE))
	{
		throw std::runtime_error("Cannot find `WRITE` in write");
	}
	data.erase(0, terminal_symbols::WRITE.size());
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::OPENING_BRACE))
	{
		throw std::runtime_error("Cannot find opening brace in write");
	}
	data.erase(0, terminal_symbols::OPENING_BRACE.size());

	auto const bracePos = data.find(terminal_symbols::CLOSING_BRACE);
	if (bracePos == std::string::npos)
	{
		throw std::runtime_error("Cannot find closing brace in write");
	}

	auto idList = data.substr(0, bracePos);
	if (!getHandler(non_terminal_symbols::IDLIST)(idList))
	{
		throw std::runtime_error("Id list is not correct in write");
	}
    data.erase(0, bracePos + 1);
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::SEMICOLON))
	{
		throw std::runtime_error("Cannot find semicolon in write");
	}
    data.erase(0, terminal_symbols::SEMICOLON.size());
	removeBlanks(data);

	return data.empty();
}
