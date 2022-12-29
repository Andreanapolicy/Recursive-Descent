#pragma once
#include "./Common/IFunction.h"
#include "./Common/TerminalSymbols.h"
#include "./Common/NonTerminalSymbols.h"

// <PROG>->PROG id <VAR> begin <LISTST> end

bool executeProg(std::string& data)
{
	if (data.starts_with(terminal_symbols::PROG))
	{
		// "PROG id "
		data.erase(0, terminal_symbols::PROG.size() + 1 + terminal_symbols::ID.size() + 1);

		if (getHandler(non_terminal_symbols::VAR)(data))
		{
			removeBlanks(data);

			if (data.starts_with(terminal_symbols::BEGIN))
			{
				// "begin "
				data.erase(0, terminal_symbols::BEGIN.size() + 1);
				if (getHandler(non_terminal_symbols::LISTST)(data))
				{
					removeBlanks(data);

					if (data.starts_with(terminal_symbols::END))
					{
						// "end "
						data.erase(0, terminal_symbols::END.size());
						return data.empty();
					}
				}
			}
		}
	}

    return false;
}