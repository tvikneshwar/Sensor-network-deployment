#import context  # Ensures paho is in PYTHONPATH
import serial
import paho.mqtt.publish as publish
#                 Topic              Message         Broaker
boo="viky"
publish.single("paho/test/single", boo, hostname="mqtt.eclipse.org")


#ser = serial.Serial("COM11", 9600)
#while True:
#     cc=str(ser.readline())
#     print(cc[2:][:-5])
#     out=(cc[2: ][:-5])
#     publish.single("paho/test/single", out, hostname="mqtt.eclipse.org")

