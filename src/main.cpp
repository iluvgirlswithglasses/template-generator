
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
#include "args_parser.h"
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
	if (dst.extension() == "") {
		if (args.has('h'))
			dst += dst.filename();	// cast .cpp to .cpp.cpp to get help
		else
			dst += Param::DefaultFileType;
	}

	/** @ collect generators */
	CppGenerator cppgen;
	MdGenerator mdgen;
	CsGenerator csgen;
	BasicGenerator bscgen;

	map<string, BasicGenerator*> gen = {
		{ ".cpp", &cppgen },
		{ ".h",   &cppgen },
		{ ".c",   &cppgen },
		{ ".md",  &mdgen },
		{ ".cs",  &csgen },
	};

	/** @ exec */
	string typ = dst.extension();
	if (gen.find(typ) == gen.end())
		bscgen.exec(dst, args);
	else
		gen[typ]->exec(dst, args);
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
