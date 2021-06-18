#!/bin/bash

LC_NUMERIC="en_US.UTF-8"

#    COLORS    #

_BLACK="\033[30m"
_RED="\033[31m"
_GREEN="\033[32m"
_YELLOW="\033[33m"
_BLUE="\033[34m"
_VIOLET="\033[35m"
_CYAN="\033[36m"
_WHITE="\033[37m"
_END="\033[0m"
# Bold
_BBLACK="\033[1;30m"		# BLACK
_BRED="\033[1;31m"			# RED
_BGREEN="\033[1;32m"		# GREEN
_BYELLOW="\033[1;33m"		# YELLOW
_BBLUE="\033[1;34m"			# BLUE
_BPURPLE="\033[1;35m"		# PURPLE
_BCYAN="\033[1;36m"			# CYAN
_BWHITE="\033[1;37m"		# WHITE


nb_tests=50

function test
{
	mid=0
	max=0
	min=9999999
	printf "${_END}Results for ${_BCYAN}$nb_tests${_END} tests:"
	printf " [${_GREEN}Wait a moment...${_END}]"
	for i in `seq 0 $nb_tests`;
	do
		var=$(./push_swap `ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`|wc -l)
		if [ "$var" -lt "$min" ]
		then
			min=$var
		fi
		if [ "$var" -gt "$max" ]
		then
			max=$var
		fi
		mid=$(( $mid + $var))
	done
	printf "${_END}\nminimum:${_GREEN}$min${_END} | ${_END}maximum:${_RED}$max${_END}"
	printf " | average:    ${_YELLOW}"
	X=`echo "($mid) / ($nb_tests + 1)" | bc -l`
	printf %.0f "$X"
	printf "\n"
}

for arg in $@
do
	test $arg
done
