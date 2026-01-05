# Meshtastic-ESP32C3-SuperMini-SX1262
<img src="https://meshtastic.org/design/logo/svg/Mesh_Logo_Black.svg" alt="Meshtastic Logo" width="200">
Configuración de pines, variante de PlatformIO y guía de conexión para crear un nodo Meshtastic de bajo consumo usando un ESP32-C3 SuperMini y el módulo LoRa DX-LR30 (SX1262).

## 🇪🇸 Descripción
Este repositorio contiene los archivos de configuración necesarios (`variant.h`, `pins_arduino.h` y `platformio.ini`) para compilar el firmware de **Meshtastic** en un nodo DIY construido con:
* **MCU:** ESP32-C3 SuperMini (Nologo/Genérico)
* **Radio LoRa:** DX-LR30 (SX1262) - (AliExpress: https://a.aliexpress.com/_EHXjuJI)

Esta combinación es económica, muy pequeña y eficiente energéticamente.

## 🇺🇸 Description
This repository hosts the necessary configuration files to compile **Meshtastic** firmware for a custom DIY node built with:
* **MCU:** ESP32-C3 SuperMini
* **LoRa Radio:** DX-LR30 (SX1262)

## 🔌 Wiring Guide / Conexiones

> **⚠️ WARNING:** The DX-LR30 module works at **3.3V**. Do not connect to 5V.

<img src="https://github.com/carlcopilot/Meshtastic-ESP32C3-SuperMini-SX1262/blob/main/esp32-C3%20Super%20mini%20pinout.jpeg?raw=true" alt="ESP32 C3 pinout" width="500">
<img src="https://github.com/carlcopilot/Meshtastic-ESP32C3-SuperMini-SX1262/blob/main/DX%20LR30%20Pinout.png?raw=true" alt="DX LR30 pinout" width="200">


| Function | DX-LR30 Pin | ESP32-C3 Pin (GPIO) | Notes |
| :--- | :--- | :--- | :--- |
| **Power** | VCC | 3.3V | |
| **Ground** | GND | GND | Common ground |
| **SPI Clock** | SCK | GPIO 4 | |
| **SPI Miso** | MISO | GPIO 5 | |
| **SPI Mosi** | MOSI | GPIO 6 | |
| **Chip Select** | NSS / CS | GPIO 7 | |
| **Reset** | RST | GPIO 10 | |
| **DIO1** | DIO1 | GPIO 3 | IRQ |
| **Busy** | BUSY | GPIO 2 | **Mandatory for SX1262** |

## 🛠️ How to Compile / Cómo Compilar

### Prerequisites / Requisitos
* Visual Studio Code
* PlatformIO Extension
* Git

### Steps / Pasos

1.  Clone the official Meshtastic firmware repository:
    ```bash
    git clone [https://github.com/meshtastic/firmware.git](https://github.com/meshtastic/firmware.git)
    cd firmware
    ```

2.  Create a new folder inside `variants`:
    * Path: `firmware/variants/diy_c3_lr30`

3.  Copy the files **`variant.h`** and **`pins_arduino.h`** from this repository into that new folder.

4.  Edit the `platformio.ini` file in the root of the firmware folder. Add the following environment block at the end:

    ```ini
    [env:diy-c3-lr30]
    extends = esp32c3_base
    board = esp32-c3-devkitm-1
    board_build.variants_dir = variants
    board_build.variant = diy_c3_lr30
    
    build_flags =
      ${esp32c3_base.build_flags}
      -DARDUINO_USB_MODE=1
      -DARDUINO_USB_CDC_ON_BOOT=1
      -I variants/diy_c3_lr30
    
    lib_deps =
      ${esp32c3_base.lib_deps}
    ```

5.  Open PlatformIO, select the environment `env:diy-c3-lr30`, **Clean**, and then **Upload**.

## 🐛 Troubleshooting / Solución de Problemas

* **Error: `SX126X_CS was not declared`**: This is fixed in the provided `variant.h` by mapping standard pin names to the specific variables required by the SX126x library driver.
* **Low RSSI (-120dBm)**: Check your antenna connection and ensure you are not testing without an antenna attached.
* **Compilation Error `pins_arduino.h not found`**: Ensure you copied the `pins_arduino.h` provided in this repo to the variant folder.

---
*Happy Meshing!*
