
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 12:54:46 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef ARGS_PARSER_H
#define ARGS_PARSER_H

/** @ docs */

/** @ dependencies */
#include <cassert>
#include <string>
#include <vector>
#include <map>

/** @ implementation */
namespace TemplateGenerator
{

struct ArgsParser
{
public:
	using str = std::string;

	explicit ArgsParser(int argc, const char** args);

	bool has(char c) const { return dct.find(c) != dct.end(); }
	bool has_value(char c) const { return has(c) && dct.at(c).length() > 0; }

	const str& get(char c) const { return dct.at(c); }
	const str& get(char c, const str& s) const { return has_value(c) ? get(c) : s; }

	const std::vector<std::string>& get_strays() const { return strays; }

private:
	std::map<char, str> dct;
	std::vector<str> strays;

	static std::vector<str> convert(int argc, const char** args);
};

}	// namespace EuphoFM

#endif	// ARGS_PARSER_H

