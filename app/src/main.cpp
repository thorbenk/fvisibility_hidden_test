#include <testlib.h>

// exported in `testlib`, so we do not have to instantiate here
extern template class TemplateExportClass<int>;

// does not work, becaues `testlib` does not export the `float` instantiation!
// extern template class TemplateExportClass<float>;

int main()
{
    TestLib t;

    t.test();
    TestLib::test_static();

    TemplateExportClass<int>();    // from lib
    TemplateExportClass<long>();   // from lib
    TemplateExportClass<float>();  // instantiated here

    TemplateExportExplicitInstantiation<int>(); // from lib
    TemplateNoExplicitInstantiation<long>();    // from lib
    TemplateNoExplicitInstantiation<float>();   // instantiated here

    return 0;
}
