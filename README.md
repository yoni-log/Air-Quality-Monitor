# Air-Quality-Monitor
This project reads environmental data from the Adafruit BME680 sensor (temperature, humidity, pressure, and gas resistance) and displays the results on an Adafruit HX8357 TFT display. The BME680 provides a general measurement while the TFT display presents the data visually in real time.

![image](https://github.com/user-attachments/assets/0b592db6-2930-4480-b677-8b8a6aa4e905)


# Components Required
* [Adafruit BME680 Sensor](https://www.adafruit.com/product/3660) for temperature, humidity, pressure, and gas resistance readings.
* [Adafruit HX8357 TFT Display](https://www.adafruit.com/product/2050) to display the readings.
* [Arduino UNO R4 WiFi](https://store.arduino.cc/products/uno-r4-wifi?srsltid=AfmBOopsrTVr2Wu2aufC8ew_nKGLE6WfVniRG4TY9pK96xlD95lN9TCA) or similar if compatible.
* USB-C to USB-A or any if compatible with Arduino.
  * The UNO R4 WiFi has one USB-C port.
* Jumper wires
* Soldering tool

# Assembly
* Connect all jumper wires to correct locations indicated by the picture above.
* Solder the wires into the microcontrollers.
* Download and install Arduino IDE [here](https://www.arduino.cc/en/software).
* Download and install libraries listed below.
* Set your serial baud rate to 9600.
* Upload `main.ino` to the Arduino.

# Libraries Used
* Wire.h: Used for I2C communication.
* SPI.h: Used for SPI communication with the TFT display.
* Adafruit_Sensor.h: Core sensor library for Adafruit sensors.
* Adafruit_BME680.h: Library to interface with the BME680 sensor.
* Adafruit_GFX.h: Graphics library for drawing on the display.
* Adafruit_HX8357.h: Library for controlling the HX8357 TFT display.

# Features
* Real-Time Environmental Monitoring: Continuously measures temperature, humidity, pressure, and gas resistance using the Adafruit BME680 sensor.
* Visual Data Display: Displays real-time environmental data on the Adafruit HX8357 TFT screen for immediate feedback.
* Serial Console Output: Sensor readings are printed to the serial console, allowing for additional monitoring or debugging via the Arduino IDE.

# Features Planned
* WiFi Connectivity: Utilize the Arduino UNO R4 WiFi capabilities to send sensor data to a remote server or cloud service for real-time monitoring.
  * Mobile App Integration: Develop a companion app that allows users to access real-time environmental data remotely via their smartphone or tablet. Users can monitor temperature, humidity, and other sensor data from anywhere.
* Graphic Visualizations: Implement graphical charts on the TFT display to visualize trends in temperature, humidity, and other readings.
