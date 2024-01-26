#include <DHT.h>//Incluyo la librería del sensor DHT11

//Configuro pines y variables
int SENSOR = 2;//Pin 2 para el valor del sensor DHT11
int temp, humedad;//Configuro las variables de temperatura y humedad del DHT11
const int nivel = 9; //Pin 9 para medir el nivel de agua
const int bomba = 13; //Pin 13 para la bomba
const int humedadsuelo = A0; //A0 para la humedad del suelo

DHT dht (SENSOR, DHT11);//Configuro el modelo de DHT. Es el DHT11

//Parte de humedad suelo y riego

void setup()
{
  Serial.begin(9600);//Arrancamos el puerto serie a 9600
  dht.begin();//Arranco el sensor DHT11
  
  //Configuramos entradas y salidas
  pinMode(humedadsuelo, INPUT);//Configuro humedadsuelo como entrada
  pinMode(bomba, OUTPUT);//Configuro bomba como salida
  pinMode(nivel, INPUT);//Configuro en nivel de agua como entrada
 }

void loop()
{
  int SensorValue = analogRead(humedadsuelo);//Leo el valor de la humedad y lo meto en SensorValue
  int SensorNivel = digitalRead(nivel); //Leo lo que marca el nivel de agua
  
  //Leo y meto los valores de temperatura y humedad en las variables temp y humedad
  humedad = dht.readHumidity();
  temp = dht.readTemperature();
  
  //Imprimo por el puerto serie los valores de temperatura y humedad del DHT11
  Serial.print("Temperatura: "); Serial.print(temp);
  Serial.print("ºC Humedad: "); Serial.print(humedad); Serial.println("%");
  
  //Imprimo por el puerto serie el valor de la humedad del suelo
  Serial.print("Humedad del suelo: ");Serial.print(SensorValue); Serial.println("%");
  delay(3000);
  
if (SensorNivel==0)
  { Serial.println("Nivel bajo de Agua. Rellenar el tanque"); 
  delay(2000);}

if (SensorNivel==1) 
  {
   Serial.println("Nivel de agua correcto, se puede regar");
   if(SensorValue >= 700) // el valor que considero seco y hay que regar es de 700
  {
   // Si la tierra está seca, comenzara a regar
   // Riega durante 1 segundo y espera a comprobar la humedad otro segundo
   Serial.println("La tierra está seca, comienza el riego");
   digitalWrite(bomba, HIGH);
   delay(2000);
   digitalWrite(bomba, LOW);
   delay(1000);
  }
   }  
  
  //Si la tierra no está seca, no riega y da el valor de la humedad
  delay(1000);
}