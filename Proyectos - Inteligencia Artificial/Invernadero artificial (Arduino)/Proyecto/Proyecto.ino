#include <DHT.h>

// Configuro pines y variables
int SENSOR = 2; // Pin 2 para el valor del sensor DHT11
int temp, humedad; // Configuro las variables de temperatura y humedad del DHT11
const int nivel = 9; // Pin 9 para medir el nivel de agua
const int bomba = 13; // Pin 13 para la bomba
const int humedadsuelo = A0; // A0 para la humedad del suelo
const int fan = 12; // El ventilador

int LDR = 0;
int pjoven = 0, padulta = 0;
int conversion = 0;

DHT dht(SENSOR, DHT11); // Configuro el modelo de DHT. Es el DHT11

void setup()
{
  Serial.begin(9600); // Arrancamos el puerto serie a 9600
  dht.begin(); // Arranco el sensor DHT11

  // Configuramos entradas y salidas
  pinMode(humedadsuelo, INPUT); // Configuro humedadsuelo como entrada
  pinMode(bomba, OUTPUT); // Configuro bomba como salida
  pinMode(nivel, INPUT); // Configuro en nivel de agua como entrada
  pinMode(fan, OUTPUT); // Configuro el ventilador como salida
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int SensorValue = analogRead(humedadsuelo); // Leo el valor de la humedad y lo meto en SensorValue
  int SensorNivel = digitalRead(nivel); // Leo lo que marca el nivel de agua

  // Leo y meto los valores de temperatura y humedad en las variables temp y humedad
  humedad = dht.readHumidity();
  temp = dht.readTemperature();

  // Imprimo por el puerto serie los valores de temperatura y humedad del DHT11
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("ºC Humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  // Imprimo por el puerto serie el valor de la humedad del suelo
  Serial.print("Humedad del suelo: ");
  Serial.print(SensorValue);
  Serial.println("%");
  delay(3000);

  // Control del ventilador basado en la temperatura
  if (temp > 30.0) { // Ajusta este umbral según tus necesidades
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(fan, LOW);
  }

  // Control de plantas jóvenes y adultas
  if (digitalRead(4) == HIGH)
  {
    padulta = 0;
    pjoven = 1;
  }
  if (digitalRead(5) == HIGH)
  {
    pjoven = 0;
    padulta = 1;
  }
  if (pjoven == 1)
  {
    analogWrite(13, LOW);
    plantajoven();
  }
  if (padulta == 1)
  {
    digitalWrite(3, LOW);
    plantaadulta();
  }
  delay(500);
}

void plantajoven()
{
  Serial.println("Planta Joven");
  LDR = analogRead(A0);
  Serial.println(LDR);
  if (LDR > 600)
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }
}

void plantaadulta()
{
  Serial.println("Planta Adulta");
  LDR = analogRead(A0);
  conversion = 780 - LDR;
  Serial.println(LDR);
  analogWrite(13, conversion);
}
