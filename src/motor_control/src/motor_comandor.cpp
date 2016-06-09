
#include "ros/ros.h"
#include "motor_control/comand_msg_1.h"

#include <stdio.h>
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "comandor");
 	ros::NodeHandle n;
 	ros::Publisher chatter_pub = n.advertise<motor_control::comand_msg_1>("comands", 1000);
 	ros::Rate loop_rate(10);

 	motor_control::comand_msg_1 msg;

 	while (ros::ok())
 	{
 		std::cout << "Enter (motor, target position) \n";
 		std::cin >> msg.motor >> msg.position;

 		chatter_pub.publish(msg);

 		ros::spinOnce();
 		loop_rate.sleep();
 	}


 	return 0;
} 	