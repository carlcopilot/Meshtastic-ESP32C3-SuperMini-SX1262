#ifndef _VARIANT_DIY_C3_LR30_H_
#define _VARIANT_DIY_C3_LR30_H_

// --- Definiciones básicas del ESP32-C3 SuperMini ---
#define BUTTON_PIN 9   
#define LED_PIN 8      

// --- CONFIGURACIÓN LORA (DX-LR30 / SX1262) ---
#define USE_SX1262

// Definiciones Estándar (Las que tú y yo entendemos)
#define LORA_SCK 4
#define LORA_MISO 5
#define LORA_MOSI 6
#define LORA_CS 7

#define LORA_DIO1 3
#define LORA_BUSY 2
#define LORA_RESET 10

// --- CORRECCIÓN DE ERRORES (Lo que pide el compilador) ---
// Aquí le decimos al código: "Cuando busques SX126X_CS, usa LORA_CS"
#define SX126X_CS    LORA_CS
#define SX126X_DIO1  LORA_DIO1
#define SX126X_BUSY  LORA_BUSY
#define SX126X_RESET LORA_RESET

// Si NO usas pantalla, dejamos esto como -1
#define I2C_SDA -1
#define I2C_SCL -1

#endif