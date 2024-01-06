
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CPU: ");
  lcd.setCursor(0, 1);
  lcd.print("Memory unused: ");
  lcd.setCursor(0, 2);
  lcd.print("Memory usage: ");

  Serial.begin(9600);
}

void loop() {
  String data = "";
  while (Serial.available() > 0) {
    char incomingChar = Serial.read();
    data += incomingChar;
    delay(5);
  }

  int cpu_index = data.indexOf("CPU:");
  String cpu_value = data.substring(cpu_index, data.indexOf("|", cpu_index));
  lcd.setCursor(0, 0);
  lcd.print(cpu_value);
  lcd.setCursor(8, 0);
  lcd.print("%");

  int memory_unused_index = data.indexOf("Memory unused: ");
  String memory_unused_value = data.substring(memory_unused_index, data.indexOf(" Gb", memory_unused_index));
  lcd.setCursor(0, 1);
  lcd.print(memory_unused_value);
  lcd.setCursor(18, 1);
  lcd.print("Gb");

  int memory_usage_index = data.indexOf("Memory usage: ");
  String memory_usage_value = data.substring(memory_usage_index, data.indexOf(" Gb", memory_usage_index));
  lcd.setCursor(0, 2);
  lcd.print(memory_usage_value);
  lcd.setCursor(18, 2);
  lcd.print("Gb");
}
