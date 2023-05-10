uint64_t bt_func(){
  //Object setup
  BluetoothSerial SerialBT;

  //Variables declaration
  int userSec = -5;

  //Serial Port Setup
  Serial.begin(115200);
  SerialBT.begin("ESP32_Bluetooth_1.0.4");
  Serial.flush();
  
  while (userSec == -5){
    if (SerialBT.available() > 0) {
      userSec = SerialBT.parseInt();
    }
  }

  //Send esp to sleep with correct enables
  Serial.println(userSec);
  esp_sleep(userSec*microFactor);

}

