




find the device

ls /dev/tty*


// if no micrcontroller connected this shows novithing. then connect the mcu
ls /dev/ttyA*




// use correct ttyACM0  baseed on the above
source /opt/ros/jazzy/setup.bash
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyACM0





new terminal

source /opt/ros/jazzy/setup.bash
ros2 topic list

ros2 topic echo /chatter

or

ros2 topic info /chatter





https://www.linkedin.com/posts/daniel-christadoss-25441411_at-last-confirmation-that-microros-works-activity-7315783947093749760-IYA0?utm_source=share&utm_medium=member_desktop&rcm=ACoAABmRbRsBc_LrBG_2C93tjfsAk1HH-UumXW0






https://www.hackster.io/514301/micro-ros-on-esp32-using-arduino-ide-1360ca
