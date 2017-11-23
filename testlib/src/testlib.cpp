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

template<>
int D<int>::where_specialized_int_impl_cpp() {
  return 2;
}

template struct D<int>;

template<typename T>
E<T>::E() {}
template struct E<int>;
