#pragma once
#include <string>

bool isAlphaNumeric(std::string& data)
{
	auto result = std::find_if(
					  data.begin(),
					  data.end(),
					  [](char c) { return !(std::isalpha(c) || std::isdigit(c) || (c == ' ')); })
		== data.end();
	data.clear();

	return result;
}

bool isSpace(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\x0b';
}

void removeBlanks(std::string& data)
{
	auto index = 0;
	for (; index < data.size(); index++)
	{
		if (!isSpace(data[index]))
		{
			break;
		}
	}
	data.erase(0, index);
}
