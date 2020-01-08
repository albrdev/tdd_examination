#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Geometry);
    RUN_TEST_GROUP(NamespaceString); 
    RUN_TEST_GROUP(Calculator);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
