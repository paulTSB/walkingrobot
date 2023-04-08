/*
  ESP32 PCA9685 Servo Control for four legged robot
  esp32-pca9685.ino
  Driving multiple servo motors with ESP32 and PCA9685 PWM module
  Use I2C Bus
  Adapetd from code from DroneBot Workshop 2020
  https://dronebotworkshop.com
  Paul Watt 02/04/2023
*/
 
// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);
 
// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width
 
#define SERVOMIN  80  // Minimum value
#define SERVOMAX  600  // Maximum value
 
// Define servo motor connections (expand as required)
// front left Leg one ~ front right Leg three
// Rear Left. Leg two ~ Rear  right Leg four
  //leg one front left
#define SER0  0  //Servo Motor 0 on connector 0 - leg one hip rotation
#define SER1  1  //Servo Motor 1 on connector 1 - leg one upper vertical
#define SER2  2  //Servo Motor 2 on connector 2 - leg one lower vertical
#define SER3  3  //Servo Motor 3 on connector 0 - leg two hip rotation
#define SER4  4  //Servo Motor 4 on connector 1 - leg two upper vertical
#define SER5  5  //Servo Motor 5 on connector 2 - leg two lower vertical
#define SER6  6  //Servo Motor 3 on connector 0 - leg three hip rotation
#define SER7  7  //Servo Motor 4 on connector 1 - leg three upper vertical
#define SER8  8  //Servo Motor 5 on connector 2 - leg three lower vertical
#define SER9  9  //Servo Motor 3 on connector 0 - leg four hip rotation
#define SER10  10  //Servo Motor 4 on connector 1 - leg four upper vertical
#define SER11  11  //Servo Motor 5 on connector 2 - leg four lower vertical
// Variables for Servo Motor positions (expand as required)
int pwm0;
int pwm1;
int pwm2;
int pwm3;
int pwm4;
int pwm5;
int pwm6;
int pwm7;
int pwm8;
int pwm9;
int pwm10;
int pwm11;
 
void setup() {
 
  // Serial monitor setup
  Serial.begin(115200);
  // Initialize PCA9685
  pca9685.begin();
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);
 
}
void loop() {
  //test movement
  leg_one_fwd();
  delay(120);
  leg_two_fwd();
  delay(120);
  leg_three_fwd(); 
  delay(120);
  leg_four_fwd();
  }

void leg_one_fwd() {
  // Move Motor 1 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0);
     }
 // Move Motor 2 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm1 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
     }

     // Move Motor 3 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm2 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER2, 0, pwm2);
     }
  delay(60);
     // Move Motor 1 from 45 to 00 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0);
     }
 // Move Motor 2 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm1 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
     }
     // Move Motor 3 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm2 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER2, 0, pwm2);
     }

   
}

void leg_two_fwd() {
  // Move Motor 4 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm3 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm3);
     }
 // Move Motor 5 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm4 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm4);
     }

     // Move Motor 6 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm5 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER5, 0, pwm5);
     }
  delay(60);
     // Move Motor 4 from 45 to 00 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm3 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm3);
     }
 // Move Motor 5 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm4 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm4);
     }
     // Move Motor 6 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm5 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER5, 0, pwm5);
     }

   
}

void leg_three_fwd() {
  // Move Motor 7 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm6 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm6);
     }
 // Move Motor 7 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm7 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm7);
     }

     // Move Motor 8 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm8 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8);
     }
  delay(60);
     // Move Motor 6 from 45 to 00 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm6 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm6);
     }
 // Move Motor 7 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm7 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm7);
     }
     // Move Motor 8 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm8 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8);
     }

   
}

void leg_four_fwd() {
  // Move Motor 8 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm9 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9);
     }
 // Move Motor 9 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm10 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm10);
     }

     // Move Motor 10 from 0 to 45 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm11 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER11, 0, pwm11);
     }
  delay(60);
     // Move Motor 8 from 45 to 00 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm9 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9);
     }
 // Move Motor 9 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm10 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm10);
     }
     // Move Motor 8 from 45 to 0 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm11 = map(posDegrees, 45, 0, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER11, 0, pwm11);
     }

   
}