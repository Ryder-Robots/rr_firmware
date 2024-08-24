#include <Arduino.h>
#include <unity.h>
#include <rr_isr.hpp>


void test_isr_l298n() 
{
    TEST_ASSERT_EQUAL(1,1);
}

void setup()
{
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_isr_l298n);
    UNITY_END();
}

void loop()
{
    delay(1000);
}