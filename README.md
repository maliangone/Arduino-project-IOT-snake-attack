# iot-snake-attack
Device Communications for the Internet of Things Report Snake- attack


1. Project Idea
This report details the project, which involved building a snake game controlled by Arduino
boards and a Python script game running on a laptop. In this project, I used two Arduino
boards: one acting as a master and the other as a slave.
● The master Arduino board was responsible for interacting with a Python script and
controlling a buzzer,
● while the slave Arduino board was connected to a joystick for controlling the snake
movement in the game
● The game will be displayed on the laptop that is connected to the Master
2. Implementation Details
Arduino Board Connections
I connected the two Arduino boards using the Two-Wire-Interface (TWI) communication
protocol, which allows for communication betIen a master (connected to the PC & Buzzer)
and a slave (connected to the joystick controller). The master Arduino served as the bridge
betIen the PC and the slave Arduino, enabling us to exchange data.
Joystick Integration
In this setup, the slave Arduino, assigned the I2C address 2, reads analog values from analog
pin A0 and analog pin A1 connected to the joystick’s X and Y values respectively. When a
request is received from the master, a requestHandler function stores the collected values in an
array to be passed from slave to master.
At the master arduino, a “newData” flag is used to serve as an indicator that new data is now
available for retrieval. For debugging purposes, the values read from the analog pins A0 and
A1, are also printed to the serial monitor.
Buzzer Integration
The master Arduino was equipped with a buzzer programmed to respond to specific events in
the Python script. When the snake collided with the food or goes into Game-Over condition, a
command is sent to the master Arduino to activate the buzzer, providing audio feedback to the
player.
Python Game Script Integration
The master Arduino continuously checks if there are any incoming commands from the Python
script using “Serial.available()”. When a command is received, the arduino will activate the
buzzer according to 3 conditions:
1. On default, there will be no buzzer sounds and the RGB LED will shine bright Green.
2. The “B” command reflects a game-over event, the buzzer will sound for 2 seconds and
the RBG LED will shine bright Red.
3 . The “F” command reflects a food event, buzzer sounds a short beep and the RGB LED
will continue to shine bright Green. .
The Python script uses the Pygame library to create a graphical interface for the snake game.
Various different functions will draw the game elements (snake, food, wall, status) and render it
on screen. A separate thread (read_joystick_thread) is created to read joystick values from the
Arduino via a serial connection and updates the python variables.
When certain game events occur, such as the snake consuming food or the player losing, the
Python script sends commands to the master Arduino via the serial connection. The 'F'
command is sent to indicate a food event, and the length of the snake is passed as a parameter.
The 'B' command is sent to indicate a game over event.
Future Work & its Challenges
#1 - Actuation to the RGB LED color intensity (dimmer to brighter) based on the increasing
snake length. Challenges - more actuations causes more time in the Arduinos to process and
creates lag-time to reflect the user’s joystick directions
#2 Integration of a button for the user to restart the game or voluntarily end the game.
Challenges - initializing the sensor onto Arduino and further python script enhancements.
#3 Using a rotary encoder for the user to increase / decrease the speed of the snake’s
movement and the difficulty of the game. Challenges - initializing the sensor onto Arduino and
further python script enhancements.

