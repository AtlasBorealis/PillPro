//Sleep Functions
//Handles wakeup logic
byte wakeup_reason_det(){
  //Initalize reason variable
  esp_sleep_wakeup_cause_t wakeup_reason;
  
  //Gets wakeup reason
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : bt_func();
    case ESP_SLEEP_WAKEUP_TIMER : return 1; break;
    default : return 0; break; //Assumed to be inital flash of code
  }
}//END WAKEUP_REASON_DET

//Configures wake up sources
//Sends ESP32 to sleep
void esp_sleep(uint64_t sleepTime){

  //Sleeps for passed in micro seconds
  esp_sleep_enable_timer_wakeup(sleepTime);

  //Configures button wake up source
  rtc_gpio_pullup_en(GPIO_NUM_33);
  rtc_gpio_pulldown_dis(GPIO_NUM_33);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0);
  
  //Clears serial buffer
  Serial.flush();

  //Sends esp32 to sleep
  esp_deep_sleep_start();
}