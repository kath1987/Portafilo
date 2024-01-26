
#define piezoelectrico 5

void setup(){

  pinMode(piezoelectrico, OUTPUT);
}

void loop(){
  tone(piezoelectrico, 100);
  delay(1000);
  noTone(piezoelectrico);
  delay(1000);
}





