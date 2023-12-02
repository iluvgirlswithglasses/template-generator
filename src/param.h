
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Sun Nov 26 16:26:05 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef PARAM_H
#define PARAM_H

/** @ docs */

/** @ dependencies */
#include <string>

/** @ implementation */
namespace TemplateGenerator
{

struct Param
{
public:
	static constexpr char
		DefaultFileType[] = ".cpp",
		TemplateDirectory[] = "/home/mika/exc/template/";

	/** @ C++ */
	inline static const std::string
		CppDefaultNSPC = "NSPC";

	/** @ C# */

private:

};

}	// namespace TemplateGenerator

#endif	// PARAM_H

