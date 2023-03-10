#pragma once
#include "Utils.h"
#include <algorithm>
#include <cctype>
#include <string>

namespace terminal_symbols
{
const std::string PROG = "PROG";
const std::string ID = "id";
const std::string BEGIN = "BEGIN";
const std::string END = "END";
const std::string VAR = "VAR";
const std::string INT = "int";
const std::string FLOAT = "float";
const std::string BOOL = "bool";
const std::string STRING = "string";
const std::string COLON = ":";
const std::string SEMICOLON = ";";
const std::string ASSIGMENT = ":=";
const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char OPENING_BRACE = '(';
const char CLOSING_BRACE = ')';
const std::string WRITE = "WRITE";
const std::string READ = "READ";
const std::string COMMA = ",";
} // namespace terminal_symbols
