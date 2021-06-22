#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(crypt) {
  RUN_TEST_CASE(crypt, CryptLogic);
  RUN_TEST_CASE(crypt, AES128_EncTest);
  // RUN_TEST_CASE(crypt, AES192_EncLogic);
  // RUN_TEST_CASE(crypt, AES256_EncLogic);
}
