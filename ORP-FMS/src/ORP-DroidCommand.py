#!/usr/bin/python
#Imports Serial Stream module
from SerialStream import *
from time import sleep
#Variables
ORPDroidChannel = "/dev/ttyACM0"
frequency = 9600
#Initializes stream on ORP-Droid COM port and frequency
initStream(ORPDroidChannel, frequency)
#Makes sure the port is open
openStream()
#Sends 3 command to ORP-Droid
send("AAA")
sleep(4)
send("DDD")
sleep(4)
send("CCC")
sleep(4)
send("FFF")
sleep(4)

#
#Command List
#A-A Left Forward
#B-A Left Backward
#C-A Left Stop
#D-A Right Forward
#E-A Right Backward
#F-A Right Stop
#U-B Left Forward
#V-B Left Backward
#W-B Left Stop
#X-B Right Forward
#Y-B Right BackWard
#Z-B Right Stop
#

#Closes Serial port
closeStream()
exit()
