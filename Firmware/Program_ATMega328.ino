const int button1 = A2; //pin 25 (+5 pwm)
const int button2 = A3; //pin 26 (-5 pwm)
const int button3 = A4; //pin 27 (+10 pwm)
const int button4 = A5; //pin 28 (-10 pwm)
const int pwm = 6; //pin 12

int buttonState1 = 0, buttonState2 = 0, buttonState3 = 0, buttonState4 = 0;
int lastButtonState1 = 0, lastButtonState2 = 0, lastButtonState3 = 0, lastButtonState4 = 0;
int speedMotor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(pwm, OUTPUT);
  
  Serial.begin(9600);
}

//read condition button
int pushButton(int button, int buttonState, int lastButtonState){
  buttonState = digitalRead(button);

  if (buttonState != lastButtonState){
    if (buttonState == HIGH){
      if (button == A2){
        return 5;
      } else if (button == A3){
        return -5;
      } else if (button == A3){
        return 10;
      } else {
        return -10;
      }
    }
    delay(50);
  }
  return 0;
}

void loop() {
  // increase/decrease speed motor
  speedMotor += pushButton(button1, buttonState1, lastButtonState1);
  speedMotor += pushButton(button2, buttonState2, lastButtonState2);
  speedMotor += pushButton(button3, buttonState3, lastButtonState3);
  speedMotor += pushButton(button4, buttonState4, lastButtonState4);

  if (speedMotor > 255) speedMotor = 255;
  if (speedMotor < 0) speedMotor = 0;

  analogWrite(pwm, speedMotor);

  Serial.println(speedMotor);
}
