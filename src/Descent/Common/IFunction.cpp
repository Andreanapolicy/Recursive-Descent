#include "./IFunction.h"
#include "../Assign.h"
#include "../Exp.h"
#include "../F.h"
#include "../Idlist.h"
#include "../Listst.h"
#include "../Prog.h"
#include "../Read.h"
#include "../St.h"
#include "../T.h"
#include "../Type.h"
#include "../Var.h"
#include "../Write.h"
#include "NonTerminalSymbols.h"
#include <map>

std::map<std::string, Handler> executableHandlers = {
	{ non_terminal_symbols::PROG, executeProg },
	{ non_terminal_symbols::VAR, executeVar },
	{ non_terminal_symbols::LISTST, executeListst },
	{ non_terminal_symbols::TYPE, executeType },
	{ non_terminal_symbols::IDLIST, executeIdlist },
	{ non_terminal_symbols::WRITE, executeWrite },
	{ non_terminal_symbols::READ, executeRead },
	{ non_terminal_symbols::ASSIGN, executeAssign },
	{ non_terminal_symbols::EXP, executeExp },
	{ non_terminal_symbols::ST, executeSt },
	{ non_terminal_symbols::T, executeT },
	{ non_terminal_symbols::F, executeF }
};

Handler getHandler(std::string const& symbols)
{
	auto it = executableHandlers.find(symbols);
	if (it == executableHandlers.end())
	{
		throw std::runtime_error("Cannot define handler for this symbol");
	}

	return it->second;
};
