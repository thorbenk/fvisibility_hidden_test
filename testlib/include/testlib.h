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
extern template class TESTLIB_EXPORT A<int>;
extern template class TESTLIB_EXPORT A<long>;

//-----------------------------------------------------------------------------

// template class itself is annotated as exported
// explicit template instantiations are not annotated
template<typename T>
class TESTLIB_EXPORT B {
public:
    B() : mInt(0) {}

    int where() {
        return DEFINED_WHERE;
    }
private:
    int mInt;
};
extern template class B<int>;
extern template class B<long>;

//-----------------------------------------------------------------------------

// Export all template instantiations
template<typename T>
class TESTLIB_EXPORT C {
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
template class C<int>;
// C<long> is instantiated in .cpp file and declared extern in main.cpp

//-----------------------------------------------------------------------------

template<typename T>
struct TESTLIB_EXPORT D {
  D() {
    mWhere = DEFINED_WHERE;
  }
  int where_impl_h() {
    return DEFINED_WHERE;
  }
  int where_specialized_int_impl_h() {
    return DEFINED_WHERE;
  }
  int where_specialized_int_impl_cpp() {
    return DEFINED_WHERE;
  }
private:
  int mWhere;
};

template<> int D<int>::where_specialized_int_impl_h() {
  return 2;
}
// forward declare a specialization
template<> int D<int>::where_specialized_int_impl_cpp();

extern template struct D<int>;

//-----------------------------------------------------------------------------

template<typename T>
struct TESTLIB_EXPORT E {
  E();
};

extern template struct E<int>;
