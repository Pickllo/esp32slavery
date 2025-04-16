# ESPHome I²C Slave Handler

A custom ESPHome component for exposing sensor states (like motion, contact, and LD2410 presence) over I²C as a slave device.

## Installation

```yaml
external_components:
  - source: github://Pickllo/esp32slavery
    components: [i2c_slave_handler]
```

## Configuration

```yaml
i2c_slave_handler:
  motion1: motion1
  motion2: motion2
  contact: contact
  presence: presence
```

## Esp32 slave yaml example
```yaml
esphome:
  name: esp32_slave

esp32:
  board: esp32dev

external_components:
  - source: github://Pickllo/esp32slavery
    components: [i2c_slave_handler]

# UART for LD2410C
uart:
  rx_pin: GPIO16
  tx_pin: GPIO17
  baud_rate: 256000
  id: uart_bus

ld2410:
  uart_id: uart_bus
  id: ld2410_sensor
  timeout: 5s

# Binary Sensors
binary_sensor:
  - platform: ld2410
    has_target:
      name: Presence
      id: presence
      filters:
        - delayed_off: 10s

    has_moving_target:
      name: "Moving Target LD2410C"
      id: moving_target
      disabled_by_default: True

    has_still_target:
      name: Still Target
      id: still_target

  - platform: gpio
    pin: GPIO12
    name: "Motion Sensor 1"
    id: motion1
  - platform: gpio
    pin: GPIO13
    name: "Motion Sensor 2"
    id: motion2
  - platform: gpio
    pin: GPIO14
    name: "Contact Sensor"
    id: contact

# Register the I2C slave logic component
i2c_slave_handler:
  motion1: motion1
  motion2: motion2
  contact: contact
  presence: presence
esphome:
  name: esp32_slave
  includes:
    - i2c_slave_handler.h  # Your custom class goes here

esp32:
  board: esp32dev

external_components:
  - source: local
    components: [i2c_slave_handler]

# UART for LD2410C
uart:
  rx_pin: GPIO16
  tx_pin: GPIO17
  baud_rate: 256000
  id: uart_bus

ld2410:
  uart_id: uart_bus
  id: ld2410_sensor
  timeout: 5s

# Binary Sensors
binary_sensor:
  - platform: ld2410
    has_target:
      name: Presence
      id: presence
      filters:
        - delayed_off: 10s
    has_moving_target:
      name: "Moving Target LD2410C"
      id: moving_target
      disabled_by_default: True
    has_still_target:
      name: Still Target
      id: still_target

  - platform: gpio
    pin: GPIO12
    name: "Motion Sensor 1"
    id: motion1
  - platform: gpio
    pin: GPIO13
    name: "Motion Sensor 2"
    id: motion2
  - platform: gpio
    pin: GPIO14
    name: "Contact Sensor"
    id: contact

# Register the I2C slave logic component
i2c_slave_handler:
  motion1: motion1
  motion2: motion2
  contact: contact
  presence: presence
```
