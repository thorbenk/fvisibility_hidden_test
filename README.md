# -fvisiblity=hidden example project (cmake)

A simple CMake project consisting of a shared library and an executable
linked to that library. Uses `-fvisibility=hiden` and
`-fvisiblity-inlines-hidden`.

Gives some examples how to export explicit template instantiations
in the library and how to make sure these instantiations are used in
the executable.

Resources:

- [A quick intro to extern templates](http://blog.bitwigglers.org/extern-templates/)
- [Controling Implicit Template Instantiation - N1448](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2003/n1448.pdf)
