#include "src/Common/Args.h"
#include "src/Parser.h"
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);
		std::ifstream input(args.inputFilename);

		if (!input.is_open())
		{
			throw std::runtime_error("Cannot open input file");
		}
		std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

		Parser::Parse(data);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
