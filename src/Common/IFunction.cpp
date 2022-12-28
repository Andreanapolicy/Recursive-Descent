#include "./IFunction.h"
#include "NonTerminalSymbols.h"
#include "../Var.h"
#include "../Prog.h"
#include "../Listst.h"
#include "../Type.h"
#include "../Idlist.h"
#include "../Write.h"
#include "../Read.h"
#include "../Assign.h"
#include "../Exp.h"
#include "../St.h"
#include "../T.h"
#include "../F.h"
#include <map>

std::map<std::string, Handler> executableHandlers = {
		{non_terminal_symbols::PROG, executeProg},
        {non_terminal_symbols::VAR, executeVar},
        {non_terminal_symbols::LISTST, executeListst},
		{non_terminal_symbols::TYPE, executeType},
		{non_terminal_symbols::IDLIST, executeIdlist},
		{non_terminal_symbols::WRITE, executeWrite},
		{non_terminal_symbols::READ, executeRead},
		{non_terminal_symbols::ASSIGN, executeAssign},
		{non_terminal_symbols::EXP, executeExp},
		{non_terminal_symbols::ST, executeSt},
		{non_terminal_symbols::T, executeT},
		{non_terminal_symbols::F, executeF}
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
