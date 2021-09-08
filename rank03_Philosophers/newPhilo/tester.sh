#!/bin/zsh

#    COLORS    #
_BLACK="\033[30m"
_RED="\033[31m"
_GREEN="\e[92m"
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

FILE=errors_log

make re
printf "${_GREEN}\n(•_•)\t( •_•)>⌐■-■\t(⌐■_■)\n${_END}"
printf "${_BYELLOW}philo successfully compiled\n\n${_END}"
printf "░█▀▀█ ░█─░█ ▀▀█▀▀ ░█──  ▄▀▀▀▄   ▀▀█▀▀ ░█▀▀▀ ░█▀▀▀█ ▀▀█▀▀ ░█▀▀▀ ░█▀▀█ \n"
printf "░█▄▄█ ░█▀▀█ ─░█── ░█── ░█   █   ─░█── ░█▀▀▀ ─▀▀▀▄▄ ─░█── ░█▀▀▀ ░█▄▄▀ \n"
printf "░█─── ░█─░█ ▄▄█▄▄ ░█▄▄▄ ▀▄▄▄▀   ─░█── ░█▄▄▄ ░█▄▄▄█ ─░█── ░█▄▄▄ ░█─░█ \n"
printf "\n\t\t${_BCYAN}Welcome to my 42 Philosophers tester.${_END}\n\n"


printf "Usage: copy this file in your project folder and then:\n"
printf "\t${_GREEN}~> bash tester.sh${_END}\n"
printf "In Case of a failed test, please check ./errors_log file for more information\n"

if [ -f "$FILE" ]; then
	rm "$FILE"
fi

error_log ()
{
	echo "[$1-$2]: $3" >> ./errors_log
}

test_one ()
{
	(./philo 4 310 200 100 > "./log_$1")&
	sleep 2
	pkill $1
	output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	if [ $output = "died" ];then
		printf "${_GREEN}"
		echo "Test #1.1 Sucess!"
	else
		printf "${_RED}"
		echo "Test #1.1 Failed!"
		error_log $1 "Test #1.1" "Given 4 310 200 100 arguments to $1, a philosopher should die!"
	fi
	printf "${_END}"
	rm -rf "./log_$1"
	(./philo 1 800 200 200 > "./log_$1")&
	sleep 2
	pkill $1
	output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	if [ $output = "died" ];then
		printf "${_GREEN}"
		echo "Test #1.2 Sucess!"
		echo
	else
		printf "${_RED}"
		echo "Test #1.2 Failed!"
		echo
		error_log $1 "Test #1.2" "Given 1 800 200 200 arguments to $1, the unique philosopher should die!"
	fi
	printf "${_END}"
	rm -rf "./log_$1"
}

test_two ()
{
	printf "${_CYAN}"
	echo "Test #2: Executing your program for 180 second, please wait..."
	(./philo 4 410 200 200 > /dev/null)&
	i=1
	error=0
	while [ $i -lt 180 ];do
		printf "\r[%d...]" $i
		pgrep $1 > /dev/null
		if [ "$?" -ne 0 ];then
			printf "${_RED}"
			echo " Test #2 Failed"
			echo
			error_log $1 "Test #2" "Given 4 410 200 200 arguments to $1, no philosopher should die! - Philo is dead the $i seconde"
			error=1
			break
		fi
		sleep 1
		i=$(( $i + 1 ))
	done
	sleep 1
	if [ $error -eq 0 ];then
		pkill $1
		printf "${_GREEN}"
		echo " Test #2 Sucess!"
		echo
	fi
	printf "${_END}"
}

test_three ()
{
	printf "${_CYAN}"
	echo "Test #3: Executing your program for 180 second, please wait..."
	(./philo 5 800 200 200 > /dev/null)&
	i=1
	error=0
	while [ $i -lt 180 ];do
		printf "\r[%d...]" $i
		pgrep $1 > /dev/null
		if [ "$?" -ne 0 ];then
			printf "${_RED}"
			echo " Test #3 Failed"
			error_log $1 "Test #3" "Given 4 800 200 200 arguments to $1, no philosopher should die! - Philo is dead the $i seconde"
			error=1
			break
		fi
		sleep 1
		i=$(( $i + 1 ))
	done
	sleep 1
	if [ $error -eq 0 ];then
		pkill $1
		printf "${_GREEN}"
		echo " Test #3 Sucess!"
	fi
	printf "${_END}"
}

test_four ()
{
	(./philo 4 410 200 200 $3 > "./log_$1")&
	sleep 12
		lines=$(grep eating "./log_$1" | wc -l)
		if [ $lines -ge $3 ];then
			printf "${_GREEN}"
			echo " Test #4: $3 Sucess!"
		else
			printf "${_RED}"
			echo " Test #4: $3 Failed"
			error_log $1 "Test #4" "Given 4 410 200 200 $3 arguments to $1, $1 should only be stopped if each philosopher ate at least $3 times! They ate: $lines time, in total"
		fi
	printf "${_END}"
	rm -rf "./log_$1"
}

test_five ()
{
	printf "\n${_CYAN}"
	echo "Test #5 in progress, please wait..."
	i=1
	t=0
	error=0
	while [ $i -le 10 ];do
		(./philo 2 60 60 60 > "./log_$1")&
		sleep 8
		pgrep $1 > /dev/null
		printf "\r[%d/10]" $i
		tmp=$(grep died -m 1 "./log_$1" | awk '{print $1}' | sed 's/[^0-9]*//g')
		if [ $i -gt 1 ];then
			x=$(expr $tmp - $t)
			x=${x#-}
			if [ $x -gt 10 ];then
				printf "${_RED} Test #5 Failed\n"
				error_log $1 "Test #5" "Given 2 60 60 60 arguments to $1, the time difference of each death shouldn't be bigger than 10ms!"
				error=1
				break
			fi
		else
			t=$tmp
		fi
		i=$(( $i + 1 ))
	done

	if [ $error -eq 0 ]; then
		printf "${_GREEN}"
		echo " Test #5 Sucess!"
	fi
	printf "${_END}\n"
}

tests()
{
	printf "\n\t\t[Testing philo]\n\n"

	target="philo"

	test_one $target $1
	
	test_two $target $1

	test_three $target $1
	
	printf "\n${_CYAN}"
	echo "Test #4 in progress, please wait..."
	printf "${_END}"
	test_four $target $1 7 28 1
	test_four $target $1 10 40 2
	test_four $target $1 12 48 3
	test_four $target $1 15 60 4

	test_five $target $1
	rm -rf "./log_$target"
}

tests