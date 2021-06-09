#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(identifier) {
  RUN_TEST_CASE(identifier, IdentifierValidStr);
  RUN_TEST_CASE(identifier, IdentifierLength);
  RUN_TEST_CASE(identifier, IdentifierFirstChar);
  RUN_TEST_CASE(identifier, IdentifierInvalidChar);
  RUN_TEST_CASE(identifier, IdentifierInvalidChar2);
  RUN_TEST_CASE(identifier, IdentifierNull);  
  RUN_TEST_CASE(identifier, IdentifierValidDigit);
  RUN_TEST_CASE(identifier, IdentifierInvalidChar3);
  RUN_TEST_CASE(identifier, IdentifierValidChar);
  RUN_TEST_CASE(identifier, IdentifierValidStr2);
  RUN_TEST_CASE(identifier, IdentifierInvalidStr);
  RUN_TEST_CASE(identifier, IdentifierInvalidStr2);
  RUN_TEST_CASE(identifier, IdentifierInvalidDigit);  
  RUN_TEST_CASE(identifier, IdentifierPredTests);
  RUN_TEST_CASE(identifier, IdentifierPredTests2);
}
