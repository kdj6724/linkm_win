#pragma once

#include <stdint.h>
extern "C" {
#include "LinkM/linkm-lib.h"
}

class I2CBase {
public:
  virtual int init(usbDevice_t* dev, uint8_t slaveAddr) = 0;
  virtual int scan(char* result) = 0;
  virtual int readByteAddr(uint8_t  addr, char* buf) = 0;
  virtual int writeByteAddr(uint8_t  addr, char* buf) = 0;
  virtual int readWordAddr(uint16_t  addr, char* buf) = 0;
  virtual int writeWordAddr(uint16_t  addr, char* buf) = 0;
};

class I2CLinkM : public I2CBase {
public:
  virtual int init(usbDevice_t* dev, uint8_t slaveAddr);
  virtual int scan(char* result);
  virtual int readByteAddr(uint8_t  addr, char* buf);
  virtual int writeByteAddr(uint8_t  addr, char* buf);
  virtual int readWordAddr(uint16_t  addr, char* buf);
  virtual int writeWordAddr(uint16_t  addr, char* buf);
private:
  usbDevice_t *dev_;
};