
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
#include <vector>

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
		<< Param::TemplateDirectory << "\n\n";

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

std::string CppGenerator::get_definition(const std::string& filename)
{
	std::string ans;
	for (char c: filename) {
		if ('a' <= c && c <= 'z')
			c = c - 'a' + 'A';
		else if (is_seperator(c))
			c = '_';
		ans += c;
	}
	return ans;
}

std::string CppGenerator::get_classname(const std::string& basename)
{
	std::string ans;
	size_t len = basename.length(), lst = 0;
	for (int i = 0; i <= len; i++) if (i == len || is_seperator(basename[i])) {
		if (i - lst > 0) {
			size_t cap = ans.length();
			ans += basename.substr(lst, i - lst);
			if ('a' <= ans[cap] && ans[cap] <= 'z')
				ans[cap] = ans[cap] - 'a' + 'A';
		}
		lst = i + 1;
	}
	return ans;
}

void CppGenerator::setup(const path& dst, const ArgsParser& args)
{
	BasicGenerator::setup(dst, args);
	m_deff = args.get('d', get_definition(m_filename));
	m_nspc = args.get('n', Param::CppDefaultNSPC);
	m_clss = args.get('c', get_classname(m_basename));
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

