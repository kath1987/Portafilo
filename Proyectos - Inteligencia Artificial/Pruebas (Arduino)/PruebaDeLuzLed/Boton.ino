#define button 4 //Conecte el boton en D4

int button_state = 0; //la variable que lee las pulsasiones del boton

void setup(){
    Serial.begin(9600);
    //Inicializo el pushbutton pin con un input
    pinMode(button, INPUT);

}

void loop(){
      //lee el estado de las pulsaciones del boton
      button_state = ditigalRead(button);

      if (button_state == HIGH) {
        Serial.println("Button Pressed!!")
      }
  delay(50);
}