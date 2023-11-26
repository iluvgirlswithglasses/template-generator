
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
#include <filesystem>

/** @ implementation */
namespace TemplateGenerator
{

class MdGenerator
{
public:
	using path = std::filesystem::path;
	static int exec(const path& dst);

private:

};

}	// namespace TemplateGenerator

#endif	// MD_GENERATOR_H

