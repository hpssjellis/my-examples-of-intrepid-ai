




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


