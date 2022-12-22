#pragma
#include <string>
#include <functional>
#include <map>
#include "NonTerminalSymbols.h"
#include "../Var.h"
#include "../Prog.h"
#include "../Listst.h"

using Handler = std::function<bool(std::string&)>;

bool executeVar(std::string& data);
bool executeProg(std::string& data);
bool executeListst(std::string& data);

std::map<std::string, Handler> executableHandlers = {
        {non_terminal_symbols::VAR, executeVar},
        {non_terminal_symbols::PROG, executeProg},
        {non_terminal_symbols::LISTST, executeListst}
};

//Example
//bool test()
//{
//    std::string test = "adssa";
//    executableHandlers.find(non_terminal_symbols::VAR)->second(test);
//}
