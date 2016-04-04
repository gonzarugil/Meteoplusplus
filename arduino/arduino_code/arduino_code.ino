#include <LiquidCrystal.h>//Incluimos la libreria de la LCD
#include "DHT.h"//Incluye libraría de control del sensor
#define DHTPIN 8//Defiene el pin al que se conectará el sensor
#define DHTTYPE DHT11//Seleciona el tipo de sensor
DHT dht(DHTPIN, DHTTYPE);//Configura la libraría

int Humedad=0;//Declaramos la variable Humedad
int Temperatura=0;//Declaramos la variable Humedad

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Declaramos los pines que usa nuestra pantalla(RS,E,D4,D5,D6,D7)

void setup() {
  dht.begin();//Inicializa la libraria dht
  lcd.begin(16, 2);//Iniciamos la pantalla y le decimos el numero de caracteres y filas
  
  lcd.setCursor(4, 0);//Situamos el lugar donde empezará la escritura
  lcd.print("Meteo ++");//Escribimos LEANTEC en la LCD
  delay (2000);//Esperamos dos segundos
  lcd.clear();//Limpiamos la pantalla
  lcd.setCursor(0, 0);//Situamos el lugar donde empezará la escritura
  lcd.print("Estacion");//Escribimos Robotics & en la LCD
  delay (1000);//Esperamos un segundos
  lcd.setCursor(3, 1);//Situamos el lugar donde empezará la escritura
  lcd.print("Meteorologica");//Escribimos Electronics en la LCD
  delay (2000);//Esperamos dos segundos
  lcd.clear();//Limpiamos la pantalla
  
  
}

void loop() {
  
  Humedad = dht.readHumidity();//Lee la humedad
  Temperatura = dht.readTemperature();//Lee la temperatura
  
  lcd.setCursor(0, 0);//Situamos el lugar donde empezará la escritura
  lcd.print("HUMEDAD");//Escribimos HUMEDAD en la LCD
  lcd.setCursor(12, 0);//Situamos el lugar donde empezará la escritura.
  lcd.print(Humedad);//Representamos el valor de la variable Humedad.
  lcd.setCursor(14, 0);//Situamos el lugar donde empezará la escritura
  lcd.print("%");//Escribimos % en la LCD
  lcd.setCursor(0, 1);//Situamos el lugar donde empezará la escritura
  lcd.print("TEMPERATURA");//Escribimos TEMPERATURA en la LCD
  lcd.setCursor(12, 1);//Situamos el lugar donde empezará la escritura
  lcd.print(Temperatura);//Representamos el valor de la variable Temperatura.
  lcd.setCursor(14, 1);//Situamos el lugar donde empezará la escritura
  lcd.print("C");//Escribimos C en la LCD
  delay(100);//Esperamos 100 milisegundos
  
    }
