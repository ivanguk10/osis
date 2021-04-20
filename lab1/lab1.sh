# !/bin/bash

echo "Username:"
ps -o user= -p $$ | awk '{print $1}'
echo
echo "Date:"
date
echo
echo "Current directory:"
echo $PWD
echo
echo "Count of processes:"
ps -A | wc -l
echo
echo "Uptime:"
cat /proc/uptime | head -n1 | cut -d " " -f1
