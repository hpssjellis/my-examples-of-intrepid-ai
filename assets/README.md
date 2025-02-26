I just like dumping my images on github. I will also try a video or use a gif


ROS 2 Setup
Run ROSBridge WebSocket Server (Port 9182 as requested):
sh
Copy
Edit
ros2 launch rosbridge_server rosbridge_websocket.launch.py port:=9182
Test ROS 2 Send & Receive:
Send a test message:
sh
Copy
Edit
ros2 topic pub /ros_to_web std_msgs/String "{data: 'Hello from ROS'}"
See messages sent from the web:
sh
Copy
Edit
ros2 topic echo /web_to_ros
