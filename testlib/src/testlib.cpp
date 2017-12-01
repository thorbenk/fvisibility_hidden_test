#include <testlib.h>

#include <iostream>

#include <vec.i>

// generate code for vec<int>
// so it is available to users of this library
template struct vec<int>;

using namespace std;

int TestLib::where() {
    return DEFINED_WHERE;
}

int TestLib::where_static() {
    return DEFINED_WHERE;
}

template class EXPORT_INSTANTIATE A<int>;
template class EXPORT_INSTANTIATE A<long>;

template class EXPORT_INSTANTIATE B<int>;
template class EXPORT_INSTANTIATE B<long>;

template class EXPORT_INSTANTIATE C<int>;

template<typename T>
E<T>::E() {}
template struct EXPORT_INSTANTIATE E<int>;

template<> int E<int>::s = 42;

int Static::staticInt = 42;


