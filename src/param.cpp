
/*
author: 	iluvgirlswithglasses
github: 	https://github.com/iluvgirlswithglasses
created:	Thu Nov 23 18:18:11 2023
style:  	C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
FYI I use Debian
*/

#include "param.h"

#include <iostream>
#include <cstring>
#include <filesystem>
#include <unistd.h>

namespace TemplateGenerator
{

Param::ExecutableDirectory::ExecutableDirectory()
	: dir([]() -> std::string {
		char ans[MaxPathLength];
		if (readlink("/proc/self/exe", ans, sizeof(ans)) == -1)
			return "";	// not on linux --> this feature is unsupported
		using path = std::filesystem::path;
		return path(ans).parent_path().string();
	}())
{
}

const std::string& Param::get_executable_directory()
{
	static const ExecutableDirectory exec;
	return exec.dir;
}

}	// namespace IbFace

