#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "oneshotadder_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block oneshotadder/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Sub_oneshotadder_38;

// For Block oneshotadder/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Sub_oneshotadder_43;

// For Block oneshotadder/Subscribe2
extern SimulinkSubscriber<std_msgs::Int8, SL_Bus_oneshotadder_std_msgs_Int8> Sub_oneshotadder_14;

// For Block oneshotadder/Output Publisher/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_oneshotadder_std_msgs_Float64> Pub_oneshotadder_5;

// For Block oneshotadder/mode publisher/Publish
extern SimulinkPublisher<std_msgs::UInt8, SL_Bus_oneshotadder_std_msgs_UInt8> Pub_oneshotadder_1;

void slros_node_init(int argc, char** argv);

#endif
