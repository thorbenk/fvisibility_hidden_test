#pragma once

#include <testlib_export.h>
#include <testlib_template_export.h>

template<class T>
struct vec {
    T getX() { return x; }
    T getY();
    T x, y;
};

extern template struct EXPORT_TEMPLATE vec<int>;
