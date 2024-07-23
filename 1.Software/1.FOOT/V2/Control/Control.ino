#define BLYNK_TEMPLATE_ID           "TMPL6o0Gy0egQ"
#define BLYNK_TEMPLATE_NAME         "test ESP32"
#define BLYNK_AUTH_TOKEN            "P9bdA9oggEYSIl-20ktXJLCDS5VMcYeY"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "THIEN TRANG";
char pass[] = "phucnhannghia";
//-------------------------------------------------
#include <BleMouse.h>
BleMouse bleMouse("FOOT MOUSE PROMAX");
//-------------------------------------------------

#define Left 23
#define Right 22

String A;
int x,y,z,b;
int Device[] = {13,12,14,27,26,25,33,32};
int Val;
//-------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 27, 14);
  
  bleMouse.begin(); 
  
  pinMode(Left,INPUT_PULLUP);
  pinMode(Right,INPUT_PULLUP);

}

void loop() {

  Connected();
}
