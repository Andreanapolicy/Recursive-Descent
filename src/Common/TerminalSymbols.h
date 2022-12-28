#pragma once
#include <algorithm>
#include <cctype>
#include <string>
#include "Utils.h"

namespace terminal_symbols
{
const std::string PROG = "PROG";
const std::string ID = "id";
const std::string BEGIN = "begin";
const std::string END = "end";
const std::string VAR = "VAR";
const std::string INT = "int";
const std::string FLOAT = "float";
const std::string BOOL = "bool";
const std::string STRING = "string";
const std::string COLON = ":";
const std::string SEMICOLON = ";";
const std::string ASSIGMENT = ":=";
const std::string PLUS = "+";
const std::string MINUS = "-";
const std::string MULTIPLY = "*";
const std::string OPENING_BRACE = "(";
const std::string CLOSING_BRACE = ")";
const std::string WRITE = "WRITE";
const std::string READ = "READ";
const std::string COMMA = ",";
} // namespace terminal_symbols

bool executeId(const std::string& data)
{
	if (data.length() == 0)
	{
		return false;
	}

	if (!std::isalpha(data[0]))
	{
		return false;
	}

	return isAlphaNumeric(data);
}

bool executeNum(const std::string& data)
{
	try
	{
		std::stoi(data);
		return true;
	}
	catch (...)
	{
		return false;
	}
}
