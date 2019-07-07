#include<dht.h>
dht DHT;
#define DHT11_PIN 4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM");
  Serial.print("LIBRARY VERSION:");
  Serial.println(DHT_LIB_VERSION);
  Serial.println():
  Serial.println("Type, \tstatus,\tHumidity(%),\tTemperatrue(C)");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DHT11,\t")；
  int chk = DHT.Read11(DHT11_PIN);
   switch (chk)
  {
    case 0:  Serial.print("OK,\t"); break;
    case -1: Serial.print("Checksum error,\t"); break;
    case -2: Serial.print("Time out error,\t"); break;
    default: Serial.print("Unknown error,\t"); break;
  }
  // DISPLAT DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
  delay(1000);
}

