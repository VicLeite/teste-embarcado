#include <mbed.h>
#include <unity.h>

DigitalOut led(LED2);

uint8_t i = 0;
uint8_t max_blinks = 5;

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(PA_5,LED2);
}

void test_led_state_high(void) {
    led = true;
    TEST_ASSERT_EQUAL(true, led);
}

void test_led_state_low(void) {
    led = false;
    TEST_ASSERT_EQUAL(false, led);
}


int main() {
    wait(2);

    UNITY_BEGIN();
    RUN_TEST(test_led_builtin_pin_number);


  while(1) {
    if (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        wait(0.5);
        RUN_TEST(test_led_state_low);
        wait(0.5);
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); 
    }
  }
}