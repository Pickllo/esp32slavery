#include "i2c_slave_handler.h"

namespace esphome {
namespace i2c_slave_handler {

I2CSlaveHandler *I2CSlaveHandler::instance_ = nullptr;

void I2CSlaveHandler::setup() {
  Wire.begin(0x08);
  Wire.onRequest(I2CSlaveHandler::requestEvent);
  instance_ = this;
}

void I2CSlaveHandler::loop() {}

void I2CSlaveHandler::requestEvent() {
  if (instance_ == nullptr) return;
  uint8_t state = 0;
  state |= instance_->motion1_ && instance_->motion1_->state ? 0b0001 : 0;
  state |= instance_->motion2_ && instance_->motion2_->state ? 0b0010 : 0;
  state |= instance_->contact_  && instance_->contact_->state  ? 0b0100 : 0;
  state |= instance_->presence_ && instance_->presence_->state ? 0b1000 : 0;
  Wire.write(state);
}

}  // namespace i2c_slave_handler
}  // namespace esphome