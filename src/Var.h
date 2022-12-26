#pragma once
#include "./Common/IFunction.h"
#include "./Common/TerminalSymbols.h"
#include "./Common/NonTerminalSymbols.h"

//<VAR>->VAR <IDLIST> : <TYPE>;

bool executeVar(std::string& data)
{
	if (data.starts_with(terminal_symbols::VAR))
	{
		// "VAR "
		data.erase(0, terminal_symbols::VAR.size() + 1);
		if (getHandler(non_terminal_symbols::IDLIST)(data))
		{
			if (data.starts_with(terminal_symbols::COLON))
			{
				// ": "
				data.erase(0, terminal_symbols::COLON.size() + 1);
				if (getHandler(non_terminal_symbols::TYPE)(data))
				{
					if (data.starts_with(terminal_symbols::SEMICOLON))
					{
						// "; "
						data.erase(0, terminal_symbols::SEMICOLON.size() + 1);
						return true;
					}
				}
			}
		}
	}

	return false;
}