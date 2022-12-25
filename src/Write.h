#pragma once
#include "Common/TerminalSymbols.h"
#include <string>

//<WRITE> -> WRITE (<IDLIST>);

bool executeWrite(std::string& data)
{
	removeBlanks(data);

	if (data.starts_with(terminal_symbols::WRITE))
	{

	}

	return true;
}
