int LDR=0;
int pjoven=0,padulta=0;
int conversion=0;
void setup() {
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(4)==HIGH){
    padulta=0;
    pjoven=1;
  }
  if(digitalRead(5)==HIGH){
    pjoven=0;
    padulta=1;
  }
  if(pjoven==1){
    analogWrite(13,LOW);
    plantajoven();
  }
  if(padulta==1){
    digitalWrite(3,LOW);
    plantaadulta();
  }
  delay(500);
}
void plantajoven(){
  Serial.println("Planta Joven");
  LDR=analogRead(A0);
  Serial.println(LDR);
  if(LDR>600){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
}
void plantaadulta(){
  Serial.println("planta adulta");
  LDR=analogRead( A0);
  conversion=780-LDR;
  Serial.println(LDR);
  analogWrite(13,conversion);
}
