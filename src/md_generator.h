
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 17:44:25 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef MD_GENERATOR_H
#define MD_GENERATOR_H

/** @ docs */

/** @ dependencies */
#include "basic_generator.h"

/** @ implementation */
namespace TemplateGenerator
{

class MdGenerator: public BasicGenerator
{
public:

protected:
	void setup(const path& dst, const ArgsParser& args) override;

	void line_exec(
		const path& dst,
		const ArgsParser& args,
		std::string& line
	) override;

private:
	std::string m_mdtime;

	static std::string get_mdtime();

};

}	// namespace TemplateGenerator

#endif	// MD_GENERATOR_H

