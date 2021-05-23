#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(payment) {
  RUN_TEST_CASE(payment, TestValidSt0);
  RUN_TEST_CASE(payment, TestValidSt1);
  RUN_TEST_CASE(payment, TestValidSt2);
  RUN_TEST_CASE(payment, TestValidSt3);
  RUN_TEST_CASE(payment, TestValidVal0);
  RUN_TEST_CASE(payment, TestValidVal1);
  RUN_TEST_CASE(payment, TestInvalidValue0);
  RUN_TEST_CASE(payment, TestInvalidValue1);
  RUN_TEST_CASE(payment, TestInvalidStatus);
}
