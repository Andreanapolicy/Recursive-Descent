#include "src/Common/IFunction.h"
#include "src/Common/NonTerminalSymbols.h"
#include <fstream>
#include <iostream>

struct Args
{
	std::string inputFilename;
};

namespace
{
Args ParseArgs(int argc, char** argv)
{
	if (argc != 2)
	{
		throw std::invalid_argument("invalid parameters");
	}

	return {
		.inputFilename = argv[1]
	};
}

bool execute(std::string& data)
{
	if (data.starts_with(non_terminal_symbols::PROG))
	{
		getHandler(non_terminal_symbols::PROG)(data);
	}
	return false;
}
} // namespace

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);
		std::ifstream input(args.inputFilename);

		/*
		 * ♥♥♥
		 * СЛОВНО ХУЙ ДРОЧЕНЫЙ В ЖОПУ ПИДОРА!!!
		 * НА ПАРСЕР ЗАДАНИЕ ДАЛИ!!!
		 * НЕ ОСТАВИВ СТУДЕНТАМ НИ ВЫБОРА!!!
		 * И ВСЕ КОСТЫЛЕЙ НАКИДАЛИ!!!
		 * ♥♥♥
		 */

		if (!input.is_open())
		{
			throw std::runtime_error("Cannot open input file");
		}
		std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
		if (!execute(data))
		{
			throw std::runtime_error("Program is not correct");
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
