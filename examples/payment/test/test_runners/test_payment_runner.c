#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(payment) {
  RUN_TEST_CASE(payment, TestValid);
  RUN_TEST_CASE(payment, TestInvalidValue);
  RUN_TEST_CASE(payment, TestInvalidStatus);
}
