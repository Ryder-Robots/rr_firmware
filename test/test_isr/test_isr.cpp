#include <Arduino.h>
#include <unity.h>
#include <rr_isr.hpp>


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
    rrfw::setup_isr();
    RUN_TEST(test_isr_l298n);
    UNITY_END();
}

void loop()
{
    delay(1000);
}