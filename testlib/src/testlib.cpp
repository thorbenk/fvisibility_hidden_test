#include <testlib.h>

#include <iostream>

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
template struct E<int>;

int Static::staticInt = 42;
