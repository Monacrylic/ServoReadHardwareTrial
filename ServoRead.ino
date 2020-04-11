
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int servoAnalogOut=A1; //The new Servo Pin
unsigned int servoValue0Deg, servoValue180Deg; // Vaiables to store min and max values of servo's pot
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  calibration();
}

void loop() {
 Serial.println(map(analogRead(servoAnalogOut),servoValue0Deg,servoValue180Deg, 0, 180));
 delay(500);
}

void calibration(){
  myservo.write(0); //set the servo to 0 position
  delay(2000); //wait for the servo to reach there
  servoValue0Deg= analogRead(servoAnalogOut); // Pot value at 0 degrees
  Serial.println("Pot value for 0 deg is " + String(servoValue0Deg)); // Print it!
  delay(500); //fancy delay
  myservo.write(180); //go to 180 degrees
  delay(2000); //wait for the servo to reach there
  servoValue180Deg= analogRead(servoAnalogOut); //pot value at 180 deg
  Serial.println("Pot value for 180 deg is " + String(servoValue0Deg));
  delay(500); //fancy delay 
  Serial.println("Now going to 90 Degrees"); //It does what it says
  myservo.write(90);// going to 90 degrees
  delay(2000);// wait for it to reach there
  myservo.detach(); // stop the PWM so that we can freely move the servo
  delay(1000);
  
}
