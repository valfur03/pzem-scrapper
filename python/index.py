from pymodbus.client.sync import ModbusSerialClient as ModbusClient
from pymodbus.transaction import ModbusRtuFramer

client = ModbusClient(method="rtu", port="/dev/ttyUSB0", timeout=1, baudrate=9600)
client.connect()
rr = client.read_input_registers(0, 10, unit=0x0001)
print('Voltage : {}V'.format(rr.getRegister(0) / 10))
print('Power : {}W'.format((rr.getRegister(3) + (rr.getRegister(4) << 16)) / 10))