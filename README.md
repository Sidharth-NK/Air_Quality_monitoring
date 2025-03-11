# Air Quality Monitoring System  

## Overview  
This **Air Quality Monitoring System** measures and analyzes environmental air quality using a **DHT22 sensor**, a **Multichannel Gas Sensor**, and a **Wio Terminal**. The system collects data on temperature, humidity, and various gas concentrations to assess air pollution levels. 

**Disclaimer** - This github repository gives a brief idea on how to monitor the data on the wio terminal, the further IoT connectivity and dashboard analysis will be explained in another repository

## Features  
- **Temperature and humidity measurement** using **DHT22**.  
- **Gas concentration detection** (CO, NO₂, Ethanol, VOCs) using a **Multichannel Gas Sensor**.  
- **Wio Terminal as the processing unit** with a built-in display.  

## Components Used  
- **Wio Terminal** – Microcontroller with built-in display and Wi-Fi support.  
- **DHT22 Sensor** – Measures temperature and humidity.  
- **Multichannel Gas Sensor** – Detects multiple gases such as CO, NO₂, Ethanol, VOCs, etc.  
- **Grove Connectors** – For sensor connections.  
- **Power Source** – USB power supply for the Wio Terminal.  

## Wiring Connections  

| Sensor  | Wio Terminal Pin |
|---------|-----------------|
| DHT22 VCC  | 3.3V  |
| DHT22 GND  | GND  |
| DHT22 Data | Digital Pin (D1) |
| Gas Sensor VCC  | 3.3V |
| Gas Sensor GND  | GND |
| Gas Sensor SDA  | I2C SDA  |
| Gas Sensor SCL  | I2C SCL  |

![Connection diagram](https://github.com/user-attachments/assets/b7ba6670-3ae7-4e2c-b18b-1804b240b8db)
           
This wiring connections can be simplified by just using the grove connectors


## Software Requirements  
- **Arduino IDE**  
- **DHT Sensor Library** for temperature and humidity readings. [Link](https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor)
- **Seeed Studio Libraries** for Wio Terminal. [Setting up wio terminal in Arduino IDE](https://wiki.seeedstudio.com/Wio-Terminal-Getting-Started/)
- **Multichannel Gas Sensor Library** for gas detection. [Link](https://github.com/Seeed-Studio/Seeed_Multichannel_Gas_Sensor/archive/master.zip)

## Installation Steps  
1. **Set up Arduino IDE** and install the required libraries.  
2. **Connect the sensors** to the Wio Terminal as per the wiring table.  
3. **Upload the firmware** to the Wio Terminal.  
4. **Monitor real-time data** on the Wio Terminal display or send it to an IoT platform.  


## Expected Output  
- **Temperature & Humidity Readings** displayed on the Wio Terminal screen.  
- **Gas Concentration Levels** displayed with alerts if pollution is detected.  
- **Real-time updates** with IoT dashboard integration (if enabled).  

## Future Improvements  
- Use IoT connectivity using **lorawan**.
- Data analysis of the obtained readings using cloud interface 
- Implement **battery operation** for portability.  
- Enhance **data analytics & AI-based predictions** for air quality trends.

---

## License   
This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.


---

### Author  
📌 Developed by **[Sidharth N Krisnna]**  

