# HighStakes-936B

# X Drive Controls

This repository contains the code for controlling an X Drive using the OkapiLib library in PROS.

## Setup

The X Drive is set up with four motors, connected to ports 1, 3, 2, and 4. The dimensions of the drive are set with a wheel diameter of 4 inches and a wheelbase width of 10 inches. The gearset is set to blue.

A rotation sensor is connected to port 5.

## Controls

The X Drive is controlled using a controller. The left Y-axis controls the forward and backward movement, the left X-axis controls the strafing movement, and the right X-axis controls the rotation.

The rotation sensor is used to calculate the field-oriented controls. This means that the forward and strafing controls are adjusted based on the current orientation of the robot, allowing for more intuitive control.

## Operation

The `opcontrol` function contains the main control loop. It continuously reads the controller inputs and adjusts the drive controls accordingly. The loop runs every 20 milliseconds.
