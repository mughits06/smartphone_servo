#define BLYNK_PRINT Serial


#include <Servo.h>
#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk

char auth[] = "W1OOzbIXXnSySuE8nxr3ngnSffqPB-pr";
char ssid[] = "abcd";
char pass[] = "ugiugiuaa";

Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
  // fungsi blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk
}

void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan boudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi dan passwordnya

  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run(); // memulai blynk
}
