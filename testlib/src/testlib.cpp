#include <testlib.h>

#include <iostream>

using namespace std;

int TestLib::where() {
    return DEFINED_WHERE;
}

int TestLib::where_static() {
    return DEFINED_WHERE;
}

template class A<int>;
template class A<long>;

template class B<int>;
template class B<long>;

template class C<long>;


