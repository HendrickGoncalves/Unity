
#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

error_code expected = 2;

static char str1[] = {"A1\n"};
static char str2[] = {"A1b2C3d\n"};
static char str3[] = {"2b3\n"};
static char str4[] = {"Z-12\n"};

void expect(error_code ret_value, char *test_str) {
    FILE *fp;
    fp = fopen("src/test_file.txt", "w");

    if(fp == NULL)
        printf("Error trying to open/create this file!\n");

    fprintf(fp, test_str);
    fclose(fp);

    expected = ret_value;
}

void IdentifierTestAction(void) {
    error_code ret = 2;

    ret = identifier();

    TEST_ASSERT_EQUAL_INT((int)expected, (int)ret);
}

TEST_GROUP(identifier);

TEST_SETUP(identifier) {
    
}

TEST_TEAR_DOWN(identifier) {
}

TEST(identifier, IdentifierValidStr) {
    expect(ret_valid, str1);
    IdentifierTestAction();
}

TEST(identifier, IdentifierLength) {
    expect(ret_invalid, str2);
    IdentifierTestAction();
}

TEST(identifier, IdentifierFirstChar) {
    expect(ret_invalid, str3);
    IdentifierTestAction();
}

TEST(identifier, IdentifierInvalidChar) {
    expect(ret_invalid, str4);
    IdentifierTestAction();
}
