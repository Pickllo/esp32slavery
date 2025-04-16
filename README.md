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
