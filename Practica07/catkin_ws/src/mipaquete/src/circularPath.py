#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def circularPath():
    pubTurtleCircularPath = rospy.Publisher('/turtle1/cmd_vel', Twist,  queue_size=10)
    rospy.init_node('circularPathern', anonymous=True)
    rate = rospy.Rate(1) # 1hz
    vel_msg = Twist()

    # linear  x   y   z  circular   x   y   z
    #       [2.0,0.0,0.0]         [0.0,0.0,1.8]

    #linear
    vel_msg.linear.x = 1.0
    vel_msg.linear.y = 0.0
    vel_msg.linear.z = 0.0

    #angular
    vel_msg.angular.x = 0.0
    vel_msg.angular.y = 0.0
    vel_msg.angular.z = 1.5

    while not rospy.is_shutdown():
        rospy.loginfo(vel_msg)
        pubTurtleCircularPath.publish(vel_msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        circularPath()
    except rospy.ROSInterruptException:
        pass