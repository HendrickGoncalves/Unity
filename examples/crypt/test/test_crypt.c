
#include "crypt.h"
#include "header_test.h"
#include "string.h"
#include "unity.h"
#include "unity_fixture.h"

static uint32_t key[8];
static uint32_t input[4];
enc_dec_type enc_dec = 2;
enc_type crypt_type;

uint8_t size_test = 0;

uint32_t key_test[9];

/* ----------------------------------------------------------------------------------- */

void initContext(enc_type type, const uint32_t *msg, enc_dec_type action) {

    memset(key, 0, sizeof(key));

    switch (type) {
    case XTEA:
        memcpy(key, KEY_128, sizeof(KEY_128));
        size_test = 4;
        break;
    case AES128:
        memcpy(key, AES128_KEY_128, sizeof(AES128_KEY_128));
        size_test = 4;
        break;
    case AES192:
        memcpy(key, AES128_KEY_192, sizeof(AES128_KEY_192));
        size_test = 6;
        break;
    case AES256:
        memcpy(key, AES128_KEY_256, sizeof(AES128_KEY_256));
        size_test = 8;
        break;
    case BLOWFISH128:
        memcpy(key, KEY_128, sizeof(KEY_128));
        size_test = 4;
        break;
    case BLOWFISH192:
        memcpy(key, KEY_192, sizeof(KEY_192));
        size_test = 6;
        break;
    case BLOWFISH256:
        memcpy(key, KEY_256, sizeof(KEY_256));
        size_test = 8;
        break;
    default:
        break;
    }

    memcpy(input, msg, sizeof(input));
    enc_dec = action;
    crypt_type = type;
}

void CryptLogic(void) {
    uint32_t output[4];
    uint32_t expect[4];
    uint32_t tmp[4];

    memset(output, 0, sizeof(output));
    memcpy(expect, input, sizeof(expect));

    crypt(key, input, crypt_type, enc_dec, output);

    enc_dec ^= 1;

    crypt(key, output, crypt_type, enc_dec, tmp);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(expect, tmp, 4);
}

void AES128_EncTestAction(enc_type type) {
    uint32_t output[4];

    crypt(key, input, crypt_type, enc_dec, output);
    
    switch (type){
    case AES128:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER_128, output, 4);
        break;
    case AES192:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER_192, output, 4);
        break;
    case AES256:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER_256, output, 4);
        break;
    default:
        break;
    }
    
}

void Crypt_KeySizeTestAction(void) { 
    uint32_t output_golden[4], output[4];

    memset(key_test, 0xFFFFFFFF, sizeof(key_test));
    memcpy(key_test, key, size_test*sizeof(uint32_t));

    crypt(key, input, crypt_type, enc_dec, output_golden);
    crypt(key_test, input, crypt_type, enc_dec, output);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(output_golden, output, 4);
}

void Crypt_InputSizeTestAction(uint32_t *plan_test) {
    uint32_t output_golden[4], output[4];

    crypt(key, input, crypt_type, enc_dec, output_golden);
    crypt(key, plan_test, crypt_type, enc_dec, output);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(output_golden, output, 4);
}

void Crypt_OutputSizeTest(void) {
    uint32_t output_golden[4], output[5];
    uint32_t test_var = 0xFFFFFFFF;

    memset(output, 0xFFFFFFFF, sizeof(output));

    crypt(key, input, crypt_type, enc_dec, output_golden);
    crypt(key, input, crypt_type, enc_dec, output);

    TEST_ASSERT_EQUAL_UINT32(test_var, output[4]);
}

void Crypt_EncDecTestAction(uint8_t encdec_test) {
    uint32_t output_enc[4], output_dec[4];
    uint32_t array_test[4];

    memcpy(array_test, input, sizeof(array_test));

    crypt(key, input, crypt_type, encdec_test, output_enc);
    crypt(key, output_enc, crypt_type, 0, output_dec);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(input, output_dec, 4);   
}

void Crypt_EncTypeTestAction(void) {
    uint32_t output[4];
    uint32_t test_var = 0xFFFFFFFF;

    memset(output, 0xFFFFFFFF, sizeof(output));

    crypt(key, input, 7, enc_dec, output);

    TEST_ASSERT_EQUAL_UINT32(test_var, output[3]);
}

TEST_GROUP(crypt);

TEST_SETUP(crypt) {
    
}

TEST_TEAR_DOWN(crypt) {
}

TEST(crypt, CryptLogic) {
    uint8_t i;
    uint32_t plan[4] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF};

    for (i = 0; i < 7; i++) {
        initContext(i, plan, ENCODER);
        CryptLogic();
    }   
}

TEST(crypt, AES128_EncTest) {
    uint8_t i;
    
    for (i = 1; i < 4; i++) {
        initContext(i, AES128_PLAN, ENCODER);
        AES128_EncTestAction(i);
    }
    
}

TEST(crypt, Crypt_KeySupSizeTest) { //limite superior
    uint8_t i;
    uint32_t plan[4] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF};

    for (i = 1; i < 7; i++) {
        initContext(i, plan, ENCODER);
        Crypt_KeySizeTestAction();
    }
    
}

TEST(crypt, Crypt_InputSizeTest) {
    uint8_t i;
    uint32_t plan_test[5] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF, 0xFFFFFFFF};
    uint32_t plan_golden[4] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF};

    for (i = 1; i < 7; i++) {
        initContext(i, plan_golden, ENCODER);
        Crypt_InputSizeTestAction(plan_test);
    }
    
}

TEST(crypt, Crypt_OutputSizeTest) {
    uint8_t i;
    uint32_t plan[4] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF};

    for (i = 1; i < 7; i++) {
        initContext(i, plan, ENCODER);
        Crypt_OutputSizeTest();
    }
    
}

TEST(crypt, Crypt_EncDecTest) {
    uint32_t plan[4] = {0x01234567, 0x89ABCDEF, 0x01234567, 0x89ABCDEF};

    initContext(0, plan, ENCODER);

    Crypt_EncDecTestAction(2);
}

TEST(crypt, Crypt_EncTypeTest) { //testa type maior do que 6
    Crypt_EncTypeTestAction();
}