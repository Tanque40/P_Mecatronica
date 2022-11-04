#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

PI = 3.1415926535897

def convertToRadians(angle):
    return angle * 2 * PI / 360

def modifyVelMsg(vel_msg, x, y, z, alpha, betha, theta):
    #linear
    vel_msg.linear.x = x
    vel_msg.linear.y = y
    vel_msg.linear.z = z

    #angular
    vel_msg.angular.x = convertToRadians(alpha)
    vel_msg.angular.y = convertToRadians(betha)
    vel_msg.angular.z = convertToRadians(theta)


def rectangularPath():
    pubTurtleRectangularPath = rospy.Publisher('/turtle1/cmd_vel', Twist,  queue_size=10)
    rospy.init_node('rectangularPathern', anonymous=True)
    rate = rospy.Rate(0.5) # 1hz
    vel_msg = Twist()

    distance = 2

    i = 0
    while not rospy.is_shutdown():
        if i % 5 == 0:
            modifyVelMsg(vel_msg, distance, 0.0, 0.0, 0.0, 0.0, 0.0)
        elif i % 5 == 1:
            modifyVelMsg(vel_msg, 0.0, 0.0, 0.0, 0.0, 0.0, 90)
        elif i % 5 == 2:
            modifyVelMsg(vel_msg, distance, 0.0, 0.0, 0.0, 0.0, 0.0)
        elif i % 5 == 3:
            modifyVelMsg(vel_msg, 0.0, 0.0, 0.0, 0.0, 0.0, 90.0)
        elif i % 5 == 4:
            modifyVelMsg(vel_msg, distance, 0.0, 0.0, 0.0, 0.0, 0.0)

        rospy.loginfo(vel_msg)
        pubTurtleRectangularPath.publish(vel_msg)

        rate.sleep()
        i += 1

if __name__ == '__main__':
    try:
        rectangularPath()
    except rospy.ROSInterruptException:
        pass