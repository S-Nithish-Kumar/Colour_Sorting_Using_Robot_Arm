import serial # to communicate with the Arduino MCU through serial communication

port = serial.Serial('COM5',9600) # create an object for serial communication

while(port.isOpen()):
    data = int(input("Enter 1 to move to Green position and 0 to move to Orange Position"))

    if(data == 1):
        port.write(str.encode('1')) # send the value 1 to the Arduino MCU to place the object in green position
    elif(data == 0):
        port.write(str.encode('0')) # send the value 0 to the Arduino MCU to place the object in orange position
    else:
        print('Invalid input!!!!')
