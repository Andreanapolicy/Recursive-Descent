#pragma once
#include "Exp.h"

bool executeF(std::string& data)
{
	auto const minusPos = data.find(terminal_symbols::MINUS);
	if (minusPos != std::string::npos)
	{
		auto fPart = data.substr(minusPos);
		return executeF(fPart);
	}

	auto const openingBracePos = data.find(terminal_symbols::OPENING_BRACE);
	auto const closingBracePos = data.find_last_of(terminal_symbols::CLOSING_BRACE);
	if (openingBracePos != std::string::npos && closingBracePos != std::string::npos)
	{
		auto expPart = data.substr(openingBracePos, closingBracePos - openingBracePos);
		return executeExp(expPart);
	}

	return executeId(data) || executeNum(data);
}
