#define CATCH_CONFIG_MAIN

#include "../src/Parser.h"
#include "catch.hpp"

TEST_CASE("valid end2end cases")
{
	std::string const testFile = GENERATE(
		"valid-example",
		"valid-string-type",
		"valid-exp-with-parentheses",
		"valid-exp-with-lot-of-brackets");

	std::ifstream input("files/" + testFile + ".txt");
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
	std::string const testFile = GENERATE(
		"invalid-prog",
		"invalid-empty-idlist",
		"invalid-wrong-id",
		"invalid-unbalanced-parentheses",
		"invalid-exp-two-signs",
		"invalid-no-semicolon",
		"invalid-exp-with-single-plus",
		"invalid-exp-two-same-brackets");

	std::ifstream input("files/" + testFile + ".txt");
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
