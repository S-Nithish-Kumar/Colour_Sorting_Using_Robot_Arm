//import the required librabries
#include<Wire.h> // To communicate with PCA9685 Servomotor driver which uses I2C communication protocol
#include<Adafruit_PWMServoDriver.h> // To set the pwm frequency and control the servomotors
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // create an object
#define SERVOMIN 130 // the minimum and maximum servomotor position values are determined through experiments and might vary for other motors.
#define SERVOMAX 550

// servomotor 1 is the elbow motor
// servomotor 2 is the shoulder motor
// servomotor 3 is the gripper motor
// servomotor 4 is the base motor
// Four potentiometers are used. One for each of the servomotors
int pot1=A0; // assign A0 pin for potentiometer 1
int pot1reading=0; // initialize a variable for potentiometer reading
int angle1=0; // initialize a variable which will be used for mapping pulse1 between 0 and 180 degrees
int pulse1=0; // initialize a variable which will be used for mapping angle1 between SERVOMIN and SERVOMAX
int pot2=A1;
int pot2reading=0;
int angle2=0;
int pulse2=0;
int pot3=A2;
int pot3reading=0;
int angle3=0;
int pulse3=0;
int pot4=A3;
int pot4reading=0;
int angle4=0;
int pulse4=0;

// initialize the variables
int desired_position_value1; // the desired_position_value of the servomotor 1
int current_position_value1; // current_position_value of the servomotor 1
int desired_position_value2;
int current_position_value2;
int desired_position_value3;
int current_position_value3;
int desired_position_value4;
int current_position_value4;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(55);
  // initialize the servomotor positions. Servomotors are controlled by potentiometers to determine all these values
  current_position_value1 = 550; 
  current_position_value2 = 448;
  current_position_value3 = 260;
  current_position_value4 = 130;
  // Bring the servomotors to the home position. Determined through experiments.
  //setPWM() syntax - setPWM(channel, on, off). The pin will be high from on to off value range (also known as tick values)
  pwm.setPWM(1,0,current_position_value1);
  delay(2000);
  pwm.setPWM(2,0,current_position_value2);
  delay(2000);
  pwm.setPWM(3,0,current_position_value3);
  delay(2000);
  pwm.setPWM(4,0,current_position_value4);
  delay(2000);
}

void loop() {
  pot1reading = analogRead(pot1);
  angle1 = map(pot1reading,0,1023,0,180); // map the potentiometer reading between 0 and 180 degrees
  pulse1= map(angle1,0,180,SERVOMIN,SERVOMAX); // map the angle reading between SERVOMIN and SERVOMAX which will be used for controlling the Servomotor
  current_position_value1 = pulse1;
  if(desired_position_value1 != current_position_value1)
  {
    if(desired_position_value1>current_position_value1)
    {
      for(int i=current_position_value1; i<=desired_position_value1; i++)
      {pwm.setPWM(1,0,i); // it's recommended take the readings from one motor at a time and comment the setPWM command for the other motors. Because if the potentiometer connection is loose it might make false triggers and make the motors misbehave. 
        delay(5);}    
      current_position_value1 = desired_position_value1; 
    }
    if(desired_position_value1<current_position_value1)
    {
      for(int j=current_position_value1; j>=desired_position_value1; j--)
      {pwm.setPWM(1,0,j);
        delay(5);}
       current_position_value1 = desired_position_value1;
    }
  }
  Serial.print("Motor_1_position_value: ");Serial.print(current_position_value1);
  
  pot2reading = analogRead(pot2);
  angle2 = map(pot2reading,0,1023,0,180);
  pulse2= map(angle2,0,180,SERVOMIN,SERVOMAX);
  current_position_value2 = pulse2;
  Serial.print("Pulse2: ");Serial.print(pulse2);
  if(desired_position_value2 != current_position_value2)
  {
    if(desired_position_value2>current_position_value2)
    {
      for(int i=current_position_value2; i<=desired_position_value2; i++)
      {pwm.setPWM(2,0,i);
        delay(5);}    
      current_position_value2 = desired_position_value2; 
    }
    if(desired_position_value2<current_position_value2)
    {
      for(int j=current_position_value2; j>=desired_position_value2; j--)
      {pwm.setPWM(2,0,j);
        delay(5);}
       current_position_value2 = desired_position_value2;
    } 
  }
  Serial.print("Motor_2_position_value: ");Serial.print(current_position_value2);

  pot3reading = analogRead(pot3);
  angle3 = map(pot3reading,0,1023,0,180);
  pulse3= map(angle3,0,180,SERVOMIN,SERVOMAX);
  current_position_value3 = pulse3;
  if(desired_position_value3 != current_position_value3)
  {
    if(desired_position_value3>current_position_value3)
    {
      for(int i=current_position_value3; i<=desired_position_value3; i++)
      {pwm.setPWM(3,0,i);
        delay(5);}    
      current_position_value3 = desired_position_value3; 
    }
    if(desired_position_value3<current_position_value3)
    {
      for(int j=current_position_value3; j>=desired_position_value3; j--)
      {pwm.setPWM(3,0,j);
        delay(5);}
       current_position_value3 = desired_position_value3;
    }
  }
  Serial.print("Motor_3_position_value: ");Serial.print(current_position_value3);

  pot4reading = analogRead(pot4);
  angle4 = map(pot4reading,0,1023,0,180);
  pulse4= map(angle4,0,180,SERVOMIN,SERVOMAX);
  current_position_value4 = pulse4;
  if(desired_position_value4 != current_position_value4)
  {
    if(desired_position_value4>current_position_value4)
    {
      for(int i=current_position_value4; i<=desired_position_value4; i++)
      {pwm.setPWM(4,0,i);
        delay(5);}    
      current_position_value4 = desired_position_value4; 
    }
    if(desired_position_value4<current_position_value4)
    {
      for(int j=current_position_value4; j>=desired_position_value4; j--)
      {pwm.setPWM(4,0,j);
        delay(5);}
       current_position_value4 = desired_position_value4;
    }
  }
  Serial.print("Motor_4_position_value: ");Serial.print(current_position_value4);
}
