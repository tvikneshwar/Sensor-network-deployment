Enabling ssh
************


In boot folder 

$touch ssh

Enabling Wifi:

In Boot folder

$sudo touch  wpa_supplicant.conf
sudo chmod 777  wpa_supplicant.conf
$vim wpa_supplicant.conf

country=SG
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
scan_ssid=1
ssid="ssid"
psk="pwd"
}


