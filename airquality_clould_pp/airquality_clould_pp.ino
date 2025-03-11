  #include <TFT_eSPI.h>
  #include <Multichannel_Gas_GMXXX.h>
  #include <Wire.h>
  #include "Grove_Temperature_And_Humidity_Sensor.h"



  #define LIGHTGREEN tft.color565(144, 238, 144)
  #define DARKBLUE tft.color565(0, 0, 139)
  #define GREY tft.color565(128,128,128)



  // Initialize Display
  TFT_eSPI tft = TFT_eSPI();

  // Initialize Gas Sensor
  GAS_GMXXX<TwoWire> gas;

  // Define DHT Sensor
  #define DHTTYPE DHT22
  #define DHTPIN 0
  DHT dht(DHTPIN, DHTTYPE);

  void setup() {
      Serial.begin(115200);
      Wire.begin();

      // Initialize Sensors
      dht.begin();
      gas.begin(Wire, 0x08);

      Serial.println("Sensors Initialized Successfully");

      // Initialize Display
      tft.init();
      tft.setRotation(3);
      tft.fillScreen(GREY);
  }

  void loop() {
      float temp_hum_val[2] = {0};

      // Read Temperature & Humidity
      int temperature = 0, humidity = 0;
      if (!dht.readTempAndHumidity(temp_hum_val)) {
          humidity = (int)temp_hum_val[0];
          temperature =(int) temp_hum_val[1];
      } else {
          Serial.println("Failed to read temperature & humidity!");
      }

      // Read Gas Sensor Data
      int NO2_val = gas.getGM102B();     
      int Ethanol_val = gas.getGM302B();  
      int VOC_val = gas.getGM502B();      
      int CO_val = gas.getGM702B();       

      // Update Serial Monitor
      Serial.print("Humidity: "); Serial.print(humidity);
      Serial.print(" | Temperature: "); Serial.print(temperature);
      Serial.print(" | NO2: "); Serial.print(NO2_val);
      Serial.print(" | Ethanol: "); Serial.print(Ethanol_val);
      Serial.print(" | VOC: "); Serial.print(VOC_val);
      Serial.print(" | CO: "); Serial.println(CO_val);

      // UI Colors
      uint16_t bgColor = TFT_WHITE;
      uint16_t boxColor = DARKBLUE;
      uint16_t textColor = TFT_WHITE;
      uint16_t highlightColor = TFT_YELLOW;

      // Air Quality Box (Left)
      int aqBoxX = 10, aqBoxY = 45, aqBoxWidth = 110, aqBoxHeight = 190;
      tft.fillRoundRect(aqBoxX, aqBoxY, aqBoxWidth, aqBoxHeight, 5, boxColor);
      tft.drawRoundRect(aqBoxX, aqBoxY, aqBoxWidth, aqBoxHeight, 5, TFT_WHITE);

      // Sensor Boxes (Right)
      int boxX = 125, boxWidth = 130, boxHeight = 43;
      int startY = 45, spacing = 50;
      for (int i = 0; i < 4; i++) {
        int boxY = startY + (i*spacing);
        tft.fillRoundRect(boxX, boxY , boxWidth, boxHeight, 5, boxColor);
        tft.drawRoundRect(boxX, boxY , boxWidth, boxHeight, 5, TFT_BLACK);
      }

      // Labels
      tft.setTextColor(textColor, bgColor);
      tft.setTextSize(2);
      // Air Qualoity heding
      tft.setCursor(70,14);
      tft.setTextColor(TFT_GREEN);
      tft.print("AIR QUALITY");

      // Air Quality Box Text
      // Dynamically Position Text Inside Boxes
      tft.setCursor(aqBoxX + 15, aqBoxY + 12);  tft.setTextColor(highlightColor);  tft.print("VOC:");
    
      tft.setCursor(aqBoxX + 35, aqBoxY + 50);  tft.print(VOC_val);

      tft.setCursor(aqBoxX + 15, aqBoxY + 110);  tft.setTextColor(LIGHTGREEN);  tft.print("CO:");
      tft.setCursor(aqBoxX + 35, aqBoxY + 150);  tft.println(CO_val);

      // Dynamically Set Sensor Values (Right)
      tft.setTextColor(TFT_WHITE);
      tft.setCursor(boxX + 10, startY + 12);  tft.print("Temp: ");   tft.print(temperature); 
      tft.setCursor(boxX + 10, startY + spacing + 12);  tft.print("NO2: ");    tft.print(NO2_val);
      tft.setCursor(boxX + 10, startY + 2 * spacing + 12);  tft.print("Humid: ");  tft.print(humidity);
      tft.setCursor(boxX + 10, startY + 3 * spacing + 12);  tft.print("Ethyl: ");  tft.print(Ethanol_val);

      // Update every 2 seconds
      delay(2000);
  }
