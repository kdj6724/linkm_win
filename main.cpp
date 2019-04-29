
#include <memory>
#include <iostream>
#include "I2cLib.h"

int main(void) {
  usbDevice_t *dev = nullptr;
  std::unique_ptr<I2CBase> i2c(new I2CLinkM);
  i2c->init(dev, 0x33);
  i2c->scan(nullptr);
  return 0;
}