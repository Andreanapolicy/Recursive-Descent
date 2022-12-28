#pragma once
#include "./Common/IFunction.h"
#include "./Common/TerminalSymbols.h"
#include "./Common/NonTerminalSymbols.h"

bool executeIdlist(std::string& data)
{
    removeBlanks(data);
    if (data.starts_with(terminal_symbols::ID))
    {
        // id ...
        data.erase(0, terminal_symbols::ID.size());
        removeBlanks(data);
        // , ...
        if (data.starts_with(terminal_symbols::COMMA))
        {
            data.erase(0, terminal_symbols::COMMA.size());
            auto result = executeIdlist(data);
            if (!result)
            {
                return result;
            }
        }
        return true;
    }
    return false;
}