#include "ros/ros.h"
#include "teleop_turtle_joy.h"

int main(int argc, char** argv) {

    ros::init(argc, argv, "teleop_turtle");
    ros::NodeHandle node_h;
    TeleopTurtle teleopTurtle(node_h);
    ros::spin();
}