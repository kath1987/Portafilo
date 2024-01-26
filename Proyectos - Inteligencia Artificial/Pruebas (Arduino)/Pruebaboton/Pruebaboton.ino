#include <avr/sleep.h>
#define button 4 //Conecte el boton en D4

int button_state = 0; //la variable que lee las pulsasiones del boton

void setup(){
    Serial.begin(9600);
    //Inicializo el pushbutton pin con un input
    pinMode(button, INPUT);
}

void loop(){
      //lee el estado de las pulsaciones del boton
      button_state = digitalRead(button);

      if (button_state == HIGH) {
        Serial.println("Button Pressed!!");
      }
  delay(50);
  stop();
}

void stop(){
  set_sleep_mode( SLEEP_MODE_PWR_DOWN );
  sleep_enable();
  noInterrupts(); //nunca será despertada
  sleep_cpu();
}