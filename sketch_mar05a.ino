#include <Ultrasonic.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Ultrasonic ultrasonic(2,5);
BluetoothSerial, SerialBT;
int distance;

void setup() {
  Serial.begin(115200);
  pinMode(23,OUTPUT);
  SerialBT.begin("UTSEmbeddedSystem"); // device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("Please Wait...");
  delay(7000);
}

void loop() {
  distance = ultrasonic.read();

  SerialBT.print("Distance in CM: ");
  SerialBT.print(ultrasonis.read());
  SerialBT.print(" cm");
  SerialBT.print("Distance in CM: ");
  SerialBT.print(distance);
  SerialBT.print(" cm");
  delay(500);
  if ((distance<10) or (distance==357)) {
    digitalWrite(23, HIGH);
  }
  else {
    digitalWrite(23, LOW);
  }
  delay(5000);
  }

}
