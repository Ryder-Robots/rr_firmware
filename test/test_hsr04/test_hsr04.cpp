#include <Arduino.h>
#include <unity.h>
#include <hsr04.hpp>

void test_hsr04()
{
    rrfw::RrOpStorage tx = rrfw::RrOpStorage(RR_CMD_U4, 0, {});
    TEST_ASSERT_EQUAL(1,1);
}

void setup()
{
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_hsr04);
    UNITY_END();
}

void loop()
{
}