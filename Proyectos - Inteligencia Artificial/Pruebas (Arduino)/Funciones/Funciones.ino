#define BUTTON 4
#define LED 6
#define SONIDO A2
#define potentiometer A0
#define BUZZER_PIN 5

#define Environment 12
// Duración de cada nota en milisegundos
int noteDuration = 500;
int A, B;
char operacion = ' ';

// Definiciones de las notas musicales
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

// Melodía a reproducir
int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

unsigned long tiempoAnteriorBuzzer;  // Almacena el tiempo en que se activó el zumbador por última vez.
bool buzzerActivo = false;    

int button_state = 0;

int duration = 0;
int i = 1;

void setup() {

  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(potentiometer, INPUT); //Sets the pinmode to input

}

void loop() {
  grabadora();
  musica();


}

void grabadora(){
  button_state = digitalRead(BUTTON);

  if(button_state == HIGH){
    digitalWrite(LED, HIGH);  
    int soundValue = 0; //create variable to store many different readings
    soundValue >>= 5; //bitshift operation   for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(SONIDO);  } //read the sound sensor
    Serial.println(soundValue); //print the value of sound sensor
      Serial.println("         ||        ");
      Serial.println("       ||||||      ");
      Serial.println("     |||||||||     ");
      Serial.println("   |||||||||||||   ");
      Serial.println(" ||||||||||||||||| ");
      Serial.println("   |||||||||||||   ");
      Serial.println("     |||||||||     ");
      Serial.println("       ||||||      ");
      Serial.println("         ||        ");
    delay(50); 
    
  }else{
      digitalWrite(LED, LOW);

  }
}

void musica(){
    int sensor_value = analogRead(potentiometer); 
    int value = map(sensor_value, 0, 1023, 0, 100); 

    if(value ==100){    
      for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
      tone(BUZZER_PIN, melody[i], noteDuration);
      delay(noteDuration + 50);  // Pausa entre notas
      noTone(BUZZER_PIN);
    }
      }

    if(value == 0){

    }

}


void operaciones(){

    int sensor_value = analogRead(potentiometer); 
    int value = map(sensor_value, 0, 1023, 0, 100); 
    if(value ==0){   

        Serial.println("Ingrese el número A:");
        A = Serial.parseInt();

        Serial.println("Ingrese el número B:");
        B = Serial.parseInt();

        Serial.println("Ingrese la operación (+):");
        operacion = Serial.read();

    if (operacion == '+') {
        if (A < B) {
            Serial.println(A);
        } else {
            Serial.println(B);
        }
    }
}
}
