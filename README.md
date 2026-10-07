# Two-Bin Revolution: Dry and Wet Waste Segregation

An automated waste segregation system designed to separate dry and wet waste into distinct compartments using microcontrollers and sensor feedback.

## Project Overview
Improper waste segregation leads to severe environmental degradation and lost recycling potential. This project automates source segregation to optimize municipal solid waste management, directly aligning with Sustainable Development Goals (SDG 11: Sustainable Cities & SDG 12: Responsible Consumption).

## Key Features & Working Mechanism
- **Automated Detection:** Uses an IR sensor to detect waste placement on the sorting flap.
- **Moisture-Based Sorting:** Utilizes a soil moisture sensor to dynamically differentiate between organic (wet) and non-organic (dry) waste.
- **Proximity Lids:** Features an HC-SR04 Ultrasonic sensor to detect approaching hands and trigger automatic lid movement.
- **Servo Actuation:** SG90 servo motors control the sorting flap mechanism and lid opening/closing sequence.

## Hardware & Components
- **Microcontroller:** Arduino Uno
- **Sensors:** Soil Moisture Sensor, HC-SR04 Ultrasonic Sensor, IR Sensor
- **Actuators:** SG90 Servo Motors (x3)
- **Power Supply:** 5V USB / External Adapter
