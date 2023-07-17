# import the required libraries
import cv2
import time
import keyboard
import datetime
import math

# create an object for VideoCapture
cap = cv2.VideoCapture(0)

# x and y limits for cropping the image with a resolution of 640 x 320 px
x_min = 208
x_max = 432
y_min = 128
y_max = 352

# frequency of saving images
sample_time_for_image_saving = 0.5

# function for saving the images
def collect_images():
	# note the start time of starting the function
	start_time = time.monotonic()
	# note the time to save images as per the sample_time_for_image_saving frequency
	current_time_for_image_saving = time.monotonic()
	i=0 # numbering the images
	while True:
		_, img = cap.read()
		region_of_interest = img[y_min:y_max, x_min:x_max] # crop the image to 224 x 224 px

		if time.monotonic()-start_time > 10:
			# To start the image collection after 10 seconds
			collect_flag = 1
		else:
			# Set the collect_flag to zero until the timer reaches 10 seconds
			collect_flag = 0
			# update the time to display on the screen
			data_collection_start_timer = time.monotonic()-start_time
			data_collection_start_timer = 10-round(data_collection_start_timer)

		if (current_time_for_image_saving + sample_time_for_image_saving) < time.monotonic() and collect_flag:
			# start collecting the images after 10 seconds and as per the sampling frequency set in the sample_time_for_image_saving
			i=i+1
			print("Saving image {}".format(i))
			path = f"D:\\Pycharm\\color_detection_robot_arm\\dataset\\background_images\\image{i}.jpg"
			cv2.imwrite(path, region_of_interest)
			current_time_for_image_saving = time.monotonic()
		
		if collect_flag ==0:
			# display the count down for starting image collection
			cv2.putText(region_of_interest, "Image collection starts in", (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0), 2, cv2.LINE_AA)
			cv2.putText(region_of_interest, str(data_collection_start_timer)+ " seconds", (70, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0), 2, cv2.LINE_AA)
		else:
			# diplay the image number when saving the images
			cv2.putText(region_of_interest, "Saving image "+str(i), (45, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0), 2, cv2.LINE_AA)
	
		cv2.imshow("Cropped Image", region_of_interest)
		if cv2.waitKey(10) & 0xFF == ord('x'):
			print("Hello")
			break

		if time.monotonic() - start_time>30:
			break

def keyboard_input():
	# function to get input for image collection
	print("Press 's' to start collecting the images")
	if keyboard.read_key() == 's':
		collect_images()
	else:
		time.sleep(0.5)
		print("Sorry. Wrong input. Try again \n\n")
		keyboard_input()
		

if __name__ == '__main__':
	keyboard_input()