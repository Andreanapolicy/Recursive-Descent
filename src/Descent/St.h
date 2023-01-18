#pragma once

#include "Common/IFunction.h"
#include "Common/NonTerminalSymbols.h"
#include "Common/TerminalSymbols.h"

bool executeSt(std::string& data)
{
	removeBlanks(data);
	if (data.starts_with(non_terminal_symbols::READ))
    {
        return getHandler(non_terminal_symbols::READ)(data);
    }
	removeBlanks(data);
	if (data.starts_with(non_terminal_symbols::WRITE))
    {
        return getHandler(non_terminal_symbols::WRITE)(data);
    }
	removeBlanks(data);
	if (data.find(terminal_symbols::ASSIGMENT) != std::string::npos)
    {
        return getHandler(non_terminal_symbols::ASSIGN)(data);
    }
    return false;
}
