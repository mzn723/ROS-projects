#!/usr/bin/env python

#  Recieves data from the pupil server and puplishes the gaze position through pupil_data topic

import rospy
import zmq
import json

from std_msgs.msg import String
from pupil_tracker.msg import gaze_position

#network setup
port = "5000"
context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.connect("tcp://127.0.0.1:"+port)
#filter by messages by stating string 'STRING'. '' receives all messages
socket.setsockopt(zmq.SUBSCRIBE, 'gaze_positions')

surface_name = "computer screen"

def talker():
	
	rospy.init_node('talker', anonymous=True)

	pub = rospy.Publisher('pupil_data', gaze_position, queue_size=10)
	rate = rospy.Rate(15) #hz
	while not rospy.is_shutdown():
		topic = socket.recv()
		msg = socket.recv()
		data_str = gaze_position()
		#print "================raw msg================\n", msg  
		gazePositions = json.loads(msg)
		for gazePosition_key, gazePosition_value in gazePositions.iteritems():
			if gazePosition_key == "norm_pos" :  # position relative to the world camera
				print gazePosition_key, ' x :',   gazePosition_value[0], ' y : ', gazePosition_value[1]
				data_str.x = gazePosition_value[0]
				data_str.y = gazePosition_value[1]
			elif gazePosition_key == "confidence" :  # confidence of the algorithm
				print gazePosition_key, gazePosition_value
				data_str.conf = gazePosition_value
			elif gazePosition_key == "realtime gaze on " + surface_name :  # position relative to the surface named "computer screen"
				print gazePosition_key, ' rx :',   gazePosition_value[0], ' ry : ', gazePosition_value[1]
				data_str.rx = gazePosition_value[0]
				data_str.ry = gazePosition_value[1]
		pub.publish(data_str)
		
		rate.sleep()	

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass