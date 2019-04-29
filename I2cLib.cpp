// I2CLib.cpp
// 2019.04.26
// dongjin.kim@lulu-lab.com
#include <iostream>
#include "I2cLib.h"

int I2CLinkM::init(usbDevice_t* dev, uint8_t slaveAddr) {
  dev_ = nullptr;
  return linkm_open(&dev_);
}

int I2CLinkM::scan(char* result) {
  int saddr = 0;
  int err;
  uint8_t buffer[65];  // room for dummy report ID  (this will go away soon?)
  uint8_t cmdbuf[64];  // blinkm command buffer
  uint8_t recvbuf[64];
  for (int i = 0; i < 7; i++) {
    saddr = i * 16 + 1;
    cmdbuf[0] = saddr;    // start address: 01
    cmdbuf[1] = saddr + 16; // end address:   16 // FIXME: allow arbitrary
    err = linkm_command(dev_, LINKM_CMD_I2CSCAN, 2, 16, cmdbuf, recvbuf);
    if (err) {
      std::cerr << "Error : " << linkm_error_msg(err) << std::endl;
    }
    else {
      hexdump("recvbuf:", recvbuf, 16);
      int cnt = recvbuf[0];
      if (cnt != 0) {
        for (int i = 0; i < cnt; i++) {
          printf("device found at address %d\n", recvbuf[1 + i]);
        }
      }
    }
  }
  return 0;
}

int I2CLinkM::readByteAddr(uint8_t  addr, char* buf) {
  return 0;
}

int I2CLinkM::writeByteAddr(uint8_t  addr, char* buf) {
  return 0;
}

int I2CLinkM::readWordAddr(uint16_t  addr, char* buf) {
  return 0;
}

int I2CLinkM::writeWordAddr(uint16_t  addr, char* buf) {
  return 0;
}
