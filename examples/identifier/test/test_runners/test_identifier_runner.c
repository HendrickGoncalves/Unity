#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(identifier) {
  RUN_TEST_CASE(identifier, IdentifierValidStr);
  RUN_TEST_CASE(identifier, IdentifierLength);
  RUN_TEST_CASE(identifier, IdentifierFirstChar);
  RUN_TEST_CASE(identifier, IdentifierInvalidChar);
  RUN_TEST_CASE(identifier, IdentifierInvalidChar2);
  RUN_TEST_CASE(identifier, IdentifierNull);  
}
