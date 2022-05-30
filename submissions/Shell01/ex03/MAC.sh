ifconfig | egrep -w "ether" | awk '{print $2}'
