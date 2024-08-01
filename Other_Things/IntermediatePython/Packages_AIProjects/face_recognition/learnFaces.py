import face_recognition
import cv2
import pickle

# Get a reference to webcam #0 (the default one)
cam = cv2.VideoCapture(0)

# enter name of person to learn face of
name = input('Enter your name: ') 

# creates a titled window for the webcam
cv2.namedWindow("Learn Face")

# counter for how many valid face pictures taken
img_counter = 0

# Repeatedly check if space or esc pressed. If esc, exit. If space, encode and save picture.
while True:
	# Grab a single frame of video
	ret, frame = cam.read()
	if not ret:
		break
	cv2.imshow("Learn Face", frame)
	k = cv2.waitKey(1)

	if k == 27:
		# ESC pressed
		print("Escape hit, closing...")
		break
	elif k == 32:
		# SPACE pressed
		
		# write the frame to file
		img_name = "opencv_frame.jpg"
		cv2.imwrite(img_name, frame)
		
		# get face encoding
		person_image = face_recognition.load_image_file(img_name)

		# check if a face was found
		if len(face_recognition.face_encodings(person_image)) > 0:

			print("Face Detected! Count " + str(img_counter))
			person_face_encoding = face_recognition.face_encodings(person_image)[0]

			# open face encoding data if exists
			try:
				pickle_in = open("facesData.pickle","rb")
				encoding_data = pickle.load(pickle_in)
			except IOError:
				encoding_data = {}
			
			if name in encoding_data:
				encoding_data[name].append(person_face_encoding)
			else:
				encoding_data[name] = [person_face_encoding]



			# write the face encoding to file
			pickle_out = open("facesData.pickle","wb")
			pickle.dump(encoding_data, pickle_out)
			pickle_out.close()

			img_counter += 1

cam.release()

cv2.destroyAllWindows()