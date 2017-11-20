#pragma once

#include <testlib_export.h>

#include <iostream>

class TESTLIB_EXPORT TestLib
{
public:
    static void test_static();
    void test();
private:
    int mInt;
};

template<typename T>
class TESTLIB_EXPORT TestTemplate {
public:
    TestTemplate() {
       std::cout << sizeof(T) << std::endl;
    }
};

template class TestTemplate<int>;
template class TestTemplate<long>;



