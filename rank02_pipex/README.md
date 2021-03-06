# Pipex 

<b>This project aims to make you understand a bit deeper two concets that you already know: the redirections and the pipes. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.</b>

<img src=""
     alt="">

<!-- 
// each cmd needs a stdin (input) and returns an output (to stdout)
   
    infile                                             outfile
as stdin for cmd1                                 as stdout for cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1    ->    end[1]        ↔        end[0]    ->    cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                           cmd2 stdin)
-->


<!-- - Tester
	- <a href="#uset">Usage</a>
	- <a href="https://github.com/Mel-louie/42cursus/blob/main/rank03_Philosophers/newPhilo/tester.sh">Link to tester.sh</a>
	- <a href="#cheatsheet">Cheatsheet for rapid tests</a>
- Download, install and use
	- <a href="#instal">Install</a>
	- <a href="#play">Use</a>
	- <a href="#bonus">Bonus</a>
- Ressources
	- <a href="#problem"></a>
	- <a href="#thread"></a> -->


# Download, install and use

<div id=instal></div></a>To download and compile:

```git clone https://github.com/Mel-louie/42cursus.git && cd rank02_pipex/ && make```

If everythings went fine, an executable (pipex) has been created.

<div id=play></div>To lauch it:

```./pipex file1 cmd1 cmd2 file2```

Examples:
``` ./pipex infile "ls -l" "wc -l" outfile```
should be the same as ```  “< infile ls -l | wc -l > outfile ``` in bash
or
``` ./pipex infile "grep a1" "wc -w" outfile```
should be the same as ```  “< infile grep a1 | wc -w > outfile ``` in bash

# Ressouces

<a href="https://aurelienbrabant.fr/blog/an-introduction-to-unix-pipes"> An introduction to UNIX pipes</a><br />
<a href="https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901">pipex tutorial — 42 project</a><br />
<a href=""></a><br />
<a href=""></a><br />
<a href=""></a><br />
<a href=""></a><br />


valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

