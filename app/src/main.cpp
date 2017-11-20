#include <testlib.h>

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
