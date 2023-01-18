#pragma once

#include "Common/TerminalSymbols.h"
#include "Exp.h"
#include <string>

bool executeAssign(std::string& data)
{
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::ID))
	{
		throw std::runtime_error("Cannot find `id` in assign");
	}
	data.erase(0, terminal_symbols::ID.size());
	removeBlanks(data);

	if (!data.starts_with(terminal_symbols::ASSIGMENT))
	{
		throw std::runtime_error("Cannot find assignment symbol in assign");
	}
	data.erase(0, terminal_symbols::ASSIGMENT.size());
	removeBlanks(data);

	auto const semicolonPos = data.find(terminal_symbols::SEMICOLON);
	if (semicolonPos == std::string::npos)
	{
		throw std::runtime_error("Cannot find semicolon in assign");
	}

	auto exp = data.substr(0, semicolonPos);
	if (!getHandler(non_terminal_symbols::EXP)(exp))
	{
		throw std::runtime_error("Exp is not correct");
	}
	data.erase(0, semicolonPos + 1);
	removeBlanks(data);

	return data.empty();
}
