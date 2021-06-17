#include "unity_fixture.h"
#include "crypt.h"

static void RunAllTests(void) {
  RUN_TEST_GROUP(crypt);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
