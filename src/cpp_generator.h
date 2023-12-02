
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 17:41:41 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef CPP_GENERATOR_H
#define CPP_GENERATOR_H

/** @ docs */

/** @ dependencies */
#include "basic_generator.h"

/** @ implementation */
namespace TemplateGenerator
{

class CppGenerator: public BasicGenerator
{
public:
	void help() override;

protected:
	void setup(const path& dst, const ArgsParser& args) override;

	void line_exec(
		const path& dst,
		const ArgsParser& args,
		std::string& line
	) override;

	std::string get_definition(const std::string& filename);
	std::string get_classname(const std::string& basename);
	bool is_seperator(char c) { return c == ' ' || c == '.' || c == '-' || c == '_'; }

private:
	std::string
		m_deff,		// file definition
		m_nspc,		// namespace
		m_clss;		// file class

};

}	// namespace TemplateGenerator

#endif	// CPP_GENERATOR_H

