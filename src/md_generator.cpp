
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 19:13:33 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include "md_generator.h"

namespace TemplateGenerator
{

/**
 * @ static
 * */
std::string MdGenerator::get_mdtime() {
	using namespace std;

	static string Month[12] = {
		"Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec",
	};

	time_t now = time(0);
	tm* lct = localtime(&now);
	string
		year  = to_string(1900 + lct->tm_year),
		month = Month[lct->tm_mon],
		day   = to_string(lct->tm_mday);
	return month + '-' + day + '-' + year;
}

/**
 * @ exec
 * */
void MdGenerator::setup(const path& dst, const ArgsParser& args)
{
	m_mdtime = get_mdtime();
}

void MdGenerator::line_exec(
	const path& dst,
	const ArgsParser& args,
	std::string& line
) {
	replace(line, "{{mdtime}}", m_mdtime);
}

}

