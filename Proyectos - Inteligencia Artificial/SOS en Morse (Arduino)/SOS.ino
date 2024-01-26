#define LED 6 
#define SONIDO 5


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SONIDO, OUTPUT);

}

void loop() {

    digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);

  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(2000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(2000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(2000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);

  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);
  digitalWrite(LED, HIGH);
  tone(SONIDO, 100);
  delay(1000);
  digitalWrite(LED, LOW);
  noTone(SONIDO);
  delay(250);


}
