#include "unity_fixture.h"
#include "identifier.h"

static void RunAllTests(void) {
  RUN_TEST_GROUP(identifier);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
