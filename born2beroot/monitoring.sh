#!/bin/bash
architecture=$(uname -a)
physical_cores=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
virtual_cores=$(grep "processor" /proc/cpuinfo | wc -l)
mem_total=$(free --mega | grep Mem: | awk '{print $2}')
mem_used=$(free --mega | grep Mem: | awk '{print $3}')
mem_perce=$(free --mega | grep Mem: | awk '{printf("%.2f"), $3/$2*100}')
disk_total=$(df -Bg | grep '/dev/' | grep -v '/boot' | awk '{ft += $2} END {print ft}')
disk_used=$(df -Bm | grep '/dev/' | grep -v '/boot' | awk '{ut += $3} END {print ut}')
disk_perce=$(df -Bm | grep '/dev/' | grep -v '/boot' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpu_load=$(expr 100 - $(vmstat 1 2 | tail -1 | awk '{printf $15}') | xargs | awk '{printf("%.1f%%"), $1 + $3}')
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvm_active=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
connections=$(ss -ta | grep ESTAB | wc -l)
user_logs=$(users | wc -w)
network="IP $(hostname -I) ($(ip link show | awk '$1 == "link/ether" {print $2}'))"
sudo_cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall	"	#Architecture: ${architecture}
	#CPU physical: ${physical_cores}
	#vCPU: ${virtual_cores}
	#Memory Usage: ${mem_used}/${mem_total}MB (${mem_perce}%)
	#Disk Usage: ${disk_used}/${disk_total}Gb (${disk_perce}%)
	#CPU load: ${cpu_load}
	#Last boot: ${last_boot}
	#LVM use: ${lvm_active}
	#TCP Connections: ${connections} ESTABLISHED
	#User log: ${user_logs}
	#Network: ${network}
	#Sudo: ${sudo_cmds} cmd"
