#pragma once
#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeF(std::string& data)
{
	removeBlanks(data);

	if (data.starts_with(terminal_symbols::MINUS))
	{
		auto fPart = data.substr(1);
		data.clear();
		return executeF(fPart);
	}

	auto const closingBracePos = data.find_last_of(terminal_symbols::CLOSING_BRACE);
	if (data.starts_with(terminal_symbols::OPENING_BRACE) && closingBracePos != std::string::npos)
	{
		auto expPart = data.substr(1, closingBracePos - 1);
		data.clear();
		auto const expHandler = getHandler(non_terminal_symbols::EXP);
		return expHandler(expPart);
	}

	return data == "num" || data == "id";
}
