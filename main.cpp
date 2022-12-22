#include <iostream>

struct Args
{
	std::string inputFilename;
};

Args ParseArgs(int argc, char** argv);

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);
		// TODO: add entry point to functions
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

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
