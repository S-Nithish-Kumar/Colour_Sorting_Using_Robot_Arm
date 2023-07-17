//import the required librabries
#include<Wire.h> // To communicate with PCA9685 Servomotor driver which uses I2C communication protocol
#include<Adafruit_PWMServoDriver.h> // To set the pwm frequency and control the servomotors
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // create an object

// servomotor 1 is the elbow motor
// servomotor 2 is the shoulder motor
// servomotor 3 is the gripper motor
// servomotor 4 is the base motor

// initialize the variables
int desired_position_value1; // the desired_position_value of the servomotor 1
int current_position_value1; // current_position_value of the servomotor 1
int desired_position_value2;
int current_position_value2;
int desired_position_value3;
int current_position_value3;
int desired_position_value4;
int current_position_value4;
int object_category_data; // to read and store the object classification data received from the Deep Learning model

void setup()
{
  Serial.begin(9600); // initialize the serial motor to view the print statements
  pwm.begin(); // initialize the pwm object
  pwm.setPWMFreq(55); // set the pwm frequency which is typically 55 Hz for MG90S servomotor
  // initialize the servomotor positions. Servomotors are controlled by potentiometers to determine all these values
  current_position_value1 = 550; 
  current_position_value2 = 448;
  current_position_value3 = 260;
  current_position_value4 = 130;
  // Bring the servomotors to the home position
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

void loop() 
{
  while(Serial.available())
  {
  object_category_data = Serial.read();
  // if object_category_data == 1, then pick the object and place it in the green position  
  if(object_category_data=='1')
  {
  desired_position_value3= 125; // desired_position_value position
  // if the desired_position_value position and current_position_value position is not 
  if(desired_position_value3 != current_position_value3)
  {
    // if the desired position value is greater than current position value then the current position value has to be incremented to reach the desired position
    if(desired_position_value3>current_position_value3)
    {
      for(int i=current_position_value3; i<=desired_position_value3; i++)
      {pwm.setPWM(3,0,i);
        delay(5);} // a delay of 5ms is added to control the speed of the servomotor    
      current_position_value3 = desired_position_value3; // set the current position value of the servomotor. This is needed for controlling the motor again
    }
    // if the desired position value is less than current position value then the current position value has to be decremented to reach the desired position
    if(desired_position_value3<current_position_value3)
    {
      for(int j=current_position_value3; j>=desired_position_value3; j--)
      {pwm.setPWM(3,0,j);
        delay(5);}
       current_position_value3 = desired_position_value3;
    }
  }

  desired_position_value2= 510;
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

  desired_position_value4= 290;
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

  desired_position_value2= 450;
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
  
  desired_position_value3= 260;
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

  desired_position_value1= 455;
  if(desired_position_value1 != current_position_value1)
  {
    if(desired_position_value1>current_position_value1)
    {
      for(int i=current_position_value1; i<=desired_position_value1; i++)
      {pwm.setPWM(1,0,i);
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

  desired_position_value4= 130;
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

  desired_position_value1= 550;
  if(desired_position_value1 != current_position_value1)
  {
    if(desired_position_value1>current_position_value1)
    {
      for(int i=current_position_value1; i<=desired_position_value1; i++)
      {pwm.setPWM(1,0,i);
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
  }
  // if object_category_data == 0, then pick the object and place it in the orange position 
  else if(object_category_data=='0')
  {
  desired_position_value3= 125;
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

  desired_position_value2= 510;
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

  desired_position_value4= 400;
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

  desired_position_value2= 450;
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
  
  desired_position_value3= 260;
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

  desired_position_value1= 455;
  if(desired_position_value1 != current_position_value1)
  {
    if(desired_position_value1>current_position_value1)
    {
      for(int i=current_position_value1; i<=desired_position_value1; i++)
      {pwm.setPWM(1,0,i);
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

  desired_position_value4= 130;
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

  desired_position_value1= 550;
  if(desired_position_value1 != current_position_value1)
  {
    if(desired_position_value1>current_position_value1)
    {
      for(int i=current_position_value1; i<=desired_position_value1; i++)
      {pwm.setPWM(1,0,i);
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
  }
  }

}
