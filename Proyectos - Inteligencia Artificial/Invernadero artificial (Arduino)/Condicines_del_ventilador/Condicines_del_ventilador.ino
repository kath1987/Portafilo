int fan = 12;  // El ventilador
int temperatureSensor = A0;  

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(temperatureSensor, INPUT);
}

void loop() {
  int temperature = analogRead(temperatureSensor);
  float celsius = (temperature / 1024.0) * 5.0 * 100.0;

  // Si la temperatura supera el limite, encender el ventilador
  if (celsius > 25.0) {  
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(fan, LOW);
  }

  delay(5000);  
}
