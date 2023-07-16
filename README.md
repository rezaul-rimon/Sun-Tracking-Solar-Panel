# Dual Axis Sun Tracking Solar Panel System

## Description
This project showcases a Dual Axis Sun Tracking Solar Panel system implemented with Arduino. The system tracks the sun in real-time to maximize solar energy capture and incorporates an automatic battery charge control system. It includes monitoring capabilities for panel and battery voltage, current, load current, and load power. The system also features a local data logging system, which saves real-time data such as solar voltage, current, servo motor position, etc. This data logging capability enables long-term recharge and performance analysis. The project utilizes Arduino Uno, a solar panel, 1602 LCD, ACS712 current sensor, voltage divider resistor for voltage measurement, MG-996R servo motor, relay for charge control, battery, LM2596 voltage regulator, micro SD card with SD card module, and other components.

## Features
- Sun Tracking: The system continuously tracks the sun's position in real-time for optimal solar energy capture.
- Automatic Battery Charge Control: Controls the charging of the battery based on the solar panel's output and the battery's status.
- Monitoring System: Monitors panel and battery voltage, current, load current, and load power to provide real-time information on the system's performance.
- Local Data Logging: Saves real-time data to a micro SD card, allowing for long-term recharge and performance analysis.
- User Interface: Displays relevant information, including solar voltage, current, servo motor position, battery status, and more on a 1602 LCD.

## Hardware Requirements
- Arduino Uno or compatible board
- Solar panel for energy capture
- 1602 LCD display for system information
- ACS712 current sensor for current measurement
- Voltage divider resistor for voltage measurement
- MG-996R servo motor for dual-axis sun tracking
- Relay for charge control
- Battery for energy storage
- LM2596 voltage regulator for voltage regulation
- Micro SD card with SD card module for data logging
- Connecting wires
- Other components as needed for your specific setup

## Software Requirements
- Arduino IDE (Integrated Development Environment)
- Libraries for LCD display, SD card, and any other specific sensors or components used in the project

## Installation and Setup
1. Clone the repository to your local machine using the following command: git clone https://github.com/rezaul-rimon/Sun-Tracking-Solar-Pane.git

2. Connect the required components, including the solar panel, LCD display, ACS712 current sensor, voltage divider resistor, servo motor, relay, battery, LM2596 voltage regulator, and SD card module, based on the provided schematic or pin connections in the code.

3. Open the Arduino IDE.

4. Open the Arduino sketch (.ino file) for the Dual Axis Sun Tracking Solar Panel system.

5. Install any required libraries for controlling the LCD display, SD card module, ACS712 current sensor, etc.

6. Upload the sketch to the Arduino board.

7. Power on the system and ensure all connections are properly made.

8. Calibrate and adjust the system parameters as necessary, such as voltage and current thresholds, servo motor movement, etc., based on your specific setup.

## Usage
1. Power on the system and position the solar panel in an open area.

2. The system will begin tracking the sun's position in real-time using the servo motor.

3. The LCD display will provide real-time information about solar voltage, current, servo motor position, battery status, and other relevant parameters.

4. The automatic battery charge control system will monitor the solar panel's output and battery status to ensure efficient charging and prevent overcharging.

5. The system will continuously log real-time data, including solar voltage, current, servo motor position, etc., to the micro SD card for long-term analysis.

6. Monitor the system's performance, battery status, and charging efficiency using the displayed information on the LCD.

7. Analyze the logged data from the micro SD card for long-term recharge and performance analysis.

## Contributing
Contributions to this project are welcome! If you have any suggestions, improvements, or encounter any issues, feel free to open an issue or submit a pull request.

## License
[MIT License](LICENSE)
