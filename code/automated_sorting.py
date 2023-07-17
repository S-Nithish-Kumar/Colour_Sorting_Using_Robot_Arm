# import the required libraries
import serial # to communicate with the Arduino MCU through serial communication
import time
import cv2
import numpy as np
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing import image

cap = cv2.VideoCapture(0) # initialize the an object for VideoCapture. Index 0 will access the webcam of the computer
model = load_model('color_sorting.h5') # load the trained Deep Learning model
ser = serial.Serial("COM5", 9600) # create an object for serial communication. This is used to transmit the classified output data from the Deep Learning model to the Arduino MCU


while(ser.isOpen()):
    cap.set(cv2.CAP_PROP_FPS, 10) # set the number of Frames per Second
    _, frame = cap.read() # read the frames
    frame = cv2.flip(frame, 1) # flip the frame around y-axis
    frame = cv2.resize(frame, (224, 224)) # resize the frame to match the input size of the trained Deep Learning model
    img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB) # change the color space from BGR to RGB

    my_image = image.img_to_array(img) # change the image type to an array
    #print(type(my_image))
    my_image = np.expand_dims(my_image, axis=0) # reshape the array as needed by the Deep Learning model
    #print(my_image.shape)
    result = model.predict(my_image) # prediction result. There are three categories - Background, green, orange
    print(result)
    cv2.imshow("frame",frame)

    if (result[0][0]==1):
        print((str(1)+ 'a').encode('utf-8'))
        ser.write(str.encode('5')) # send the value 5 to the Arduino MCU which indicates background
    elif(result[0][1]==1):
        print((str(2)+'b').encode('utf-8'))
        ser.write(str.encode('1')) # send the value 1 to the Arduino MCU which indicates green object
    elif(result[0][2]==1):
        print((str(3)+'c').encode('utf-8'))
        ser.write(str.encode('0')) # send the value 0 to the Arduino MCU which indicates orange object
    time.sleep(1)
    if (cv2.waitKey(20) & 0XFF) == ord('q'):
        break

