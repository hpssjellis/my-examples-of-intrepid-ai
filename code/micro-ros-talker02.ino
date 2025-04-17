
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>

#define LED_PIN LED_BUILTIN

// Error checking macros
#define MY_CHECK(fn) { if ((fn) != RCL_RET_OK) { myErrorLoop(); }}
#define MY_SOFT_CHECK(fn) { if ((fn) != RCL_RET_OK) {} }

// Micro-ROS objects
rcl_publisher_t myPub;
std_msgs__msg__String myMsg;
rclc_executor_t myExec;
rclc_support_t mySupport;
rcl_allocator_t myAlloc;
rcl_node_t myNode;
rcl_timer_t myTimer;

// Message content and counter
char myText[50];
int myNum = 0;

// Blink LED if there's an error
void myErrorLoop() {
  while (1) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}

// Send message every timer tick
void myTimerCallback(rcl_timer_t * timer, int64_t lastTime) {
  RCLC_UNUSED(lastTime);
  if (timer != NULL) {
    snprintf(myText, sizeof(myText), "Hello World: %d", myNum++);
    myMsg.data.data = myText;
    myMsg.data.size = strlen(myText);
    myMsg.data.capacity = sizeof(myText);
    MY_SOFT_CHECK(rcl_publish(&myPub, &myMsg, NULL));
  }
}

void setup() {
  set_microros_transports(); // Required Micro-ROS setup

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(2000); // Let things settle

  myAlloc = rcl_get_default_allocator();

  MY_CHECK(rclc_support_init(&mySupport, 0, NULL, &myAlloc));
  MY_CHECK(rclc_node_init_default(&myNode, "talker", "", &mySupport));
  MY_CHECK(rclc_publisher_init_default(
    &myPub, &myNode,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
    "chatter"));

  MY_CHECK(rclc_timer_init_default(
    &myTimer, &mySupport,
    RCL_MS_TO_NS(1000), // Every 1 sec
    myTimerCallback));

  MY_CHECK(rclc_executor_init(&myExec, &mySupport.context, 1, &myAlloc));
  MY_CHECK(rclc_executor_add_timer(&myExec, &myTimer));
}

void loop() {
  delay(100);
  MY_SOFT_CHECK(rclc_executor_spin_some(&myExec, RCL_MS_TO_NS(100)));
}
