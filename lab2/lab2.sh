# !/bin/bash

max_value=20000
value=$(($(date +%N)%max_value))
my_mul=15

next_int (){
value=$((value*my_mul%max_value));
}
while true
	do
	printf "\033c"
	next_int
	x=$((value%($(tput cols)-5)))
	next_int
	y=$((value%$(tput lines)))
	tput cup $x $y
	echo $(date +%T)
	sleep 8
done
