#pragma once

// figure out which code is executed.
// When testlib is compiled, the `where` functions will return 0
//
// When template functions are instantiated from within the main function,
// we redefine `DEFINED_WHERE`.
#ifndef DEFINED_WHERE
#define DEFINED_WHERE 0
#endif

#include <testlib_export.h>

#include <iostream>
using namespace std;

#if defined(TESTLIB_EXPORT) && defined(testlib_EXPORTS)
  #if (defined(__GNUC__) || defined(__clang__))
      #define EXPORT_TEMPLATE TESTLIB_EXPORT
      #define EXPORT_INSTANTIATE
  #else
      #define EXPORT_TEMPLATE
      #define EXPORT_INSTANTIATE TESTLIB_EXPORT
  #endif
#elif defined(TESTLIB_NO_EXPORT)
  #define EXPORT_TEMPLATE TESTLIB_EXPORT
  #define EXPORT_INSTANTIATE
#endif

//-----------------------------------------------------------------------------

class TESTLIB_EXPORT TestLib
{
public:
    static int where_static();

    int where();
    inline int where_inline() { return DEFINED_WHERE; }
};

//-----------------------------------------------------------------------------

// template class itself not exported
// but each explicit template instantiation is exported
template<typename T>
class A{
public:
    A() = default;
    int where() {
        return DEFINED_WHERE;
    }
};
extern template class EXPORT_TEMPLATE A<int>;
extern template class EXPORT_TEMPLATE A<long>;

//-----------------------------------------------------------------------------

// template class itself is annotated as exported
// explicit template instantiations are not annotated
template<typename T>
class B {
public:
    B() : mInt(0) {}

    int where() {
        return DEFINED_WHERE;
    }
private:
    int mInt;
};
extern template class EXPORT_TEMPLATE B<int>;
extern template class EXPORT_TEMPLATE B<long>;

//-----------------------------------------------------------------------------

// Export all template instantiations
template<typename T>
class C {
public:
    C() {
      mIntP = new int();
    }
    ~C() {
      delete mIntP;
    }
    int where() {
        return DEFINED_WHERE;
    }
private:
    int* mIntP;
};
extern template class EXPORT_TEMPLATE C<int>;

//-----------------------------------------------------------------------------

template<typename T>
struct D {
  int where() { return DEFINED_WHERE; }
};

template<>
struct D<int> {
  int where() { return DEFINED_WHERE; }
};

//-----------------------------------------------------------------------------

template<typename T>
struct E {
  E();

  T get() { return s; }

  static T s;
};

#ifdef __clang__
template<> int E<int>::s;
#endif

extern template struct EXPORT_TEMPLATE E<int>;

//-----------------------------------------------------------------------------

namespace Static {

extern TESTLIB_EXPORT int staticInt;

} /* namespace Static */
