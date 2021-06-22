
#include "crypt.h"
#include "header_test.h"
#include "string.h"
#include "unity.h"
#include "unity_fixture.h"

static uint32_t key[8];
static uint32_t input[4];
enc_dec_type enc_dec = 2;
enc_type crypt_type;

/* ----------------------------------------------------------------------------------- */

void initContext(enc_type type, uint32_t *msg, enc_dec_type action) {
    int i;

    switch (type) {
    case XTEA:
        memcpy(key, KEY_128, sizeof(KEY_128));
        break;
    case AES128:
        memcpy(key, AES128_KEY_128, sizeof(AES128_KEY_128));
        break;
    case AES192:
        memcpy(key, AES128_KEY_192, sizeof(AES128_KEY_192));
        break;
    case AES256:
        memcpy(key, AES128_KEY_256, sizeof(AES128_KEY_256));
        break;
    case BLOWFISH128:
        memcpy(key, KEY_128, sizeof(KEY_128));
        break;
    case BLOWFISH192:
        memcpy(key, KEY_192, sizeof(KEY_192));
        break;
    case BLOWFISH256:
        memcpy(key, KEY_256, sizeof(KEY_256));
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
    int i;

    memset(output, 0, sizeof(output));
    memcpy(expect, input, sizeof(expect));

    crypt(key, input, crypt_type, enc_dec, output);

    // printf("\nOutput Encrypted: \n");
    // for (i = 0; i < 4; i++)
    //     printf("%08X ", output[i]);
    // printf("\n");
    
    enc_dec ^= 1;

    crypt(key, output, crypt_type, enc_dec, tmp);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(expect, tmp, 4);

    // printf("\nOutput Decrypted: \n");
    // for (i = 0; i < 4; i++)
    //     printf("%08X ", tmp[i]);
    // printf("\n");
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
    uint32_t key[8];

    memset(key, 0, sizeof(key));

    for (i = 1; i < 4; i++) {
        initContext(i, AES128_PLAN, ENCODER);
        AES128_EncTestAction(i);
    }
    
}

