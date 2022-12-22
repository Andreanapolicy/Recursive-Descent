#pragma once
#include "./Common/IFunction.h"
#include "./Common/TerminalSymbols.h"
#include "./Common/NonTerminalSymbols.h"
#include <iostream>

// <PROG>->PROG id <VAR> begin <LISTST> end

bool executeProg(std::string& data)
{
    if (executableHandlers.find(non_terminal_symbols::VAR)->second(data))
    {
        if (data.starts_with(terminal_symbols::BEGIN))
        {
            data.erase(0, terminal_symbols::BEGIN.size() + 1);
            if (executableHandlers.find(non_terminal_symbols::LISTST)->second(data))
            {
                if (data.starts_with(terminal_symbols::END))
                {
                    data.erase(0, terminal_symbols::END.size());
                    return data.empty();
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}