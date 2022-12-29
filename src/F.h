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

	auto const openingBracePos = data.find(terminal_symbols::OPENING_BRACE);
	auto const closingBracePos = data.find_last_of(terminal_symbols::CLOSING_BRACE);
	if (openingBracePos != std::string::npos && closingBracePos != std::string::npos)
	{
		auto expPart = data.substr(openingBracePos + 1, closingBracePos - openingBracePos - 1);
		data.clear();
		auto const expHandler = getHandler(non_terminal_symbols::EXP);
		return expHandler(expPart);
	}

	return data == "num" || data == "id";
}
