// Arduino DC motor speed and direction control

#define button1  8
#define button2  4
#define pot      0
#define pwm1     9
#define pwm2    10
#define pwm3     6
#define pwm4     5

boolean motor_dir = 0;
boolean motor_dir2 = 0;
int motor_speed;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(pwm1,   OUTPUT);
  pinMode(pwm2,   OUTPUT);
  pinMode(pwm3,   OUTPUT);
  pinMode(pwm4,   OUTPUT);
}

void loop() {
  motor_speed = analogRead(pot) / 4;
  if (motor_dir)
    analogWrite(pwm1, motor_speed);
  else
    analogWrite(pwm2, motor_speed);
      if (motor_dir2)
    analogWrite(pwm3, motor_speed);
  else
    analogWrite(pwm4, motor_speed);
    
  if (!digitalRead(button1)) {              // If direction button is pressed
    while (!digitalRead(button1));          // Wait until direction button released
    motor_dir = !motor_dir;                // Toggle direction variable
    if (motor_dir)
      digitalWrite(pwm2, 0);
    else
      digitalWrite(pwm1, 0);
  }
  if (!digitalRead(button2)) {              
    while (!digitalRead(button2));          
    motor_dir2 = !motor_dir2;                
    if (motor_dir2)
      digitalWrite(pwm4, 0);
    else
      digitalWrite(pwm3, 0);
  }
}
