import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID

CONF_MOTION1 = "motion1"
CONF_MOTION2 = "motion2"
CONF_CONTACT = "contact"
CONF_PRESENCE = "presence"

i2c_slave_handler_ns = cg.esphome_ns.namespace("i2c_slave_handler")
I2CSlaveHandler = i2c_slave_handler_ns.class_("I2CSlaveHandler", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(I2CSlaveHandler),
    cv.Required(CONF_MOTION1): cv.use_id(binary_sensor.BinarySensor),
    cv.Required(CONF_MOTION2): cv.use_id(binary_sensor.BinarySensor),
    cv.Required(CONF_CONTACT): cv.use_id(binary_sensor.BinarySensor),
    cv.Required(CONF_PRESENCE): cv.use_id(binary_sensor.BinarySensor),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    motion1 = await cg.get_variable(config[CONF_MOTION1])
    motion2 = await cg.get_variable(config[CONF_MOTION2])
    contact = await cg.get_variable(config[CONF_CONTACT])
    presence = await cg.get_variable(config[CONF_PRESENCE])
    cg.add(var.set_motion1(motion1))
    cg.add(var.set_motion2(motion2))
    cg.add(var.set_contact(contact))
    cg.add(var.set_presence(presence))