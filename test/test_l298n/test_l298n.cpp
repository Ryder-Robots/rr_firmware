#include <Arduino.h>
#include <unity.h>
#include <PinLayout.h>
#include <l298n.hpp>

void test_drive_motors1()
{
    rrfw::L298 l298 = rrfw::L298(
        M1_U1_ENA, M1_U1_ENB, M1_U1_IN1, M1_U1_IN2, M1_U1_IN3, M1_U1_IN4
    );
    TEST_ASSERT_EQUAL(1,1);
}


void setup()
{
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_drive_motors1);
    UNITY_END();
}

void loop()
{
    delay(1000);
}