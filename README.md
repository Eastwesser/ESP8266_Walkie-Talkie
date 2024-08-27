# ESP8266 WiFi Walkie-Talkie
**ESP8266 WiFi Walkie-Talkie** is a project that allows you to create a simple walkie-talkie using ESP8266 modules with Wi-Fi communication between two devices. The project includes using **DFPlayer Mini** to play sound signals upon connection.

## Description
The project is divided into two parts:

- Access Point (AP): One ESP8266 device acts as an access point, to which the other device (Client) connects.
- Client: The second ESP8266 device connects to the Access Point and can send and receive messages, while playing sound signals.

## Hardware Required
- 2 ESP8266 boards
- 2 DFPlayer Mini modules
- Piezo buzzers or small speakers
- SD cards for storing MP3 files
- Wires and resistors
- Power supply for the ESP8266

## Wiring
DFPlayer Mini:
- RX connects to D5 on the ESP8266
- TX connects to D6 on the ESP8266
- VCC and GND connect to power

## Libraries Used
- ESP8266WiFi — Built-in library for Wi-Fi functionality on the ESP8266.
- SoftwareSerial — Built-in library to create additional software serial ports.
- DFPlayerMini_Fast — A library for interacting with the DFPlayer Mini module.

## Installation
### 1. Setting Up the Environment
- Ensure that you have the latest version of Arduino IDE installed.
- Set up your development environment for the ESP8266 by installing the ESP8266 board support.

### 2. Installing Libraries
- To work with this project, you will need the following libraries:
- DFPlayerMini_Fast: This can be installed via the Library Manager in Arduino IDE.

### 3. Uploading the Code
- Download or clone the project repository.
- Open esp_walkie_talkie_ap.ino for the Access Point device, and esp_walkie_talkie_cli.ino for the Client device in Arduino IDE.
- Connect your ESP8266 boards to your computer.
- Select the appropriate board and port in Arduino IDE.
- Upload the corresponding code to each board.

## Usage
- Load the esp_walkie_talkie_ap.ino code onto the first ESP8266, which will act as the Access Point.
- Load the esp_walkie_talkie_cli.ino code onto the second ESP8266, which will act as the Client.
- The devices will automatically start communicating over Wi-Fi once connected.
- The DFPlayer Mini module will play a sound when a connection is established between the two devices.
