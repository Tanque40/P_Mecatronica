#!/usr/bin/env python
import rospy
from std_msgs.msg import Empty

def publisherToArduino():
    pub = rospy.Publisher('/chatter', Empty,  queue_size=10)
    rospy.init_node('toggle_led', anonymous=False)
    rate = rospy.Rate(1) # 1hz
    
    i = 0
    while not rospy.is_shutdown():
        rospy.loginfo(i)
        pub.publish()
        rate.sleep()
        i=i+1

if __name__ == '__main__':
    try:
        publisherToArduino()
    except rospy.ROSInterruptException:
        pass