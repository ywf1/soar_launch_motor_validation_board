# soar_launch_motor_validation_board
PCB and Arduino Code for a data logging board for collecting data on solid rocket force and pressure output, along with GPIO for triggering ignition and testing

Sensor Inputs:
-  Load Cell
-  Pressure Sensor

Load Cell:
-  +10V excitation
-  20mV @ max Load (1000 N)

Pressure Sensor:
-  0 - 1600 PSI input
-  .5V - 4.5V voltage output

Board specs:
-  Teensy 4.1 MCU
-  INA823 Instrumental Amplifier
-  MCP3202T 12-bit, 2 Channel, 50ksps
-  Dual 3.3V, 5V LDO power bus
-  Accesible GPIO

Schematic:

