#include <testlib.h>

int main()
{
    TestLib t;

    t.test();
    TestLib::test_static();

    TestTemplate<int>();
    TestTemplate<long>();

    return 0;
}
