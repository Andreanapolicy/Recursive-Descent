#pragma
#include <string>
#include <functional>
#include <map>

using Handler = std::function<bool(std::string&)>;

std::map<std::string, Handler> executableHandlers = {

};