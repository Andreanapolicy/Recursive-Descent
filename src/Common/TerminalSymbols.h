#pragma once
#include <string>

namespace terminal_symbols
{
const std::string ID = "id";
const std::string BEGIN = "begin";
const std::string END = "end";
const std::string INT = "int";
const std::string FLOAT = "float";
const std::string BOOL = "bool";
const std::string STRING = "string";
const std::string ASSIGMENT = ":=";
const std::string PLUS = "+";
const std::string MINUS = "-";
const std::string MULTIPLY = "*";
}

bool executeId(std::string& data)
{
	return true;
}

bool executeNum(std::string& data)
{
	return true;
}
