# 42_push_swap 90%
This project asks you to sort data on a stack, with a limited instruction set, in as few moves as possible.


The game consists of 2 stacks named a and b.
- At the beginning:
  - a contains an arbitrary number of positive or negative integers, without duplicates
  - b is empty
  - The goal of the game is to sort a in ascending order.
  - To do this, you have only the following operations:
## Madatories operations
sa: swap a - swap the first 2 elements at the top of stacka. Do nothing if there is only one or no elements<br />
sb: swap b - swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements<br />
ss: sa and sb at the same time<br />

ra: rotate a - shift up all elements of stackaby 1. The first element becomes the last one<br />
rb: rotate b - shift up all elements of stackbby 1. The first element becomes the last one<br />
rr: ra and rb at the same time<br />

rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one<br />
rrb: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one<br />
rrr: rra and rrb at the same time<br />

pa: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty<br />
pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty<br />


## How to use
```
git clone git@github.com:Mel-louie/42cursus.git ; cd rank02_push_swap/ ; make
```
and then
```
> ./push_swap 5 1 3 2 4                       #the program prints the operations it uses to sort the stack:
> ra
> pb
> ra
> pb
> rra
> pa
> pa
```
or
```
> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
>   6                                      #operation number
> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_[OS] $ARG
> OK                                       #the checkers print OK if your stack is correctly sorted, KO if not
```
## Correction
To pass the correction, you need to have 80%.<br />
It means to succes 3 int and 5 int and have at least 3/5 and 3/5 to 100 int and 500 int:<br />
- 3 int: max 2-3 hits<br />
- 5 int: max 12 hits<br />
- 100 int:
  - Less than 700: 5pt
  - Less than 900: 4pt
  - Less than 1100: 3pt
  - Less than 1300: 2pt
  - Less than 1500: 1pt<br />
- 500 int:
  - Less than 5500: 5pt
  - Less than 7000: 4pt
  - Less than 8500: 3pt
  - Less than 10000: 2pt
  - Less than 11500: 1pt<br />

## Ressources
I used <a href="https://www.geeksforgeeks.org/insertion-sort/">insertion sort</a> and <a href="https://www.geeksforgeeks.org/quick-sort/">quick sort</a>, adapt with two stack and the limited amount of operations.<br />
<a href="https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a">push_swap tutorial: partitioning your stack with chunks</a><br />
<a href="https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e">push_swap tutorial: radix sort</a><br />

## Tester
I also coded a <a href="https://github.com/Mel-louie/42cursus/tree/main/rank02_push_swap_tester">script</a> to check your instruction number.
