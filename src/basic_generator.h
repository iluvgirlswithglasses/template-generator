
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
#include <filesystem>

/** @ implementation */
namespace TemplateGenerator
{

class BasicGenerator
{
public:
	using path = std::filesystem::path;
	static int exec(const path& dst);

private:

};

}	// namespace TemplateGenerator

#endif	// BASIC_GENERATOR_H

