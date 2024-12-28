#include <DHT.h>
#include <Servo.h>

#define ServoBR 13
#define ServoBL 23
#define ServoCR 18
#define ServoCL 19
#define LDR 26
#define DHT1 14
#define Fan 4
#define Element 5
#define buzzer 2
#define MSB1 32
#define MSB2 33

Servo servoBR;
Servo servoBL;
Servo servoCR;
Servo servoCL;
dht DHT;

float t,h;
void setup() {
  pinMode(LDR, INPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Element, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(MSB1, INPUT);
  pinMode(MSB2, INPUT);

  Serial.begin(115200);

  servoBR.attach(ServoBR);
  servoBL.attach(ServoBL);
  servoCR.attach(ServoCR);
  servoCL.attach(ServoCL);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readData = DHT.read11(DHT1); // DHT11
  t = DHT.temperature; // Gets the values of the temperature
  h = DHT.humidity; // Gets the values of the humidity
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" ");
  Serial.print((char)176);//shows degrees character
  Serial.print("C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);//print the temperature in Fahrenheit
  Serial.print(" ");
  Serial.print((char)176);//shows degrees character
  Serial.println("F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.println("");
  delay(2000); // Delays 2 secods
}
