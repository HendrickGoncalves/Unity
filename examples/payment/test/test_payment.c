#include "payment.h"
#include "unity.h"
#include "unity_fixture.h"

// 0 - Sucesso; 1 - Erro no valor; 2 - Status incorreto

int expected = 0;
static char status_str0[] = {"regular"};
static char status_str1[] = {"estudante"};
static char status_str2[] = {"aposentado"};
static char status_str3[] = {"VIP"};

void expect(int ret_value) {
    expected = ret_value;
}

void validSt0(void) {
    int ret = 3;
    ret = payment(100.0, status_str0);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void validSt1(void) {
    int ret = 3;
    ret = payment(100.0, status_str1);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void validSt2(void) {
    int ret = 3;
	expected = 0; 
    ret = payment(100.0, status_str2);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void validSt3(void) {
    int ret = 3;
    ret = payment(100.0, status_str3);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void validVal0(void) {
    int ret = 3;
    ret = payment(0.02, status_str0);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void validVal1(void) {
    int ret = 3;
    ret = payment(99999.0, status_str0);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void invalidValue0(void) {
    int ret = 3;
    
    ret = payment(0.005, status_str0);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void invalidValue1(void) {
    int ret = 3;
    
    ret = payment(99999.99, status_str0);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void invalidStatus(void) {
    int ret = 3;
    char tmp[] = {"gremio"};
    
    ret = payment(1.0, tmp);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

TEST_GROUP(payment);

TEST_SETUP(payment) {
    
}

TEST_TEAR_DOWN(payment) {
}

TEST(payment, TestValidSt0) {
    expect(0);
    validSt0();
}

TEST(payment, TestValidSt1) {
    expect(0);
    validSt1();
}

TEST(payment, TestValidSt2) {
    expect(0);
    validSt2();
}

TEST(payment, TestValidSt3) {
    expect(0);
    validSt3();
}

TEST(payment, TestValidVal0) {
    expect(0);
    validVal0();
}

TEST(payment, TestValidVal1) {
    expect(0);
    validVal1();
}

TEST(payment, TestInvalidValue0) {
    expect(1);
    invalidValue0();
}

TEST(payment, TestInvalidValue1) {
    expect(1);
    invalidValue1();
}

TEST(payment, TestInvalidStatus) {
    expect(2);
    invalidStatus();
}
