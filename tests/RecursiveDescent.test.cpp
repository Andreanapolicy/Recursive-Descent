#define CATCH_CONFIG_MAIN

#include "../src/Parser.h"
#include "catch.hpp"

TEST_CASE("valid end2end cases")
{
	std::string const testFile = GENERATE("default");

	std::ifstream input("files/" + testFile + ".pas");
	std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

	WHEN("parsing a file")
	{
		THEN("it passes")
		{
			REQUIRE_NOTHROW(Parser::Parse(data));
		}
	}
}

TEST_CASE("invalid end2end cases")
{
	std::string const testFile = GENERATE("invalid-prog");

	std::ifstream input("files/" + testFile + ".pas");
	std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

	std::stringstream output;

	WHEN("parsing a file")
	{
		THEN("it throws an exception")
		{
			REQUIRE_THROWS(Parser::Parse(data));
		}
	}
}
