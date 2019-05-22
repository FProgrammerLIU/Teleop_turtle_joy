#include "teleop_turtle_joy.h"

#include "geometry_msgs/Twist.h"
#include "sensor_msgs/Joy.h"


TeleopTurtle::TeleopTurtle(ros::NodeHandle& nh):
    //ros::NodeHandle n;
	linear_joy_button_(1),
	angular_joy_button_(2) {

	nh.param("axis_linear", linear_joy_button_, linear_joy_button_);
	nh.param("axis_angular", angular_joy_button_, angular_joy_button_);
	nh.param("button_move", button_y_, button_y_);
	nh.param("button_linear", button_b_, button_b_);
	nh.param("button_angular", button_rig_, button_rig_);
	vel_pub_ = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
	joy_sub_ = nh.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::teleopCallback, this);
}

void TeleopTurtle::teleopCallback(const sensor_msgs::Joy::ConstPtr& joy)
{	
	button_joy_y_ = joy->buttons[button_y_];
	button_joy_b_ = joy->buttons[button_b_];
	button_joy_rig_ = joy->buttons[button_rig_];
	//keep pressing key y,move the turtlesim
	if (button_joy_y_)
	{	
		ROS_INFO("keep pressing key y,now move your action bars");
		geometry_msgs::Twist twist;

		twist_linear_speed_ = joy->axes[linear_joy_button_];
		twist_angular_speed_ = joy->axes[angular_joy_button_];
		//keep press key b,change linear_speed
		if (button_joy_b_) {
			ROS_INFO("speed of linear up");
			twist_linear_speed_ *= 5;
		}
		//keep press key rig,change angular_speed
		if (button_joy_rig_) {
			ROS_INFO("speed of angular up");
			twist_angular_speed_ *= 3;
		}

		twist.angular.z = twist_angular_speed_;
		twist.linear.x = twist_linear_speed_;

		vel_pub_.publish(twist);
	}

}

