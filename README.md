# Sensor-network-deployment

Grafana Installation:

For Raspberry pi 2, and Raspberry Pi 3, 3B, 3B+, use:

  $ wget https://dl.grafana.com/oss/release/grafana_6.2.2_armhf.deb
  $ sudo dpkg -i grafana_6.2.2_armhf.deb
  $ sudo apt-get update
  $ sudo apt-get install grafana
  
   Start the server (init.d service)
   
   $ sudo service grafana-server start
   
   
   This will start the grafana-server process as the grafana user, which was created during the package installation. The default HTTP port is 3000 and default user and group is admin.

To configure the Grafana server to start at boot time:

$ sudo update-rc.d grafana-server defaults


localhost:3000

admin
vikytnk511



