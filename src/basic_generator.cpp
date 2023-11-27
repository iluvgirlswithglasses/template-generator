
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

#include <iostream>
#include <sstream>
#include "param.h"
#include "file_manager.h"

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
void BasicGenerator::help() const
{
	std::cout
		<< "Usage: g <output-file> [variation]\n\n";
	std::cout
		<< "Generate <output-file> based on 't.filetype' in the template directory\n"
		<< "Current template directory path: "
		<< Param::get_executable_directory() << "/template/\n\n";
	std::cout
		<< "Variation:\n"
		<< "    If [variation] is specified, template-generator will generate\n"
		<< "    <output-file> based on 't.[variation].filetype'\n\n";
}

void BasicGenerator::setup(const path& dst, const ArgsParser& args)
{
	m_time = get_time();
	m_filename = dst.filename().string();
	m_basename = dst.stem().string();
}

void BasicGenerator::exec(const path& dst, const ArgsParser& args)
{
	/** @ check if help */
	if (args.has('h')) {
		help();
		return;
	}

	/** @ ensure that the template file exists */
	std::string template_path = get_template(dst, args);
	if (!FileManager::file_exists(template_path)) {
		std::clog
			<< "ERROR: Template file for "
			<< dst.filename() << " ("
			<< path(template_path).filename().string() << ") "
			<< "does not exist\n\n";
		std::clog
			<< "You can create that template yourself & save it as:\n"
			<< "\"" << template_path << "\"\n\n";
		return;
	}

	/** @ generate */
	setup(dst, args);

	std::ifstream fsrc(template_path);
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
	replace(line, "{{filename}}", m_filename);
	replace(line, "{{basename}}", m_basename);
}

}

