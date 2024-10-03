#include <SPI.h>
#include <MCP3202.h>

const int ledPin = 33;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds)

float Vdd = 3.3; //change according to your Vdd value.

MCP3202 adc = MCP3202(10); //Parameter passed is the CS pin number. Change according to requirement.

float channel0 = 0;
float channel1 = 0;
void setup() {
  // put your setup code here, to run once:
  adc.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  channel0 = adc.readChannel(0);
  channel1 = adc.readChannel(1);
  //Serial.print(channel0);
  //Serial.print("channel 0 \t");

  //Serial.println(channel0);

  Serial.println(1.0*channel0*Vdd/4096.0);
  Serial.println(1.0*channel1*Vdd/4096.0);


  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  delay(10);
}
