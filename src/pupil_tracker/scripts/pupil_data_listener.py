#!/usr/bin/env python

#  Subscriber to the pupil_data topic

import rospy
from std_msgs.msg import String
from pupil_tracker.msg import gaze_position

qo = 0

def callback(data):
    #rospy.loginfo("gaze_position (%f,%f), confidence: %f, gaze position on surface (%f,%f)" % (data.x, data.y, data.conf, data.rx, data.ry))

    if data.conf > 0.6 :
	    global qo

	    if data.x > 0.5 and data.y > 0.5:
	    	qc = 1
	    elif data.x > 0.5 and data.y < 0.5:
	    	qc = 4
	    elif data.x < 0.5 and data.y < 0.5:
	    	qc = 3
	    elif data.x < 0.5 and data.y > 0.5:
	    	qc = 2	

	    if qo != qc :
	    	qo = qc
	    	if qc == 1:
	    		rospy.loginfo("You are looking at TOP RIGHT")
	    	elif qc == 2:
	    		rospy.loginfo("You are looking at TOP LEFT")
	    	elif qc == 3:
	    		rospy.loginfo("You are looking at BOTTOM LEFT")	
	    	elif qc == 4:
	    		rospy.loginfo("You are looking at BOTTOM RIGHT")
			

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('pupil_data', gaze_position, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()