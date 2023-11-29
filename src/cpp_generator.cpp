
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 19:33:05 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include "cpp_generator.h"
#include "param.h"

#include <iostream>

namespace TemplateGenerator
{

void CppGenerator::help()
{
	std::cout
		<< "Usage: g <output-file>"
		<< m_filetype
		<< " [variation] [OPTIONS]\n\n";

	std::cout
		<< "Generate a file based on 't"
		<< m_filetype
		<< "' in the template directory\n";
	std::cout
		<< "Current template directory path: "
		<< Param::get_executable_directory() << "/template/\n\n";

	std::cout
		<< "Variation:\n";
	std::cout
		<< "    If [variation] is specified, template-generator will generate\n"
		<< "    the output file based on 't.[variation]"
		<< m_filetype
		<< "'\n\n";

	std::cout
		<< "Options:\n";
	std::cout
		<< "    -d <definition>   The file's definition (replaces {{deff}})\n"
		<< "    -n <namespace>    The file's namespace (replaces {{namespace}})\n"
		<< "    -c <class>        The file's class (replaces {{class}})\n\n";
}

void CppGenerator::setup(const path& dst, const ArgsParser& args)
{
	const auto deff = [](const std::string& fname) {
		std::string ans;
		for (char c: fname) {
			if ('a' <= c && c <= 'z')
				c = c - 'a' + 'A';
			else if (c == '-' || c == ' ' || c == '.')
				c = '_';
			ans += c;
		}
		return ans;
	};

	BasicGenerator::setup(dst, args);
	m_deff = args.get('d', deff(m_filename));
	m_nspc = args.get('n', Param::CppDefaultNSPC);
	m_clss = args.get('c', Param::CppDefaultCLSS);
}

void CppGenerator::line_exec(
	const path& dst,
	const ArgsParser& args,
	std::string& line
) {
	BasicGenerator::line_exec(dst, args, line);
	replace(line, "{{deff}}", m_deff);
	replace(line, "{{namespace}}", m_nspc);
	replace(line, "{{class}}", m_clss);
}


}

