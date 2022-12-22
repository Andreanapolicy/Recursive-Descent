#pragma
#include <string>
#include <functional>

using Handler = std::function<bool(std::string&)>;

[[nodiscard]] Handler getHandler(const std::string& symbols);