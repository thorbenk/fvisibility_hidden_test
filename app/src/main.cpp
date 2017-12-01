// figure out if we instantiate a template here
// or reuse the generated code from the lib */
#define DEFINED_WHERE 1
#include <testlib.h>

#include <iostream>
#include <cassert>
using namespace std;

#define IN_LIB  0
#define IN_MAIN 1
#define IN_LIB_SPECIALIZATION 2

#define assert_eq(a, b) \
{ \
  if ((a) != (b)) { \
    cout << "failed at " << __FILE__ << ":" << __LINE__ << endl; \
    cout << (a) << " != " << (b) << endl; \
    exit(1); \
  } \
}

int main() {
    TestLib t;
    assert_eq(TestLib::where_static() , IN_LIB);
    assert_eq(t.where() , IN_LIB);
#if !defined(NDEBUG) && defined(_MSC_VER)
    assert_eq(t.where_inline() , IN_LIB);
#else
    assert_eq(t.where_inline() , IN_MAIN);
#endif

#ifndef NDEBUG
    assert_eq(A<int>().where() , IN_LIB);
    assert_eq(A<long>().where() , IN_LIB);
#else
    assert_eq(A<int>().where() , IN_MAIN);
    assert_eq(A<long>().where() , IN_MAIN);
#endif
    assert_eq(A<float>().where() , IN_MAIN);

#ifndef NDEBUG
    assert_eq(B<int>().where() , IN_LIB);
    assert_eq(B<long>().where() , IN_LIB);
#else
    assert_eq(B<int>().where() , IN_MAIN);
    assert_eq(B<long>().where() , IN_MAIN);
#endif
    assert_eq(B<float>().where() , IN_MAIN);

#ifndef NDEBUG
    assert_eq(C<int>().where() , IN_LIB);
#else
    assert_eq(C<int>().where() , IN_MAIN);
#endif
    assert_eq(C<long>().where() , IN_MAIN);
    assert_eq(C<float>().where() , IN_MAIN);

    assert_eq(D<int>().where() , IN_MAIN);
    assert_eq(D<long>().where() , IN_MAIN);

    assert_eq(Static::staticInt, 42);
    cout << "done" << endl;

    E<int> e;
    //E<float> eF; // ==> undefined reference to `E<float>::E()`

    return 0;
}
