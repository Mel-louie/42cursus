# Philosophers 🧵 📜    🚧 

<b>This project will learn you the basics of threading a process, how to make threads, and discover the mutex</b>


<img src=""
     alt="">

<figure>
	<blockquote>
		<p>Five philosophers, Aristotle, Kant, Spinoza, Marx, and Russell (the tasks) spend their time thinking and eating spaghetti. They eat at a round table with five individual seats. For eating each philosopher needs two forks (the resources). There are five forks on the table, one left and one right of each seat. When a philosopher cannot grab both forks it sits and waits. Eating takes random time, then the philosopher puts the forks down and leaves the dining room. After spending some random time thinking about the nature of the universe, he again becomes hungry, and the circle repeats itself.</p>
		<a href="https://rosettacode.org/wiki/Dining_philosophers">RosettaCode.org</a>
	</blockquote>
</figure>

In this project, the Philosophers also have to sleep.

- Tester
	- <a href="#uset">Usage</a>
	- <a href="">Link to tester.sh</a>
	- <a href="#cheatsheet">Cheatsheet for rapid tests</a>
- Download, install and use
	- <a href="#instal">Install</a>
	- <a href="#play">Use</a>
	- <a href="#bonus">Bonus</a>
- Ressources
	- <a href="#problem">Dinning Philosophers problem, explanations and solutions</a>
	- <a href="#thread">Programming with threads</a>


# Tester

<div id=uset></div></a>How to use the tester
Copy tester.sh in your project folder and then:
Inspire by differents testers on github.
Feel free to use and modify it.

```
~> bash tester.sh

```

<div id=cheatsheet></div></a>Cheatsheet
<table>
    <tr>
        <td><b>Test</b></td>
        <td><b>Résultat attendu</b></td>
    </tr>
    <tr>
        <td>./philo 1 200 200 200</td>
        <td>philo 1 ne prend qu'une fourchette et meurt au bout de 200 ms</td>
    </tr>
    <tr>
        <td>./philo 1 800 200 200</td>
        <td>	"			"			"		"			"	800 ms</td>
    </tr>
    <tr>
        <td><./philo 2 800 200 200</td>
        <td>personne ne meurt</td>
    </tr>
    <tr>
        <td>./philo 5 800 200 200 </td>
        <td>	"	"	"</td>
    </tr>
    <tr>
        <td>./philo 5 800 200 200 7</td>
        <td>la simulation s'arrete quand chaque philo a mange au moins 7 fois</td>
    </tr>
    <tr>
        <td>./philo 4 410 200 200</td>
        <td>personne ne meurt</td>
    </tr>
    <tr>
        <td>./philo 4 310 200 200</td>
        <td>un philo meurt</td>
    </tr>
    <tr>
        <td>./philo 4 500 200 1.2</td>
        <td>argument invalide</td>
    </tr>
    <tr>
        <td>./philo 4 0 200 200</td>
        <td>argument invalide</td>
    </tr>
    <tr>
        <td>./philo 4 -500 200 200 </td>
        <td>argument invalide</td>
    </tr>
    <tr>
        <td>./philo 4 500 200 2147483647</td>
        <td>un philo meurt au bout de 500 ms</td>
    </tr>
    <tr>
        <td>./philo 4 2147483647 200 200</td>
        <td>personne ne meurt</td>
    </tr>
    <tr>
        <td>./philo 4 214748364732 200 200</td>
        <td>argument invalide</td>
    </tr>
    <tr>
        <td>./philo 4 200 210 200</td>
        <td>un philo meurt, il faut afficher la mort avant 210 ms</td>
    </tr>
</table>

# Download, install and use

<div id=instal></div></a>To download and compile:

```git clone https://github.com/Mel-louie/42cursus.git && cd rank03_Philosophers/philo/ && make```

If everythings went fine, an executable (philo) has been created.

<div id=play></div>To lauch it:

```./philo [number_of_pholisophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]```

- number_of_philosophers: is the number of philosophers and also the numberof forks
- time_to_die: is in milliseconds, if a philosopher doesn’t start eating [time_to_die] milliseconds after starting his last meal or the beginning of the simulation, it dies
- time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
- time_to_sleep: is in milliseconds and is the time the philosopher will spendsleeping.
- number_of_times_each_philosopher_must_eat: argument is optional, if allphilosophers eat at least [number_of_times_each_philosopher_must_eat] the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher

Examples:
``` ./philo 5 800 200 200```
or
``` ./philo 5 800 200 200 7```

<div id=bonus></div><b>BONUS</b>

NB: my programm only containes the mandatoty part.
In this version the specific rules are:
- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented bya semaphore.
- Each philosopher should be a process and the main process should not be a philosopher

# Ressouces

<h3><div id=problem></div>Dinning Philosophers problem, explanations and solutions</h3>

<a href="https://sites.cs.ucsb.edu/~rich/class/old.cs170/notes/DiningPhil/index.html">📄 Dining Philosophers problem, explanations and some solutions in C (EN)</a><br />
<a href="https://www.youtube.com/watch?v=syMOLWlGjNg">📺 Operating System #30 Dining Philosophers Problem & Its solutions (EN)</a><br />
<a href="https://www.youtube.com/watch?v=HHoB2t_B6MI">📺 L-3.13: Dining philosophers Problem and Solution using Semaphore in Operating System (EN)</a><br />

<h3><div id=thread></div>Programming with threads</h3>

<a href="https://www.youtube.com/playlist?list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM">📺 Programming with threads, Jacob Sorber playlist on youtube (EN)</a><br />
<a href="https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2">📺 Unix Threads in C, CodeVault playlist on youtube (EN)</a><br />
<a href="https://youtu.be/o_GbRujGCnM">📺 Langage C #17 (les threads) (FR)</a><br />
<a href="https://franckh.developpez.com/tutoriels/posix/pthreads/">📄 Tutoriel pthread (FR)</a><br />
<a href=""></a><br />
<a href=""></a><br />
<a href=""></a><br />