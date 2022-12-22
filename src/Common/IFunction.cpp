#include "./IFunction.h"
#include "NonTerminalSymbols.h"
#include "../Var.h"
#include "../Prog.h"
#include "../Listst.h"
#include <map>

std::map<std::string, Handler> executableHandlers = {
        {non_terminal_symbols::VAR, executeVar},
        {non_terminal_symbols::PROG, executeProg},
        {non_terminal_symbols::LISTST, executeListst}
};

Handler getHandler(const std::string& symbols)
{
    auto it = executableHandlers.find(symbols);
    if (it == executableHandlers.end())
    {
        throw std::runtime_error("Cannot define handler for this symbol");
    }

    return it->second;
};
