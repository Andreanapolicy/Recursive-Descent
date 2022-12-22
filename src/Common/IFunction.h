#pragma
#include <string>
#include <functional>
#include <map>
#include "NonTerminalSymbols.h"
#include "../Var.h"

using Handler = std::function<bool(std::string&)>;

std::map<std::string, Handler> executableHandlers = {
        {non_terminal_symbols::VAR, executeVar}
};

//Example
//bool test()
//{
//    std::string test = "adssa";
//    executableHandlers.find(non_terminal_symbols::VAR)->second(test);
//}
