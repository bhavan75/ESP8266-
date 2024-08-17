#define BLYNK_TEMPLATE_ID "//copy your TEPLATE_ID//"
#define BLYNK_TEMPLATE_NAME "//copy your TEPLATE_NAME//"
#define BLYNK_AUTH_TOKEN "//copy yoUR AUTH TOKEN Here//"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Your WiFi credentials
char ssid[] = "//your ssid name//";
char pass[] = "// ssid password//";

// Your Blynk credentials


// Servo instance
Servo myservo;
int servoPin = D4;

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Blynk begin
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Attach the servo to the pin
  myservo.attach(servoPin);
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    myservo.write(180); // Move to 90 degrees
  } else {
    myservo.write(0);  // Move to 0 degrees
  }
}

void loop()
{
  Blynk.run();
}
