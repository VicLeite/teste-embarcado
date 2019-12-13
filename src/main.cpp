#include <mbed.h>

DigitalOut led(LED1);

int main() {

  while(1) {
    led = true;
    wait(0.5);
    led = false;
    wait(0.5);
  }
}