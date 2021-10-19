#include <ros/ros.h>
#include <std_msgs/Int64.h>


class Number {

    private:
    
    ros::Publisher pub,pub1;
    ros::Subscriber number_subscriber;
    ros::Timer timer;
    int64_t number_count_var = 0;
    int64_t count =0;
    
     public:
    Number(ros::NodeHandle *nh) 
    {
    
    	pub = nh->advertise<std_msgs::Int64>("/number1", 10);  
    	pub1 = nh->advertise<std_msgs::Int64>("/number2", 10);  
     	number_subscriber = nh->subscribe("/number_count", 1000, &Number::callback_number, this);  
     	timer = nh->createTimer(ros::Duration(0.1), &Number::loop, this);
     	timer.start();
     	
    }
    
    void loop(const ros::TimerEvent& event){
    
	    std_msgs::Int64 msg;
	    msg.data = 1;
	    ROS_INFO("%ld", msg.data);
	    pub.publish(msg);
	    std_msgs::Int64 msg1;
	    msg1.data = number_count_var;
	    ROS_INFO("%ld", msg1.data);	    
	    pub1.publish(msg1);
	    
    }
    
    void callback_number(const std_msgs::Int64::ConstPtr& msg1)

    {
  
	  ROS_INFO("I heard int data: [%ld]", msg1->data);
	  number_count_var = number_count_var + msg1->data;
	  count++;
	  if(count == 10)
	  ROS_INFO("I heard int data: [%ld]", number_count_var);
	   count==0;
	  
   }



};

int main (int argc, char **argv)
{
    ros::init(argc, argv, "node2");
    ros::NodeHandle nh;
    Number nc = Number(&nh); 
    ros::spin();
    //return 0;
}

