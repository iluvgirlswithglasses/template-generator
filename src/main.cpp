
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 13:09:34 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include <map>
#include <iostream>
#include <filesystem>
#include "args-parser.h"
#include "param.h"
#include "basic_generator.h"
#include "cpp_generator.h"
#include "cs_generator.h"
#include "md_generator.h"
using namespace std;
using namespace std::filesystem;
using namespace TemplateGenerator;

void solve(ArgsParser& args)
{
	/** @ build target (destination) file information */
	path dst(args.get_strays()[0]);
	if (dst.extension() == "")
		dst += Param::DefaultFileType;

	/** @ collect generators */
	map<string, int (*)(const path&)> gen = {
		{ ".cpp", CppGenerator::exec },
		{ ".h",   CppGenerator::exec },
		{ ".md",  MdGenerator::exec },
		{ ".cs",  CsGenerator::exec },
	};

	string typ = dst.extension();
	if (gen.find(typ) == gen.end())
		BasicGenerator::exec(dst);
	else
		gen[typ](dst);
}

int main(int argc, const char** argv)
{
	constexpr char Help[] =
		"To see help for generating an `.x` file, type:\n" \
		"	g .x -h\n";

	ios_base::sync_with_stdio(false); cin.tie(0);

	ArgsParser args(argc, argv);
	if (args.get_strays().size() == 0)
		cout << Help;
	else
		solve(args);

	return 0;
}
