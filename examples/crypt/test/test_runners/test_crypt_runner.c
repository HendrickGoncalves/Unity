#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(crypt) {
  RUN_TEST_CASE(crypt, CryptLogic);
  RUN_TEST_CASE(crypt, AES128_EncTest);
  RUN_TEST_CASE(crypt, Crypt_KeySupSizeTest);
  RUN_TEST_CASE(crypt, Crypt_InputSizeTest);
  RUN_TEST_CASE(crypt, Crypt_OutputSizeTest); 
  RUN_TEST_CASE(crypt, Crypt_EncDecTest); 
}
