
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 17:23:55 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef BASIC_GENERATOR_H
#define BASIC_GENERATOR_H

/** @ docs */

/** @ dependencies */
#include <ctime>
#include <fstream>
#include <filesystem>
#include "args_parser.h"

/** @ implementation */
namespace TemplateGenerator
{

class BasicGenerator
{
public:
	using path = std::filesystem::path;
	virtual void exec(const path& dst, const ArgsParser& args);
	virtual void help();

protected:
	std::string m_time;
	std::string m_filename;
	std::string m_basename;
	std::string m_filetype;

	virtual void setup(const path& dst, const ArgsParser& args);

	virtual void line_exec(
		const path& dst,
		const ArgsParser& args,
		std::string& line
	);

	static bool replace(std::string& str, const std::string from, const std::string to);
	static std::string get_template(const path& dst, const ArgsParser& args);
	static std::string get_time();

};

}	// namespace TemplateGenerator

#endif	// BASIC_GENERATOR_H

