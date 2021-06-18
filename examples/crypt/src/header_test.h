
#ifndef __HEADER_TEST_H__
#define __HEADER_TEST_H__

#include <stdint.h>

const uint32_t KEY_128[] = {0xA5A5A5A5, 0x1234567L, 0xFEDCBA98, 0x5A5A5A5A};
const uint32_t KEY_192[] = {0xA5A5A5A5, 0x1234567L, 0xFEDCBA98, 0x5A5A5A5A, 0xFFFFFFFF, 0x10101010};
const uint32_t  KEY_256[] = {0xA5A5A5A5, 0x1234567L, 0xFEDCBA98, 0x5A5A5A5A, 0xFFFFFFFF, 0x10101010, 0xAAAAAAAA, 0x11111111};

/* ----------------------------- AES128 -----------------------------------------------*/
const uint32_t AES128_PLAN[] = {0, 0, 0};

const uint32_t AES128_KEY_128[] = {0x10a58869, 0xd74be5a3, 0x74cf867c, 0xfb473859};
const uint32_t AES128_CIPHER_128[] = {0x6d251e69, 0x44b051e0, 0x4eaa6fb4, 0xdbf78465};

const uint32_t AES128_KEY_192[] = {0xe9f065d7, 0xc1357358, 0x7f787535, 0x7dfbb16c, 0x53489f6a, 0x4bd0f7cd};
const uint32_t AES128_CIPHER_192[] = {0x0956259c, 0x9cd5cfd0, 0x181cca53, 0x380cde06};

const uint32_t AES128_KEY_256[] = {0xc47b0294, 0xdbbbee0f, 0xec4757f2, 0x2ffeee35, 0x87ca4730, 0xc3d33b69, 0x1df38bab, 0x076bc558};
const uint32_t AES128_CIPHER_256[] = {0x46f2fb34, 0x2d6f0ab4, 0x77476fc5, 0x01242c5f};

/* ------------------------------------------------------------------------ --------- */

typedef enum {
    XTEA = 0,
    AES128,
    AES192,
    AES256,
    BLOWFISH128,
    BLOWFISH192,
    BLOWFISH256
} enc_type;

typedef enum {
    DECODER = 0,
    ENCODER
} enc_dec_type;

#endif /* __HEADER_TEST_H__ */