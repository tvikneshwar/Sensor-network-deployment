# Sensor-network-deployment

Grafana Installation:

For Raspberry pi 2, and Raspberry Pi 3, 3B, 3B+, use:

  $ wget https://dl.grafana.com/oss/release/grafana_6.2.2_armhf.deb
  $ sudo dpkg -i grafana_6.2.2_armhf.deb
  $ sudo apt-get update
  $ sudo apt-get install grafana
  
   Start the server (init.d service)
    $ sudo systemctl enable grafana-server 
   $ sudo service grafana-server start
  
 

   
   
   This will start the grafana-server process as the grafana user, which was created during the package installation. The default HTTP port is 3000 and default user and group is admin.

To configure the Grafana server to start at boot time:

$ sudo update-rc.d grafana-server defaults


localhost:3000

admin
vikytnk511

For Installing plugin for grafana:

$ sudo grafana-cli plugins install grafana-polystat-panel


$ grafana-cli plugins install grafana-clock-panel

************************************************************************************************************************************

Influx db installation
######################


Refrence link: https://community.influxdata.com/t/raspberry-pi-installation-instructions/5515/6



curl -sL https://repos.influxdata.com/influxdb.key | sudo apt-key add - 
source /etc/os-release
test $VERSION_ID = "7" && echo "deb https://repos.influxdata.com/debian wheezy stable" | sudo tee /etc/apt/sources.list.d/influxdb.list
test $VERSION_ID = "8" && echo "deb https://repos.influxdata.com/debian jessie stable" | sudo tee /etc/apt/sources.list.d/influxdb.list
test $VERSION_ID = "9" && echo "deb https://repos.influxdata.com/debian stretch stable" | sudo tee /etc/apt/sources.list.d/influxdb.list

sudo apt-get update && sudo apt-get install influxdb

sudo systemctl enable influxdb
 
sudo systemctl start influxdb

.......................................................
MetaBrad
Jun '18
It took me a while to sort out the correct installation procedure for the entire TICK stack. The documentation for each component was not consistent. Can’t remember which, but one of them offered a nice sequence for auto-detecting and auto-selecting the right package. The summary steps are similar to @noahcrowley, but figures out the correct OS for you and lends itself to copy-paste:
.......................................................................................................................
 For setting user account and commands
 #####################################
Read also : https://docs.influxdata.com/influxdb/v1.5/query_language/authentication_and_authorization/
            http://blog.centurio.net/2018/10/28/howto-install-influxdb-and-grafana-on-a-raspberry-pi-3/
            


AGRI Stick:
###########

https://www.instructables.com/id/Agri-Stick/

sensor----rasp(loragw)------mqtt


check this:

https://github.com/raspberrypi-tw/lora-sx1276


important link: $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

https://github.com/tvikneshwar/lora_to_lora_mqtt_iot_cloud


$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

https://www.instructables.com/id/Intelligent-Street-Light-Using-LoRa/


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
https://github.com/YandievRuslan/sx1278-LoRa-RaspberryPi

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Esp32 installation in arduino ide
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

https://circuits4you.com/2018/02/02/installing-esp32-board-in-arduino-ide-on-ubuntu-linux/

Lora interface with esp32:

https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
https://github.com/sandeepmistry/node-sx127x/blob/master/API.md#create-device

https://www.takaitra.com/spi-device-raspberry-pi/

very  important:
****************
https://github.com/Inteform/PyLora

###########################################################################
https://www.seeedstudio.com/blog/2019/11/18/lora-and-lorawan-for-arduino-and-raspberry-pi/

https://medium.com/@sajinalex2011/basic-lora-to-lora-messaging-using-raspberry-pi-3b-tutorial-12db2ce8028b

https://www.deviceplus.com/raspberry-pi/how-to-run-arduino-sketches-on-raspberry-pi/4/

very important:
~~~~~~~~~~~~~~~
https://github.com/mayeranalytics/pySX127x

Nodered-serialport sensor data read
************************************

https://iotdesignpro.com/projects/interface-arduino-with-node-red-to-send-sensor-data-on-webpage

***************************************************************************************************************************************************

Serialport to mqtt Python

https://github.com/eclipse/paho.mqtt.python/tree/master/examples


Serial Read:

https://stackoverflow.com/questions/16077912/python-serial-how-to-use-the-read-or-readline-function-to-read-more-than-1-char






