#include <Arduino.h>
#include <unity.h>
#include <stdlib.h>
#include <rr_isr.hpp>

void test_hsr04()
{
    rrfw::RrOpStorage tx = rrfw::RrOpStorage(RR_CMD_U4, 0, {});
    rrfw::RrOpStorage res = rrfw::ctl_isr(tx);

    int result = 0 | res._data[0] | res._data[1];
    Serial.println(result);
    TEST_ASSERT_EQUAL(1,1);
}

void test_isr_l298n() 
{
    uint8_t mflags = 0 | RR_MOTOR_FLAG_IN1 | RR_MOTOR_FLAG_IN3;
    uint8_t data[] = {mflags, 125, 235};
    rrfw::RrOpStorage tx = rrfw::RrOpStorage(RR_CMD_U1, 3, data);
    rrfw::ctl_isr(tx);
    delay(2000);
    TEST_ASSERT_EQUAL(1,1);
}

void setup()
{
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_isr_l298n);
    RUN_TEST(test_hsr04);
    UNITY_END();
}

void loop()
{
    delay(1000);
}