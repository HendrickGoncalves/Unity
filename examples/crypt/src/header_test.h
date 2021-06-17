
#ifndef __HEADER_TEST_H__
#define __HEADER_TEST_H__

#include <stdint.h>

const uint32_t KEY_128[] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
const uint32_t KEY_192[] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL, 0xFFFFFFFF, 0x10101010};
const uint32_t  KEY_256[] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL, 0xFFFFFFFF, 0x10101010, 0xAAAAAAAA, 0x11111111};

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

void memcpy32(uint32_t *output, uint32_t *input, uint32_t size);

#endif /* __HEADER_TEST_H__ */