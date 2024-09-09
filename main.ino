#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

#define TFT_CS 10
#define TFT_DC 9

Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC);

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme;

void setup() {
  tft.begin();
  tft.fillScreen(HX8357_BLACK);
  tft.setRotation(1);
  
  tft.setCursor(0, 0);
  tft.setTextSize(3.5);

  // Setup console at 9600 bauds
  Serial.begin(9600);

  tft.setTextColor(HX8357_WHITE);

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() {
  // Read data from BME680 and display results to HX8357 every 5 seconds
  delay(5000);
  if (!bme.performReading()) { 
    Serial.println("Failed to perform reading");
  } else {
    Serial.println("Measuring...");

    // Reset screen
    tft.fillScreen(HX8357_BLACK);
    tft.setCursor(0, 0);

    // Display Temperature
    Serial.print("Temperature = "); Serial.print(bme.temperature); Serial.println(" °C");
    tft.print("Temperature: "); tft.print(bme.temperature - 10); tft.println(" *C");

    // Display Pressure
    Serial.print("Pressure = "); Serial.print(bme.pressure / 100.0); Serial.println(" hPa");
    tft.print("Pressure: "); tft.print(bme.pressure / 100); tft.println(" hPa");

    // Display Humidity
    Serial.print("Humidity = "); Serial.print(bme.humidity); Serial.println(" %");
    tft.print("Humidity: "); tft.print(bme.humidity); tft.println(" %");

    // Display gas
    Serial.print("Gas = "); Serial.print(bme.gas_resistance / 1000.0); Serial.println(" KOhms");
    tft.print("Gas = "); tft.print(bme.gas_resistance / 1000.0); tft.println(" KOhms");

    // Display altitude
    Serial.print("Approx. Altitude = "); Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA)); Serial.println(" m");
    tft.print("Altitude = "); tft.print(bme.readAltitude(SEALEVELPRESSURE_HPA)); tft.println(" m");

    tft.println();
    Serial.println();  
  }
}
