
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

namespace TemplateGenerator
{

void CppGenerator::setup(const path& dst, const ArgsParser& args)
{
	BasicGenerator::setup(dst, args);
	m_deff = args.get('d', Param::CppDefaultDEFF);
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

