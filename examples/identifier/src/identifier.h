
#ifndef __IDENTIFIER_H__
#define __IDENTIFIER_H__

#include <stdio.h>

typedef enum {
    ret_valid = 0, /* return 0 when identifier is valid */
    ret_invalid
} error_code;

int identifier(void);
int valid_f(char ch);
int valid_s(char ch);

#endif /* __IDENTIFIER_H__ */