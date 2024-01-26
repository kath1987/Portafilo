#define luz_sensor A3

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw_light = analogRead(luz_sensor);
  int luz = map(raw_light, 0, 1023, 0, 100);

  Serial.print("Cantidad de claridad: ");
  Serial.println(luz);

  delay(500);
}