
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Mon Nov 27 11:40:00 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

/** @ docs */

/** @ dependencies */
#include <string>
#include <sys/stat.h>

/** @ implementation */
namespace TemplateGenerator
{

class FileManager
{
public:
	static bool file_exists(const std::string& s)
	{
		struct stat buffer;
		return (stat(s.c_str(), &buffer) == 0);
	}

private:

};

}	// namespace TemplateGenerator

#endif	// FILE_MANAGER_H

