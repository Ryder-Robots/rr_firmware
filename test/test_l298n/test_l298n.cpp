#include <Arduino.h>
#include <unity.h>
#include <PinLayout.h>
#include <l298n.hpp>

void test_drive_motors1()
{
    rrfw::L298 l298 = rrfw::L298(
        M1_U1_ENA, M1_U1_ENB, M1_U1_IN1, M1_U1_IN2, M1_U1_IN3, M1_U1_IN4
    );
    uint8_t mflags = 0 | RR_MOTOR_FLAG_IN1 | RR_MOTOR_FLAG_IN3;
    TEST_ASSERT_EQUAL(5, mflags);

    const uint8_t data[] = {mflags, 125, 125};
    rrfw::RrOpStorage bytes = rrfw::RrOpStorage(RR_CMD_U1, 3, data);

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