#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

class TeleopTurtle {
public:
    TeleopTurtle(ros::NodeHandle& n);
private:

    void teleopCallback(const sensor_msgs::Joy::ConstPtr& joy);
    int linear_joy_button_, angular_joy_button_, button_joy_y_, button_joy_b_, button_joy_rig_,
        button_y_, button_b_, button_rig_;
    double twist_linear_speed_, twist_angular_speed_;
    ros::Publisher vel_pub_;
    ros::Subscriber joy_sub_;
    
};