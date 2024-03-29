# soar_launch_motor_validation_board
PCB and Arduino Code for a data logging board for collecting data on solid rocket force and pressure output, along with GPIO for triggering ignition and testing

Sensor Inputs:
-  Load Cell
-  Pressure Sensor

[Load Cell](https://www.tgloadcells.com/products/tjh-4a-pancake-load-cell/):
-  +10V excitation
-  20mV @ max Load (1000 N)

[Pressure Sensor](https://www.rocketmotorparts.com/details/p1577809_21906261.aspx):
-  0 - 1600 PSI input
-  .5V - 4.5V voltage output

Board specs:
-  [Teensy 4.1 MCU](https://www.pjrc.com/store/teensy41.html)
-  [INA823 Instrumental Amplifier](https://www.ti.com/product/INA823?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=INA823&ds_k=INA823&DCM=yes&gad_source=1&gclid=Cj0KCQiAoKeuBhCoARIsAB4WxtcPaApMLNnKOuGF0fya7Qy3El9pm-ohKC3AlAP7697QAOL5JRwLc-kaApGQEALw_wcB&gclsrc=aw.ds)
-  [MCP3202T 12-bit, 2 Channel, 50ksps](https://www.microchip.com/en-us/product/mcp3202)
-  Dual 3.3V, 5V LDO power bus
-  Accessible GPIO
  
Schematic:
![image](https://github.com/ywf1/soar_launch_motor_validation_board/assets/115194344/ea3f6fa7-ea23-4dfd-9221-333ebd4f0312)

Picture:
![image](https://github.com/ywf1/soar_launch_motor_validation_board/assets/115194344/154c0009-7201-49b2-97bd-0942dde5032f)




