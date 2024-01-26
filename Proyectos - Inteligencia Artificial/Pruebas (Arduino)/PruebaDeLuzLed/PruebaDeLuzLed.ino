#define LED 6
int light_sensor = A3; 

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);//Se envia una corriente de 5 v por el pin digital
  delay(3000);
  digitalWrite(LED, LOW);//Se envia una corriente de 0 
  delay(1000);//La transicion entre las fases se controla con delay
}
