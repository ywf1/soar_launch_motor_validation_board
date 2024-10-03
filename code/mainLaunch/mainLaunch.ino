#include <SPI.h>
#include <MCP3202.h>
#include <SD.h>
//these are dummy values rn
#define relayPin 8
#define beginLaunchPin 17
#define endParsingPin 14
#define LED 33

elapsedMicros timeStamp;

File dataFile;
// Variables will change:
volatile bool startParsing = false;
volatile bool fire = false;
volatile bool launchOver = false;

const double Vdd = 3.3; //Vdd

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

MCP3202 adc = MCP3202(10); //Parameter passed is the CS pin number. Change according to requirement.

int pressureV = 0;
int forceV = 0;

long dummyCounter = 0;

void setup() {
  adc.begin();
  Serial.begin(115200);

  //I/O
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //begin launch input and interrupt
  pinMode(beginLaunchPin, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(beginLaunchPin), beginLaunch, HIGH);

  //begin stop launch input and interrupt
  pinMode(endParsingPin, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(endParsingPin), endParsing, HIGH);
  
  //SD setup
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Card failed, or not present");
    while (1) {
      // No SD card, so don't do anything more - stay stuck here
    }
  }
  dataFile = SD.open("3_31_0.txt", FILE_WRITE);
  if (dataFile) {
      Serial.println("SD Card File Found and Created");
      dataFile.println("Time(us),ForceRaw,PressureRaw,RelayValue");
    } 
}

void loop() {
  if(startParsing && !launchOver){
    if(timeStamp >= 1000000){
      fire = true;
      digitalWrite(relayPin, HIGH);
      if(timeStamp >= 2000000){
        digitalWrite(relayPin,LOW);
        fire = false;
      }
    }
    if (dataFile) {
      //log timestamp, pressure adc reading, and force adc readings
      pressureV = adc.readChannel(0);
      forceV = adc.readChannel(1);
      dataFile.print(timeStamp);
      dataFile.print(",");
      dataFile.print(pressureV);
      dataFile.print(",");
      dataFile.print(forceV);
      dataFile.print(",");
      dataFile.println(fire);
      //Serial.println(dummyCounter);
      //dummyCounter++;
    }
    if(timeStamp >= 20000000){
      startParsing = false;
      launchOver = true;
      dataFile.close();
    }
  } else if(launchOver){
    dataFile.close();
    digitalWrite(LED,HIGH);
    Serial.println("LaunchOver");
    digitalWrite(LED,HIGH);
    delay(500);
    digitalWrite(LED,LOW);
    delay(500);
  } else{
    //Serial.println("Awaiting launch..."); delay(100);
  }
}

void beginLaunch(){
  startParsing = true;
  timeStamp = 0;
  detachInterrupt(digitalPinToInterrupt(beginLaunchPin));
}

void endParsing(){
  if(startParsing){
    startParsing = false;
    launchOver = true;
    dataFile.close();
  }
}


