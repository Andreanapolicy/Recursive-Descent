#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeListst(std::string& data)
{
	removeBlanks(data);
	if (data.starts_with(terminal_symbols::END))
    {
        return true;
    }
    auto semicolonPos = data.find(terminal_symbols::SEMICOLON);
    if (semicolonPos != std::string::npos)
    {
        auto st = data.substr(0, semicolonPos + 1);
        data.erase(0, st.size());
        removeBlanks(data);
        if (getHandler(non_terminal_symbols::ST)(st))
        {
            if (!executeListst(data))
            {
                return false;
            }
            return true;
        }
    }
    return false;
}
