void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT); // sets the digital pin 10 as output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10,1); // Turns on pin 10
  delay(1000);        // 1 Sec Delay
  digitalWrite(10,0); // Turns off pin 10
  delay(1000);
}
