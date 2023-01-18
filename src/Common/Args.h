#pragma once

#include <string>

struct Args
{
	std::string inputFilename;
};

Args ParseArgs(int argc, char** argv);
