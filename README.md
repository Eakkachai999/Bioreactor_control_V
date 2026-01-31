# Bioreactor Control System (Arduino Mega 2560)

This project is an Arduino-based bioreactor control system designed for **Arduino Mega 2560**.  
The code controls key bioreactor conditions including **temperature, pH, and dissolved oxygen limits**, as well as related devices such as **circulation pumps, mixing pumps, and other process components**.

## Setup Instructions

1. Connect the Arduino Mega 2560 to your computer.
2. Open the code using **Arduino IDE**.
3. In the **first block of the code**, set all required **setpoints** according to your desired operating conditions.
4. After editing all setpoints, upload the code to the Arduino board via Arduino IDE.
5. Turn on the controller to start the bioreactor operation.

## Shutdown Procedure

After the fermentation process is completed:
1. Turn off the controller.
2. Disconnect the Arduino board from the computer.

⚠️ **Important:**  
Always verify sensor calibration and actuator connections before starting the bioreactor.
