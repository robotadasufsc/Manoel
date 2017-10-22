from exposer import SerialExposer # Imports the communication module
import sys
import time

if len(sys.argv) == 2:
    port = sys.argv[1]
else:
    print("Port not specified, using default port /dev/ttyACM0")
    port = "/dev/ttyACM0"

# Instantiate a "SerialExposer" object named "comm"
comm = SerialExposer(port)
time.sleep(1)
comm.requestAll()
print("starting")

# Transparent Mode, enables an easier interface to use
remote = comm.transparentLayer

# Equivalent to "testuint8 = 18;"

def setTo(num):
    remote.left_pwm = num
    print(num)
    time.sleep(5)

setTo(1500)
setTo(1000)
setTo(1500)
setTo(2000)
setTo(1500)
setTo(1500)

