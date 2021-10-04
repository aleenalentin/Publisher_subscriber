  #include <ros/ros.h>
#include <std_msgs/Int64.h>
class Number {

    private:
    
    ros::Publisher pub;
    ros::Subscriber number_subscriber, number_subscriber1;
    ros::Timer timer;
    
     public:
    Number(ros::NodeHandle *nh) 
    {
    
    	pub = nh->advertise<std_msgs::Int64>("/number_count", 10);    
     	number_subscriber = nh->subscribe("/number1", 1000, &Number::callback_number1, this);  
     	number_subscriber1 = nh->subscribe("/number2", 1000, &Number::callback_number2, this); 
     	timer = nh->createTimer(ros::Duration(0.1), &Number::loop, this);
     	timer.start();
     	
    }
    
    void loop(const ros::TimerEvent& event){
    
	    std_msgs::Int64 msg;
	    
	    msg.data = 122;
	    ROS_INFO("%ld", msg.data);
	    
	    pub.publish(msg);
    }
    
    void callback_number1(const std_msgs::Int64::ConstPtr& msg1)

{

   
  ROS_INFO("I heard int data: [%ld]", msg1->data);

}

 void callback_number2(const std_msgs::Int64::ConstPtr& msg2)

{

   
  ROS_INFO("I heard int data: [%ld]", msg2->data);

}

};

int main (int argc, char **argv)
{
    ros::init(argc, argv, "node1");
    ros::NodeHandle nh;
    Number nc = Number(&nh); 
    ros::spin();
    //return 0;
}

