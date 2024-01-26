#include <avr/sleep.h>
int pontentiometer = A0; //lo conecte al pin A0
void setup(){

    Serial.begin(9600); // la velocidad de la comunicacion 
    pinMode(pontentiometer, INPUT);
}

void loop(){

    int sensor_value = analogRead(pontentiometer);
    int value = map(sensor_value, 0, 1023, 0, 100); //Mapea desde 0, 1023 a 0, 100
    Serial.print("Pontentiometer value: ");
    Serial.println(value);
    delay(500); //Se mostrara cada 1/2 segundo 
}

void stop() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Configura el modo de sueño como SLEEP_MODE_PWR_DOWN
  sleep_enable(); // Habilita el modo de sueño
  noInterrupts(); // Deshabilita las interrupciones, la CPU no se despertará por ninguna interrupción
  sleep_cpu(); // Pone la CPU en modo de bajo consumo de energía
}