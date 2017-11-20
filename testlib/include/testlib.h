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

// Export each explicit template instantiation
template<typename T>
class TemplateExportClass {
public:
    TemplateExportClass() { std::cout << sizeof(T) << std::endl; }
};
template class TESTLIB_EXPORT TemplateExportClass<int>;
template class TESTLIB_EXPORT TemplateExportClass<long>;

// Export all template instantiations
template<typename T>
class TESTLIB_EXPORT TemplateExportExplicitInstantiation {
public:
    TemplateExportExplicitInstantiation() { std::cout << sizeof(T) << std::endl; }
};
template class TemplateExportExplicitInstantiation<int>;
template class TemplateExportExplicitInstantiation<long>;
// not allowed: duplicate explicit instantiation of ‘class TestTemplate2<int>’
// template class TestTemplate2<int>;

template<typename T>
class TESTLIB_EXPORT TemplateNoExplicitInstantiation {
public:
    TemplateNoExplicitInstantiation() { std::cout << sizeof(T) << std::endl; }
};
