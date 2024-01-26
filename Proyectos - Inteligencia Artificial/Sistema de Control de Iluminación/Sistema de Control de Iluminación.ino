#include "Arduino_SensorKit.h"
#define LED 6
int light_sensor = A3; 
#define BUZZER 5
int minimo = 10;
int maximo = 73;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600); 
  Oled.begin();
  Oled.setFlipMode(true);

}

void loop() {


  int raw_light = analogRead(light_sensor);
  int light = map(raw_light, 0, 1023, 0, 100);
  Serial.print("Light level: ");
  Serial.println(light);

  digitalWrite(LED, HIGH);
  Oled.clearDisplay();  // Borra la pantalla antes de escribir nuevo contenido
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 33);
  Oled.print("Perfecto");
  Oled.refreshDisplay();

  if(light >= maximo){
     digitalWrite(LED, LOW);
     Oled.setFont(u8x8_font_chroma48medium8_r);
     Oled.setCursor(0, 33);
     Oled.print("DEMASIADA LUZ!!!"); 
     Oled.refreshDisplay();

    delay(1000);  

  }if(light <= minimo){
      digitalWrite(LED, HIGH);
      tone(BUZZER, 100);
      Oled.setFont(u8x8_font_chroma48medium8_r);
      Oled.setCursor(0, 33);
      Oled.clearDisplay();
      Oled.print("NECESITO LUZ!!"); 
      Oled.refreshDisplay();        
      delay(250);
      Oled.setFont(u8x8_font_chroma48medium8_r);
      Oled.setCursor(0, 33);
      Oled.clearDisplay();
      Oled.print("NECESITO LUZ!!"); 
      Oled.refreshDisplay();  
      digitalWrite(LED, LOW);
      noTone(BUZZER);
      delay(250);
  

    }

  delay(1000);

}
