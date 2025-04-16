#pragma once
#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include <Wire.h>

namespace esphome {
namespace i2c_slave_handler {

class I2CSlaveHandler : public Component {
 public:
  void set_motion1(binary_sensor::BinarySensor *sensor) { motion1_ = sensor; }
  void set_motion2(binary_sensor::BinarySensor *sensor) { motion2_ = sensor; }
  void set_contact(binary_sensor::BinarySensor *sensor) { contact_ = sensor; }
  void set_presence(binary_sensor::BinarySensor *sensor) { presence_ = sensor; }

  void setup() override;
  void loop() override;

  static void requestEvent();

 protected:
  static I2CSlaveHandler *instance_;
  binary_sensor::BinarySensor *motion1_;
  binary_sensor::BinarySensor *motion2_;
  binary_sensor::BinarySensor *contact_;
  binary_sensor::BinarySensor *presence_;
};

}  // namespace i2c_slave_handler
}  // namespace esphome