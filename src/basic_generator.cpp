
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 18:12:22 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include "basic_generator.h"

#include <sstream>
#include "param.h"

namespace TemplateGenerator
{

/**
 * @ static
 * */
bool BasicGenerator::replace(std::string& str, const std::string from, const std::string to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

std::string BasicGenerator::get_template(const path& dst, const ArgsParser& args)
{
	auto strays = args.get_strays();
	std::string opt = "";
	if (strays.size() > 1) {
		opt = strays[1];
		opt = '.' + opt;
	}

	std::stringstream ans;
	ans << Param::get_executable_directory()
		<< "/template/t"
		<< opt
		<< dst.extension().string();

	return ans.str();
}

std::string BasicGenerator::get_time()
{
	time_t t = time(0);
	std::string ans = ctime(&t);
	// remove the linebreak
	return ans.substr(0, ans.length() - 1);
}

/**
 * @ exec
 * */
void BasicGenerator::setup(const path& dst, const ArgsParser& args)
{
	m_time = get_time();
	m_filename = dst.filename().string();
	m_basename = dst.stem().string();
}

void BasicGenerator::exec(const path& dst, const ArgsParser& args)
{
	setup(dst, args);

	std::ifstream fsrc(get_template(dst, args));
	std::ofstream fdst(dst);
	std::string line;
	while (getline(fsrc, line)) {
		line_exec(dst, args, line);
		fdst << line << "\n";
	}
}

void BasicGenerator::line_exec(
	const path& dst,
	const ArgsParser& args,
	std::string& line
) {
	replace(line, "{{date}}", m_time);
}

}

