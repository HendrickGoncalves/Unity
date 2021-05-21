#include "payment.h"
#include "unity.h"
#include "unity_fixture.h"

int expected = 0;
static char status_str[] = {"regular"};

void expect(int ret_value) {
    expected = ret_value;
}

void valid(void) {
    int ret = 3;

    ret = payment(100.0, status_str);
    TEST_ASSERT_EQUAL_INT(expected, ret);
}

void invalidValue(void) {
    int ret = 3;
    
    ret = payment(0.005, status_str);
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

TEST(payment, TestValid) {
    expect(0);
    valid();
}

TEST(payment, TestInvalidValue) {
    expect(1);
    invalidValue();
}

TEST(payment, TestInvalidStatus) {
    expect(2);
    invalidStatus();
}