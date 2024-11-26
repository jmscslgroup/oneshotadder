#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "oneshotadder";

// For Block oneshotadder/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Sub_oneshotadder_38;

// For Block oneshotadder/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Sub_oneshotadder_43;

// For Block oneshotadder/Subscribe2
SimulinkSubscriber<std_msgs::Int8, SL_Bus_oneshotadder_std_msgs_Int8> Sub_oneshotadder_14;

// For Block oneshotadder/Output Publisher/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Pub_oneshotadder_5;

// For Block oneshotadder/mode publisher/Publish
SimulinkPublisher<std_msgs::UInt8, SL_Bus_oneshotadder_std_msgs_UInt8> Pub_oneshotadder_1;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

