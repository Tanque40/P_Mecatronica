#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

void messageCb( const std_msgs::Empty& toggle_msg){
  if (digitalRead(13) == LOW){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
