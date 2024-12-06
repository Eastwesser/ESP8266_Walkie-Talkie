# ESP8266 Walkie-Talkie SeRWaL

This project implements a simple walkie-talkie system using two ESP8266 boards. It uses UDP communication to transmit and receive audio data between the devices.

## Features
- Two-way audio communication.
- One ESP8266 acts as an **Access Point (Server)**.
- The other ESP8266 acts as a **Client**.
- Transmit audio using a microphone and play it back using a speaker.
- LED indication for transmitting/receiving status.

## Hardware Requirements
1. Two ESP8266 boards.
2. Electret microphone module (connected to `D1` pin).
3. Speaker or buzzer (connected to `D5` pin).
4. Push button (connected to `D6` pin).
5. LED for indication (connected to `D7` pin).

## Circuit Diagram
- Connect the microphone to the `D1` pin.
- Connect the speaker to the `D5` pin.
- Connect the button to the `D6` pin.
- Connect the LED to the `D7` pin with a 220-ohm resistor.

## Software Setup
1. Install the Arduino IDE.
2. Install the ESP8266 board support package in the Arduino IDE.
3. Load the `server.ino` file onto the **Server ESP8266**.
4. Load the `client.ino` file onto the **Client ESP8266**.

## Usage
1. Power on both devices.
2. The **Server ESP8266** creates a Wi-Fi network named `WalkieTalkieAP`.
3. The **Client ESP8266** connects to this network automatically.
4. Press the button on one device to transmit audio.
5. Release the button to receive audio from the other device.

## Notes
- Ensure both devices are within Wi-Fi range for communication.
- Adjust the microphone and speaker sensitivity if needed for better audio quality.
- Use `Serial Monitor` for debugging purposes.
