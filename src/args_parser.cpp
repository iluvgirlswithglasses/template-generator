
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 12:54:50 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include "args_parser.h"
#include <iostream>

namespace TemplateGenerator
{

// this removes the first arg
std::vector<std::string> ArgsParser::convert(int argc, const char** argv)
{
	std::vector<str> ans;
	ans.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		ans.emplace_back(argv[i]);
	return ans;
}

ArgsParser::ArgsParser(int argc, const char** args)
{
	std::vector<str> argv = convert(argc, args);

	// flg[i] == true --> item `i` was processed
	std::vector<bool> flg(argv.size(), false);

	for (size_t i {}; i < argv.size(); i++) if (!flg[i]) {
		flg[i] = true;

		// is a stray argument
		if (argv[i][0] != '-') {
			strays.push_back(argv[i]);
			continue;
		}

		// is an option toggler, but the length is illegal
		if (argv[i].length() != 2) {
			std::cerr << "invalid arguments: " << argv[i] << "\n";
			exit(22);	// invalid arguments
		}

		// is a legal option toggler
		if (i + 1 < argv.size() && argv[i + 1][0] != '-') {
			// this option has a value
			dct[argv[i][1]] = argv[i + 1];
			flg[i + 1] = true;
		} else {
			// this option is a flag
			dct[argv[i][1]] = "";
		}
	}
}

}	// namespace EuphoFM

