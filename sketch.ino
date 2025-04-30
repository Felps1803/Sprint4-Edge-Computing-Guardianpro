#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Pinos
#define DHTPIN 2          // Pino do sensor DHT11
#define DHTTYPE DHT11
#define LEDPIN 13          // LED
#define BUZZERPIN 12      // Buzzer

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lastPublishTime = 0;
const unsigned long publishInterval = 5000;

void setup() {
  Serial.begin(9600);

  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");

  dht.begin();
  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();

  // Envia dados a cada 5 segundos
  if (currentMillis - lastPublishTime >= publishInterval) {
    lastPublishTime = currentMillis;

    float temp = dht.readTemperature();
    if (!isnan(temp)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temp);
      lcd.print(" C");

      // Envia temperatura como JSON pela Serial
      String json = "{\"temperatura\":" + String(temp) + "}";
      Serial.println(json);

      // Sinaliza febre
      if (temp > 37.5) {
        digitalWrite(LEDPIN, HIGH);
        digitalWrite(BUZZERPIN, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("ALERTA FEBRE!");
      } else {
        digitalWrite(LEDPIN, LOW);
        digitalWrite(BUZZERPIN, LOW);
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Erro leitura");
    }
  }

  // Verifica comandos pela Serial
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    lcd.clear();
    if (comando == "FRONTEND:GET") {
      lcd.setCursor(0, 0);
      lcd.print("Front-end");
      lcd.setCursor(0, 1);
      lcd.print("requisitou dado");
    } else if (comando == "BACKEND:POST") {
      lcd.setCursor(0, 0);
      lcd.print("Dado enviado");
      lcd.setCursor(0, 1);
      lcd.print("ao back-end");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Comando invalido");
    }
  }
}
