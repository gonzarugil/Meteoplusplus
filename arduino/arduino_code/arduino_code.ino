#include <LiquidCrystal.h>//Incluimos la libreria de la LCD
#include <SoftwareSerial.h>// Incluimos la libreria para bluetooth
#include "DHT.h"//Incluye libraría de control del sensor
#define DHTPIN 8 //Defiene el pin al que se conectará el sensor
#define DHTTYPE DHT11//Seleciona el tipo de sensor
SoftwareSerial BT1(10,7);

DHT dht(DHTPIN, DHTTYPE);//Configura la libraría
int analogPin=0;//Declaramos que queremos usar el pin analógico 0
int analogPinb=2;//Declaramos que queremos usar el pin analógico 2
int Humedad=0;//Declaramos la variable Humedad
int Temperatura=0;//Declaramos la variable Temperatura
int Suelo=0;//Declaramos la variable Humedad Suelo
int Valor=0;//Declaramos porcentaje humedad suelo
int Auxiliar=0;//Declaramos auxiliar para humedad suelo
int Agua=0;
int AguaAux = 0;
char msg;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Declaramos los pines que usa nuestra pantalla(RS,E,D4,D5,D6,D7)

void setup() {
  
  dht.begin();//Inicializa la libraria dht
  Serial.begin(9600);
  BT1.begin(9600);
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
  
 // lcd.setCursor(0,0);
  /*lcd.write(BT1.read());
  delay(2000);
  lcd.clear(); */ 
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
  delay(3000);//Esperamos 100 milisegundos
  lcd.clear();//limpiamos la pantalla
  lcd.setCursor(0, 0);//Situamos el lugan donde empezará la escritura
  Suelo=analogRead(analogPin);
  Auxiliar=Suelo/10,24;
  Valor=100-Auxiliar;
  if(Valor<0)
    Valor=0;
  lcd.print("HUMEDAD SUELO");
  lcd.setCursor(3,1);
  lcd.print(Valor);
  //lcd.setCursor(6,1);
  lcd.print("%");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  Agua=analogRead(analogPinb);
  lcd.print("NIVEL DE AGUA");
  lcd.setCursor(0,1);
  AguaAux=Agua/4;
  lcd.print(Agua);
  lcd.print("%");
  
  //Serial.print(Agua);
  delay(3000);
  lcd.clear();

  //INICIO COMPROBACIÓN 

  if (BT1.available()){
    msg=BT1.read();
    switch(msg){
      case '0':
        lcd.setCursor(0,0);
        lcd.write("Bluetooth on");
        delay(2000);
      break;
      case '1':
      String aux1= "T "+Temperatura;
      BT1.print("Temperatura ");
      BT1.print(Temperatura);
      BT1.print("Humedad ");
      BT1.println(Humedad);
      delay(200); 
     
    }
  }else{
    lcd.setCursor(0,0);
    lcd.write("Bluetooth off");
    delay(2000);
    lcd.clear();
    
  }
  
  
  
 
    }
