// figure out if we instantiate a template here
// or reuse the generated code from the lib */
#define DEFINED_WHERE 1
#include <testlib.h>

#include <iostream>
#include <cassert>
using namespace std;

#define IN_LIB  0
#define IN_MAIN 1

int main() {
    TestLib t;
    assert(t.where() == IN_LIB);
    assert(TestLib::where_static() == IN_LIB);

    assert(A<int>().where() == IN_LIB);
    assert(A<long>().where() == IN_LIB);
    assert(A<float>().where() == IN_MAIN);

    assert(B<int>().where() == IN_LIB);
    assert(B<long>().where() == IN_LIB);
    assert(B<float>().where() == IN_MAIN);

    assert(C<int>().where() == IN_MAIN); // !
    assert(C<long>().where() == IN_LIB);
    assert(C<float>().where() == IN_MAIN);

    return 0;
}
