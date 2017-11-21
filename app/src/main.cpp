// figure out if we instantiate a template here
// or reuse the generated code from the lib */
#define DEFINED_WHERE 1
#include <testlib.h>

#include <iostream>
#include <cassert>
using namespace std;

#define IN_LIB  0
#define IN_MAIN 1

void assert_eq(int a, int b)
{
    if (a != b) {
        cout << "failed!" << endl;
        exit(1);
    }
}

int main() {
    TestLib t;
    assert_eq(TestLib::where_static() , IN_LIB);
    assert_eq(t.where() , IN_LIB);
    assert_eq(t.where_inline() , IN_MAIN);

    assert_eq(A<int>().where() , IN_LIB);
    assert_eq(A<long>().where() , IN_LIB);
    assert_eq(A<float>().where() , IN_MAIN);

    assert_eq(B<int>().where() , IN_LIB);
    assert_eq(B<long>().where() , IN_LIB);
    assert_eq(B<float>().where() , IN_MAIN);

    assert_eq(C<int>().where() , IN_MAIN); // !
    assert_eq(C<long>().where() , IN_LIB);
    assert_eq(C<float>().where() , IN_MAIN);

    cout << "done" << endl;

    return 0;
}
