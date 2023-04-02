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
  //leg two rear left
#define SER3  3  //Servo Motor 3 on connector 3 - leg two hip rotation
#define SER4  4  //Servo Motor 4 on connector 4 - leg two upper vertical
#define SER5  5  //Servo Motor 5 on connector 5 - leg two lower vertical
  //leg three front right
#define SER6  6  //Servo Motor 6 on connector 6 - leg three hip rotation
#define SER7  7  //Servo Motor 7 on connector 7 - leg three upper vertical
#define SER8  8  //Servo Motor 8 on connector 8 - leg three lower vertical
  //leg four rear right
#define SER9  9    //Servo Motor 9 on connector 9   - leg four hip rotation
#define SER10  10  //Servo Motor 10 on connector 10 - leg four upper vertical
#define SER11  11  //Servo Motor 11 on connector 11 - leg four lower vertical
  //currently unused
#define SER12  12  //Servo Motor 12 on connector 12
#define SER13  13  //Servo Motor 13 on connector 13
#define SER14  14  //Servo Motor 14 on connector 14
#define SER15  15  //Servo Motor 15 on connector 15
// Variables for Servo Motor positions (expand as required)
int pwm0;
int pwm1;
 
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
  robot_forward();
  delay(30);
  robot_back();
  delay(30);
  robot_turn_right();
  delay(30);
  robot_turn_left();
  delay(30);
  }
void robot_forward() {
  leg_one_fwd();
  leg_four_fwd();
  leg_two_fwd();
  leg_three_fwd();
}
void robot_back() {
  leg_one_bck();
  leg_four_bck();
  leg_two_bck();
  leg_three_bck();
}
void robot_turn_right(){
leg_one_fwd();
leg_two_fwd();
leg_three_bck();
leg_four_bck();
}
void robot_turn_left(){
leg_one_bck();
leg_two_bck();
leg_three_fwd();
leg_four_fwd();
}
void leg_one_fwd() {
  // Move Motor 1 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0);
    pca9685.setPWM(SER2, 0, pwm0);
  }
// Move Motor 0 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0);
  }
  // Move Motor 1 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0);
    pca9685.setPWM(SER2, 0, pwm0);
  }
// Move Motor 0 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0);
  }
}
void leg_one_bck() {
  // Move Motor 1 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0);
    pca9685.setPWM(SER2, 0, pwm0);
  }
  // Move Motor 0 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0); 
  }
  // Move Motor 1 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm0);
    pca9685.setPWM(SER2, 0, pwm0); 
  }
// Move Motor 0 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0);
  }
}
void leg_two_fwd() {
  // Move Motor 4 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm0);
    pca9685.setPWM(SER5, 0, pwm0); 
  }
// Move Motor 3 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm0); 
  }
  // Move Motor 4 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm0);
    pca9685.setPWM(SER5, 0, pwm0);   
  }
// Move Motor 3 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm0); 
  }
}
void leg_two_bck() {
   // Move Motor 4,5 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm0);
    pca9685.setPWM(SER5, 0, pwm0);     
  }
// Move Motor 3 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm0);
    }  
// Move Motor 4 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm0);
    pca9685.setPWM(SER5, 0, pwm0);
    }
// Move Motor 3 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm0);
    }
 }
void leg_three_fwd() {
// Move Motor 7 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm0);
    pca9685.setPWM(SER8, 0, pwm0);
    }

// Move Motor 6 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm0);
   }
// Move Motor 7 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm0);
    pca9685.setPWM(SER8, 0, pwm0);
   }
// Move Motor 6 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm0);
    }
}
void leg_three_bck() {
  // Move Motor 7 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm0);
    pca9685.setPWM(SER8, 0, pwm0);
    }
// Move Motor 6 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm0);
    }

// Move Motor 7 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER7, 0, pwm0);
    pca9685.setPWM(SER8, 0, pwm0);
   }
// Move Motor 6 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER6, 0, pwm0);
    }
 }
void leg_four_fwd() {
  // Move Motor 10 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm0);
    pca9685.setPWM(SER11, 0, pwm0);
   }
// Move Motor 9 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm0);
    }
  // Move Motor 10 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm0);
    pca9685.setPWM(SER11, 0, pwm0);    
    }
// Move Motor 9 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm0);
    }
}
void leg_four_bck() {
    // Move Motor 10 from 0 to 10 degrees - lifts leg up for clearence
  for (int posDegrees = 0; posDegrees <= 10; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm0);
    pca9685.setPWM(SER11, 0, pwm0);
    }
// Move Motor 9 from 45 to 0 degrees - brings leg back to original position
  for (int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm0);
    }
// Move Motor 10 from 10 to 0 degrees - puts leg down after rotation
  for (int posDegrees = 10; posDegrees >= 0; posDegrees--) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 10, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm0);
    pca9685.setPWM(SER11, 0, pwm0);
   }
// Move Motor 9 from 0 to 45 degrees rotates leg forward
  for (int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    // Determine PWM pulse width
    pwm0 = map(posDegrees, 0, 45, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm0);
    }
  }