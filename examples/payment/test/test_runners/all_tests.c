#include "unity_fixture.h"
#include "payment.h"

static void RunAllTests(void) {
  RUN_TEST_GROUP(payment);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
