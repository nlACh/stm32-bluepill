/*
 *  STM32 Multi serial use. 
 *  There are 3 serial ports, Serial1: PA9, PA10, Serial2: PB6, PB7 , Serial3: PB11, PB10
 *  The Serial1 is by default used to upload code to the chip, when using USB-Serial adapters.
 *  If a dfu bootloader is used, then this should be tied to USB-COM port.
 */
HardwareSerial Serial3(PB11, PB10);
void setup() {
  Serial.begin(9600);
  Serial.println("Reading on default serial");
  Serial3.begin(38400);
  Serial3.print("Hello");
}

void loop() {
  char b;
  if (Serial3.available()){
    b = Serial3.read();
    //Serial.println(b, HEX);
    Serial.print(b);
  }
}
