//Alarm Functions
//Handles alarm logic when called
void runAlarm(){

  //Starts Alarm
  servMove();
  digitalWrite(ledPin,HIGH);
  ledcWrite(buzzPwm,buzzDuty);

  //Waits for limit switch to close
  while(digitalRead(limPin) == 1){}//Do nothing until limPin == 0

  //Turns off buzzer and light after limit switch
  digitalWrite(ledPin,LOW);
  ledcWrite(buzzPwm,0);

  //Delay to avoid limit switch bounce
  delay(100);

  //Wait for limit switch to open
  while(digitalRead(limPin) == 0){}//Do nothing until limPin == 1

}//END RUNALARM


//Function to command servo
void servMove(){
  int const stepDelay = 10;
  int const lowLim = 82;
  int const highLim = 105;
  byte servCycles;

  //Determines number of cycles to run servo for
  if (servoMoves == 2){
    servCycles = 7;
    servoMoves = 0;
  }else{
    servCycles = 8;
  }

  //Powers servo
  digitalWrite(mosPin,HIGH);

  //Cycles the servo from low to high and back specified number of times
  for (int servi = 0; servi < servCycles; servi += 1){

    //Low to High
    for(int pos = lowLim; pos <= highLim; pos += 1){
      servo.write(pos);
      delay(stepDelay);
    }

    //High to low
    for(int pos = highLim; pos >= lowLim; pos -= 1){
      servo.write(pos);
      delay(stepDelay);
    }
  }

  //Pulls power from servo
  digitalWrite(mosPin, LOW);

}//END SERVCMD