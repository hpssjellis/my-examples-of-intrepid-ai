



# ROS 2 Basic Installation Guide

This guide provides the **simplest** installation steps for **basic ROS 2 functionality** on **Ubuntu Linux** and **Windows**.

---

## **Ubuntu Linux (Recommended: 22.04 LTS)**

### **1. Set up sources and keys**
Open a terminal and run:

```bash
sudo apt update && sudo apt install -y curl gnupg2 lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | sudo tee /usr/share/keyrings/ros-archive-keyring.gpg > /dev/null
echo "deb [signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

### **2. Install ROS 2 Base**
```bash
sudo apt update
sudo apt install -y ros-humble-ros-base
```
> *"ros-base" provides core ROS 2 tools without GUI tools like RViz or Gazebo.*

### **3. Set up environment**
Add ROS 2 to your shell profile:
```bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

### **4. Test Installation**
Run:
```bash
ros2 run demo_nodes_cpp talker
```
Then, in a **new terminal**, run:
```bash
ros2 run demo_nodes_py listener
```
If you see messages being sent and received, ROS 2 is working!

---

## **Windows (Easiest Setup)**

### **1. Install Dependencies**
- Install **[Chocolatey](https://chocolatey.org/install)** (if not already installed).
- Open **PowerShell as Administrator** and run:
  ```powershell
  choco install -y git cmake python3 curl
  ```

### **2. Install ROS 2**
- Download **[ROS 2 Humble (Base)](https://github.com/ros2/ros2/releases/download/release-humble-20230421/ros2-humble-20230421-windows-release-amd64.zip)**.
- Extract the zip file to `C:\ros2_humble`.

### **3. Set up environment**
Open **PowerShell** and run:
```powershell
$env:Path += ";C:\ros2_humble\bin"
echo 'source C:\ros2_humble\setup.bat' >> $PROFILE
```
Restart PowerShell to apply changes.

### **4. Test Installation**
Run:
```powershell
ros2 run demo_nodes_cpp talker
```
Then, in a **new PowerShell window**, run:
```powershell
ros2 run demo_nodes_py listener
```
If you see messages being sent and received, ROS 2 is working!

---

## **Next Steps**
- [ROS 2 Documentation](https://docs.ros.org/en/humble/)
- [ROS 2 Tutorials](https://docs.ros.org/en/humble/Tutorials.html)

This setup provides **basic ROS 2 functionality**. Let me know if you need support for USB devices (e.g., ESP32-S3)!


