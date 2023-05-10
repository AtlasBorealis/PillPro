//Global Pin Variables
byte const mosPin = 13;
byte const ledPin = 14;
byte const buzzPin = 27;
byte const servPin = 26;
byte const limPin = 25;
byte const butPin = 33;

//Buzzer Globals
byte const buzzPwm = 2;
int const buzzFreq = 750;
int const buzzRes = 8; //Resolution in bits
int const buzzDuty = 50; //Percent duty cycle

//Sleep Globals
uint64_t const microFactor = 1000000;
uint64_t const sleepSecDefault = 86400*microFactor;

//Servo Move Counter
RTC_DATA_ATTR byte servoMoves = 0;

//Libraries
#include <ESP32Servo.h>
#include "driver/rtc_io.h"
#include "BluetoothSerial.h"

//Servo Object
Servo servo;

//---------------Setup---------------
void setup(){

  //Continues on if timer woke up esp
  //Goes into connectivity function if ext0 woke up esp
  byte alarm = wakeup_reason_det();

  //Pin Setups
  pinMode(mosPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(limPin, INPUT_PULLUP);
  pinMode(butPin, INPUT_PULLUP);
  servo.attach(servPin); //Assuming this operates on PWM channel 0

  //Buzzer and PWM channel setup
  ledcSetup(buzzPwm, buzzFreq, buzzRes);
  ledcAttachPin(buzzPin, buzzPwm);

  //Sets desired starting values of pins
  digitalWrite(mosPin,LOW);
  digitalWrite(ledPin,LOW);

  //Runs alarm sequence
  if (alarm == 1){
    runAlarm();
  }

  //Configures and sends esp to sleep
  esp_sleep(sleepSecDefault);

}//END SETUP

//---------------Loop---------------//NOT USED
void loop(){
  //Will never enter loop as esp32 sleeps and then restart setup code
}//END LOOP