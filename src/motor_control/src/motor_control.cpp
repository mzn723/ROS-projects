//ROS
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "motor_control/comand_msg_1.h"
#include "motor_control/jointState.h"
#include <ros/package.h>
//C++
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
//Communication
#include "serial/serial.h"

#define NOT_FOUND 2147483647

serial::Serial serialConn;
int32_t  motorID = -1;
int32_t   targetPos;

bool startMotor (int motor_ID)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "A\r";

    msg = ss.str();
    serialConn.write(msg);
    ROS_DEBUG("Starting motor");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "A";
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool stopMotor (int motor_ID)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "S1\r";

    msg = ss.str();
    serialConn.write(msg);
    ROS_DEBUG("Stopping motor");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "S1";
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool changeDirection (int motor_ID, bool direction) //0 = ccw, 1 = cw 
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "d" << direction << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Stetting direction");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "d" << direction;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool reduceSpeed (int motor_ID)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "-\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Reducing speed -100 stp/s");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "-";
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool increaseSpeed (int motor_ID)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "+\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Increasing speed +100 stp/s");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "+";
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setPhaseCurrent (int motor_ID, int x) 
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "i" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting phase current");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "i" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setPhaseCurrentAtStandStill (int motor_ID, int x) 
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "r" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting phase current at stand still");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "r" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setEncoderType (int motor_ID, int x)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_rotenc_type=" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting encoder type");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_rotenc_type=" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setMaxSpeed (int motor_ID, int speed) //steps/s
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "o" << speed << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("max speed %d step/s", speed);
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "o" << speed;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setTargetPosition (int motor_ID, int pos) //steps
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "s" << pos << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Going to position: %d ", pos);
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "s" << pos;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;    
}

bool setStepMode (int motor_ID, int x)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "g" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("step mode 1/%d", x);
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "g" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;  
}

bool setPositioningMode (int motor_ID, int x) // 1 = relative pos , 2 = absolute pos
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "p" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting mode");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "p" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false; 
}

bool setAccelerationRamp (int motor_ID, int x) 
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << "b" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting acceleration ramp");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << "b" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;
}

bool enableCL (int motor_ID, int mode) //Closed loop
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_enable" << mode << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Enabling Closed Loop");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_enable" << mode;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;
}

bool disableCL (int motor_ID)
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_enable0\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Disabling Closed Loop");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_enable0";
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;
}

bool setPolePairs (int motor_ID, int x) 
{
    std::string output_buffer, msg;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_motor_pp=" << x << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting pole pairs");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_motor_pp=" << x;
    if (output_buffer.compare (ss.str()) == 0)
        return true;
    else
        return false;
}

bool setEncoderResolution (int motor_ID, int increments, int revolutions)
{
    std::string output_buffer, msg;
    bool check;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_rotenc_inc=" << increments << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting number of increments");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_rotenc_inc=" << increments;
    if (output_buffer.compare (ss.str()) == 0)
        check = true;
    else
        check = false;

    ss.str("");

    ss << "#" << motor_ID << ":CL_rotenc_rev=" << revolutions << "\r";
    msg = ss.str();

    serialConn.write(msg);
    ROS_DEBUG("Setting number of revolutions");
    output_buffer = serialConn.readline();
    ROS_DEBUG("Response: %s", output_buffer.c_str());

    output_buffer = output_buffer.substr(0, output_buffer.find_first_of("\r"));
    ss.str("");
    ss << motor_ID << ":CL_rotenc_rev=" << revolutions;
    if (output_buffer.compare (ss.str()) == 0 && check)
        return true;
    else
        return false;

}

int getMotorPosition(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << "C\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    if (output_buffer.find_first_of("C") == std::string::npos)
        return NOT_FOUND;

    int pos, i;
    pos = output_buffer.find_first_of("+-");
    substr = output_buffer.substr (pos); 

    i = atoi(substr.c_str());

    return i;
}

int getEncoderPosition(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << "I\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    if (output_buffer.find_first_of("I") == std::string::npos)
        return NOT_FOUND;

    int pos, i;
    pos = output_buffer.find_first_of("+-");
    substr = output_buffer.substr (pos); 

    i = atoi(substr.c_str());

    return i;
}

int getAccelerationRamp(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << "Zb\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    if (output_buffer.find_first_of("Zb") == std::string::npos)
        return NOT_FOUND;

    int pos, i;
    pos = output_buffer.find_first_of("+-");
    substr = output_buffer.substr (pos); 

    i = atoi(substr.c_str());

    return i;
}

int getSpeed(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":v\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    if (output_buffer.find_first_of(":v") == std::string::npos)
        return NOT_FOUND;

    int pos, i;
    pos = output_buffer.find_first_of("+-");
    substr = output_buffer.substr (pos); 

    i = atoi(substr.c_str());

    return i;
}

bool setAnalogInput(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":Capt_iAnalog=0\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    ROS_INFO("Response: %s", output_buffer.c_str());

    if (output_buffer.find_first_of(":Capt_iAnalog") == std::string::npos)
        return false;
    return true;
}

void getAnalogInput(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << "Z:Capt_iAnalog\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    ROS_INFO("Response: %s", output_buffer.c_str());

    // if (output_buffer.find_first_of(":Capt_iAnalog") == std::string::npos)
    //     return NOT_FOUND;

    // int pos, i;
    // pos = output_buffer.find_first_of("+-");
    // substr = output_buffer.substr (pos); 

    // i = atoi(substr.c_str());

    // return i;
}

void getVoltage(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":Capt_iVolt\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    ROS_INFO("Response: %s", output_buffer.c_str());

    // if (output_buffer.find_first_of(":Capt_iVolt") == std::string::npos)
    //     return NOT_FOUND;

    // int pos, i;
    // pos = output_buffer.find_first_of("+-");
    // substr = output_buffer.substr (pos); 

    // i = atoi(substr.c_str());

    // return i;
}

void setTemp(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":Capt_lTemp=0\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    ROS_INFO("Response: %s", output_buffer.c_str());

    // if (output_buffer.find_first_of(":Capt_iVolt") == std::string::npos)
    //     return NOT_FOUND;

    // int pos, i;
    // pos = output_buffer.find_first_of("+-");
    // substr = output_buffer.substr (pos); 

    // i = atoi(substr.c_str());

    // return i;
}

void getTemp(int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":temp_adc\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    ROS_INFO("Response: %s", output_buffer.c_str());

    // if (output_buffer.find_first_of(":Capt_iVolt") == std::string::npos)
    //     return NOT_FOUND;

    // int pos, i;
    // pos = output_buffer.find_first_of("+-");
    // substr = output_buffer.substr (pos); 

    // i = atoi(substr.c_str());

    // return i;
}




bool isCLEnabled (int motor_ID)
{
    std::string output_buffer, msg, substr;
    std::stringstream ss;
    ss << "#" << motor_ID << ":CL_is_enabled\r";
    msg = ss.str();

    serialConn.write(msg);
    output_buffer = serialConn.readline();

    if (output_buffer.find_first_of(":CL_is_enabled") == std::string::npos)
        return false;

    int pos, i;
    pos = output_buffer.find_first_of("+-");
    substr = output_buffer.substr (pos); 

    i = atoi(substr.c_str());

    return (i != 0);
}

uint32_t initilizeMotor (int motorID)
{
    uint32_t  max_speed = 1000; 
    /* switch (motorID)
            *each motor has its own settings*
       case 1: max speed = x, positioning mode = ... 
       ...
                                                        */
    if ( !setMaxSpeed (motorID, max_speed) ) 
        ROS_ERROR("Could not set max speed!");
    if ( !setAccelerationRamp (motorID, 55800) ) 
        ROS_ERROR("Could not set acceleration ramp!");
    if ( !setPositioningMode (motorID, 2) ) //Absolute positioning
        ROS_ERROR("Could not set positioning mode!");
    if ( !setTargetPosition (motorID, 0) ) 
        ROS_ERROR("Could not set target position!");
    if ( !setStepMode (motorID, 2) ) 
        ROS_ERROR("Could not set step mode!");

    if (!isCLEnabled (motorID))
    {
        if ( !enableCL (motorID, 1) ) 
            ROS_ERROR("Could not enable closed loop mode!");
    }

    return max_speed;
}

void comandsCallback (const motor_control::comand_msg_1::ConstPtr& msg)
{
    motorID = msg->motor;
    targetPos = msg->position;
    
    ROS_INFO("\n======================\nMotor:\t\t %u\nTarget Position: %d\n======================", motorID, targetPos); 
}

/* Operating on torque mode */
void torqueMode (int motorID, ros::NodeHandle n)
{
    ros::Publisher chatter_pub = n.advertise<motor_control::jointState>("jointState", 1000); //publishes the joint state
    uint32_t  max_speed = 1000; 
    if ( !setMaxSpeed (motorID, max_speed) ) 
        ROS_ERROR("Could not set max speed!");
    if ( !setAccelerationRamp (motorID, 55800) ) 
        ROS_ERROR("Could not set acceleration ramp!");
    if ( !setPositioningMode (motorID, 15) ) //Absolute positioning
        ROS_ERROR("Could not set positioning mode!");
    if ( !setStepMode (motorID, 2) ) 
        ROS_ERROR("Could not set step mode!");
    if (!isCLEnabled (motorID))
    {
        if ( !enableCL (motorID, 1) ) 
            ROS_ERROR("Could not enable closed loop mode!");
    }

    startMotor (motorID);
    motor_control::jointState jointState;

    while (ros::ok())
    {
        jointState.motorID = motorID;
        jointState.position = getEncoderPosition (motorID);
        jointState.velocity = getSpeed (motorID);

        chatter_pub.publish(jointState);

        if (getSpeed (motorID) == 0)
        {
            break;
        }
    }
    stopMotor (motorID);
}

/* Operating on position mode */
void positionMode (ros::NodeHandle n)
{
    int32_t   currentPos = 0;
    int32_t   distance = 0;
    uint32_t  max_speed = 0; 
    int       currentMotor = -1;
    int       input = 0;

    ros::Subscriber sub = n.subscribe("comands", 1000, comandsCallback); //subscribe to the commands
    ros::Publisher chatter_pub = n.advertise<motor_control::jointState>("jointState", 1000); //publishes the joint state

    ROS_INFO("Waiting for commands...");

   


    while (ros::ok())
    {

        while ((targetPos == currentPos && motorID == currentMotor) || motorID == -1)
        {
            ros::spinOnce();
        } 

        if (motorID != currentMotor)
        {
            max_speed = initilizeMotor (motorID);
            usleep (50000);
        }

        currentMotor = motorID;
        distance = abs (targetPos - currentPos);
        currentPos = targetPos;

        if ( !setTargetPosition (motorID, targetPos) ) 
            ROS_ERROR("Could not set target position!");
        if ( !startMotor (motorID) ) 
            ROS_ERROR("Could not start motor %d!", motorID);

        ros::Time before = ros::Time::now ();
        ros::Duration travelTime ((distance/max_speed) + 0.6);
        motor_control::jointState jointState;

        while ((ros::Time::now () - before) < travelTime)
        {
            jointState.motorID = motorID;
            jointState.position = getEncoderPosition (motorID);
            jointState.velocity = getSpeed (motorID);

            chatter_pub.publish(jointState);
        }

        ROS_INFO("Done ... ");
        if ( getMotorPosition (motorID) != NOT_FOUND ) 
            ROS_INFO("current position  = %d", getMotorPosition (motorID));
        if ( getEncoderPosition (motorID) != NOT_FOUND ) 
            ROS_INFO("current position (encoder) = %d", getEncoderPosition (motorID));
        

    }
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "motor_control");
	ros::NodeHandle n;
    std::string output_buffer, msg;
	serialConn.setBaudrate(115200);
    serialConn.setPort("/dev/ttyUSB0");
    serialConn.setTimeout(serial::Timeout::max(), 250, 0, 250, 0);
    ROS_DEBUG("Trying to open a connection...");
    try
    {
        serialConn.open();
    }
    catch (serial::IOException e)
    {
        ROS_ERROR("An IO exception occurred");
    }

    if (serialConn.isOpen()) 
        ROS_DEBUG("Connected.");
    else
    {
        ROS_ERROR("Not connected!");
        return 0;
    }

     usleep (100);

    //for the gripper motor (stops after reaching a certain torque threshold)
    torqueMode (2/* ID of the gripper motor*/, n);

    //for other motors
    //positionMode (n);

	return 0;
}
