
#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

error_code expected = 2;

static char str1[] = {"A1\n"};
static char str2[] = {"A1b2C3d\n"};
static char str3[] = {"2b3\n"};
static char str4[] = {"Z-12\n"};
static char str5[] = {"zed*dd\n"};
static char str6[] = {" \n"};
static char str7[] = {"z12345\n"};
static char str8[] = {"@@\n"};
static char str9[] = {"A\n"};
static char str10[] = {"abcdef\n"};
static char str11[] = {"1abcde\n"};
static char str12[] = {"abcdef0\n"};
static char str13[] = {"9\n"};


/* ----------------------------------------------------------------------------------- */

static Unity_Test test_buffer[] = {{"A\n"}, {"@\n"}, {"Z\n"}, {"[\n"}, {"a\n"}, {"-\n"}, {"z\n"}, {"{\n"},
                                {"AA\n"}, {"A@\n"}, {"ZZ\n"}, {"Z[\n"}, {"aa\n"}, {"a-\n"}, {"zz\n"}, {"z{\n"}, {"a0\n"}, {"a/\n"}, {"a9\n"}, {"a:\n"}};


static Unity_Test test_buffer2[] = {{"aa\n"}, {"--\n"}, {"a\n"}, {" \n"}, {"abcdef\n"}, {"abcdefg\n"}};

/* ----------------------------------------------------------------------------------- */

void expect(error_code ret_value, char *test_str) {
    FILE *fp;
    fp = fopen("src/test_file.txt", "w");

    if(fp == NULL)
        printf("Error trying to open/create this file!\n");

    //if(test_str != NULL)
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

TEST(identifier, IdentifierInvalidChar2) {
    expect(ret_invalid, str5);
    IdentifierTestAction();
}

TEST(identifier, IdentifierNull) {
    expect(ret_invalid, str6);
    IdentifierTestAction();
}

TEST(identifier, IdentifierValidDigit) {
    expect(ret_valid, str7);
    IdentifierTestAction();
}

TEST(identifier, IdentifierInvalidChar3) {
    expect(ret_invalid, str8);
    IdentifierTestAction();
}

TEST(identifier, IdentifierValidChar) {
    expect(ret_valid, str9);
    IdentifierTestAction();
}
TEST(identifier, IdentifierValidStr2) {
    expect(ret_valid, str10);
    IdentifierTestAction();
}

TEST(identifier, IdentifierInvalidStr) {
    expect(ret_invalid, str11);
    IdentifierTestAction();
}

TEST(identifier, IdentifierInvalidStr2) {
    expect(ret_invalid, str12);
    IdentifierTestAction();
}

TEST(identifier, IdentifierInvalidDigit) {
    expect(ret_invalid, str13);
    IdentifierTestAction();
}

TEST(identifier, IdentifierPredTests) {
    uint8_t i;
    error_code tmp = 0;

    for (i = 0; i < 20; i++) {
        expect(tmp, test_buffer[i].test_string);
        IdentifierTestAction();   

        tmp ^= 1;
    }
}

TEST(identifier, IdentifierPredTests2) {
    uint8_t i;
    error_code tmp = 0;

    for (i = 0; i < 6; i++) {
        expect(tmp, test_buffer2[i].test_string);
        IdentifierTestAction();   

        tmp ^= 1;
    }
}


