#include "unity_fixture.h"
#include "sort.h"

static void RunAllTests(void) {
  RUN_TEST_GROUP(sort);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
