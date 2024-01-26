void setup() {
  Serial.begin(9600);

}

void loop() {
    int soundValue = 0; //cree una variable para alamcenar 
      for (int i = 0; i < 32; i++) 
      { soundValue += analogRead(Sensor_sonido);  } 
    
      soundValue >>= 5; 
      Serial.println(soundValue); 
	
//if a value higher than 500 is registered, we will print the following
//this is done so that we can clearly see if the threshold is met
  if (soundValue > 500) { 
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");
  }
  delay(50); //a shorter delay between readings
}