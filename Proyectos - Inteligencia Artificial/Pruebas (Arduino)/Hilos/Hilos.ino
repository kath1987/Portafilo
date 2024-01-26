#define LED_PIN 6
#define BUZZER_PIN 5
#define LIGHT_SENSOR_PIN A3

// Duración de cada nota en milisegundos
int noteDuration = 500;

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
bool buzzerActivo = false;          // Bandera que indica si el zumbador está activo o no.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Lectura del valor del sensor de luz
  int valorSensorLuz = analogRead(LIGHT_SENSOR_PIN);

  // Impresión del valor para depuración
  Serial.print("Valor del sensor de luz: ");
  Serial.println(valorSensorLuz);

  // Verificación del valor del sensor de luz
  if (valorSensorLuz < 500) {
    // Si la luz es baja, apaga el LED y ejecuta la función de reproducción del zumbador
    digitalWrite(LED_PIN, LOW);
    ejecutarHiloBuzzer();
  } else {
    // Si la luz es suficientemente alta, enciende el LED, apaga el zumbador y restablece la bandera
    digitalWrite(LED_PIN, HIGH);
    noTone(BUZZER_PIN);
    buzzerActivo = false;
  }
}

void ejecutarHiloBuzzer() {
  // Obtención del tiempo actual
  unsigned long tiempoActual = millis();

  // Verificación del estado del zumbador y del tiempo transcurrido
  if (!buzzerActivo && tiempoActual - tiempoAnteriorBuzzer >= 500) {
    // Reproducción de la melodía en el zumbador con pausas entre notas
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
      tone(BUZZER_PIN, melody[i], noteDuration);
      delay(noteDuration + 50);  // Pausa entre notas
      noTone(BUZZER_PIN);
    }

    // Actualización del tiempo anterior y activación del zumbador
    tiempoAnteriorBuzzer = tiempoActual;
    buzzerActivo = true;
  }
}