# Template Generator

Template Generator! Originally a part of iluvgirlswithglasses/arch-tools, it evolved into something so sophisticated that it deserves its own repository!

I don't expect anyone other than me to use this, but I just love to write docs such as this one; so check it out.

# Installation

Build via CMake:

```sh
git clone https://github.com/iluvgirlswithglasses/template-generator
cd template-generator
cmake .
make    # an executable file named `./g` should be available after this
```

Once built, copy both `./g` and `./template` into any directory that's in `$PATH` environment. Then, you can execute this command at any place in your system:

```sh
g -h    # see help
```
# How to use

Assume this is your `template/t.c` file:

```C
// author: 	iluvgirlswithglasses
// created:	{{date}}
#include <stdio.h>

int main() {
	return 0;
}
```

By executing `g ~/test.c`, the program creates a `~/test.c` file that looks like this:

```C
// author: 	iluvgirlswithglasses
// created:	Mon Nov 27 14:39:22 2023
#include <stdio.h>

int main() {
	return 0;
}
```

As you can see, this repository replaces any token such as `{{date}}` into something else. To see what is replaced by what, see [this function](src/basic_generator.cpp#L139-L142) and its derivatives.

For more details, see help via the `-h` flag.

