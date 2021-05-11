#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

static int buffer[100]; 
static int out[100]; 
static int *expected;

void initBuffer(int *ptr, int size) {
    int k = 0;

    for (int i = (size-1); i >= 0; i--) {
        ptr[k] = i;
        k++;        
    }

}

void initOutput(int *ptr, int size) {
    for (int i = 0; i < size; i++) 
        ptr[i] = i;
}

void expect(int *buff) {
    expected = buff;
}

void equalPtr(void) {
    sort(buffer, BUFF_LEN);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, buffer, BUFF_LEN);
}

TEST_GROUP(sort);

TEST_SETUP(sort) {
    initBuffer(buffer, BUFF_LEN);
    initOutput(out, BUFF_LEN);
}

TEST_TEAR_DOWN(sort)
{
}

TEST(sort, TestEqual) {
    expect(out);
    equalPtr();
}
