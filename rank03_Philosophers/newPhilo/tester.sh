#!/bin/bash

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

FILE="errors_log"

make re
printf "${_BGREEN}\n(•_•)\t( •_•)>⌐■-■\t(⌐■_■)\n${_END}"
printf "${_BYELLOW}Philosophers successfully compiled\n\n${_END}"
printf "░█▀▀█ ░█─░█ ▀▀█▀▀ ░█     ▄▀▀▀▄   ▀▀█▀▀ ░█▀▀▀ ░█▀▀▀█ ▀▀█▀▀ ░█▀▀▀ ░█▀▀█ \n"
printf "░█▄▄█ ░█▀▀█ ─░█── ░█─── ░█  ░█── ─░█── ░█▀▀▀ ─▀▀▀▄▄ ─░█── ░█▀▀▀ ░█▄▄▀ \n"
printf "░█─── ░█─░█ ▄▄█▄▄ ░█▄▄▄  ▀▄▄▄▀   ─░█── ░█▄▄▄ ░█▄▄▄█ ─░█── ░█▄▄▄ ░█─░█ \n"
printf "\n\t\t${_BCYAN}Welcome to my 42 Philosophers tester.${_END}\n\n"

printf "Usage: copy this file in your project's folder, then:"
printf "\n\t${_GREEN}~ > bash tester.sh${_END}\n\n"
printf "In Case of a failed test, please check ./errors_log file\n\n"

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
        printf "\e[92m[+] Test #1-1 Success!\e[0m\n"
    else
        printf "\e[91m[+] Test #1 Failed!\e[0m\n"
        error_log $1 "Test #1" "Given 4 310 200 100 arguments to $1, a philosopher should die!"
    fi
    rm -rf "./log_$1"
	(./philo 1 800 200 200 > "./log_$1")&
    sleep 2
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
    if [ $output = "died" ];then
        printf "\e[92m[+] Test #1-2 Success!\e[0m\n\n"
    else
        printf "\e[91m[+] Test #1 Failed!\e[0m\n\n"
        error_log $1 "Test #1" "Given 4 310 200 100 arguments to $1, a philosopher should die!"
    fi
    rm -rf "./log_$1"
}

test_two ()
{
    printf "\e[94m[+] Test #2: Executing your program for 180 second, please wait...\e[0m\n"
    (./philo 4 410 200 200 > /dev/null)&
    i=1
    error=0
    while [ $i -lt 180 ];do
        printf "\r[%d...]" $i
        pgrep $1 > /dev/null
        if [ "$?" -ne 0 ];then
            printf "\r\e[91m[+] Test #2 Failed\e[0m\n\n"
            error_log $1 "Test #2" "Given 4 410 200 200 arguments to $1, no philosopher should die! - Philo dies at $i secondes"
            error=1
			break
        fi
        sleep 1
        i=$(( $i + 1 ))
    done
    sleep 1
    if [ $error -eq 0 ];then
        pkill $1
        printf "\r\e[92m[+] Test #2 Success\e[0m\n\n"
    fi
}

test_three ()
{
    printf "\e[94m[+] Test #3: Executing your program for 180 second, please wait...\e[0m\n"
    (./philo 5 800 200 200 > /dev/null)&
    i=1
    error=0
    while [ $i -lt 180 ];do
        printf "\r[%d...]" $i
        pgrep $1 > /dev/null
        if [ "$?" -ne 0 ];then
            printf "\r\e[91m[+] Test #3 Failed\e[0m\n\n"
            error_log $1 "Test #3" "Given 4 800 200 200 arguments to $1, no philosopher should die! - Philo dies at $i secondes"
            error=1
            break
        fi
        sleep 1
        i=$(( $i + 1 ))
    done
    sleep 1
    if [ $error -eq 0 ];then
        pkill $1
        printf "\r\e[92m[+] Test #3 Success\e[0m\n\n"
    fi
}

test_four ()
{
    (./philo 4 410 200 200 $3 > "./log_$1")&
    sleep 2
    pgrep $1 > /dev/null
    if [ "$?" -eq 1 ];then
        lines=$(grep eating "./log_$1" | wc -l)
        if [ $lines -ge $4 ];then
            printf "\t\e[92m[+] Test #4 - $5 Success\e[0m\n"
        else
            printf "\t\e[91m[+] Test #4 - $5 Failed\e[0m\n"
            error_log $1 "Test #4" "Given 4 410 200 200 $3 arguments to $1, $1 should only be stopped if each philosopher ate at least $3 times!"
        fi
    else
        printf "\t\e[91m[+] Test #4  -$5 Failed\e[0m\n"
        error_log $1 "Test #4" "Given 4 410 200 200 $3 arguments to $1, $1 should stop!"
        pkill $1
    fi
    rm -rf "./log_$1"
}

test_five ()
{
    printf "\e[94m[+] Test #5 in progress, please wait...\e[0m\n"
    i=1
    t=0
    error=0
    while [ $i -le 10 ];do
        (./philo 2 60 60 60 > "./log_$1")&
        sleep 1
        pgrep $1 > /dev/null
        if [ "$?" -eq 1 ];then
            printf "\r[%d/10]" $i
            tmp=$(grep died -m 1 "./log_$1" | awk '{print $1}' | sed 's/[^0-9]*//g')
            if [ $i -gt 1 ];then
                x=$(expr $tmp - $t)
                x=${x#-}
                if [ $x -gt 10 ];then
                    printf "\r\e[91m[+] Test #5 Failed\e[0m\n"
                    error_log $1 "Test #5" "Given 2 60 60 60 arguments to $1, the time difference of each death shouldn't be bigger than 10ms!"
                    error=1
                    break
                fi
            else
                t=$tmp
            fi
        else
            printf "\r\e[91m[+] Test #5 Failed\e[0m\n"
            error_log $1 "Test #5" "Given 2 60 60 60 arguments to $1, a philosopher should die!"
            pkill $1
            break
        fi
        i=$(( $i + 1 ))
    done
    
    if [ $error -eq 0 ];then
        printf "\r\e[92m[+] Test #5 Success\e[0m\n"
    fi
}

tests ()
{
	 printf "\n[============[Testing philo]==============]\n"

    target="philo"

    test_one $target $1
    
    test_two $target $1

    test_three $target $1
    
    printf "\e[94m[+] Test #4 in progress, please wait...\e[0m\n"
    test_four $target $1 7 28 1
    test_four $target $1 10 40 2
    test_four $target $1 12 48 3
    test_four $target $1 15 60 4

    test_five $target $1
    rm -rf "./log_$target"
}

tests
