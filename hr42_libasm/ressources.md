# Ressouces

https://github.com/mmeisson/tests_libasm/blob/master/SPOILERS.md

## ASM sur OSx

<a href="http://macappstore.org/nasm/">Installer NASM sur OSx</a><br />
<a href="http://programmersought.com/article/31511396273/;jsessionid=D7C553CE95EBA33D82451AD8F94EEC37">Si la compile ne fonctionne pas</a><br />
<a href="http://thexploit.com/secdev/mac-os-x-64-bit-assembly-system-calls/">Numéros des 'classes' syscalls sur OSx</a><br />
<a href="https://opensource.apple.com/source/xnu/xnu-792.13.8/osfmk/mach/i386/syscall_sw.h">Numéros des 'classes' syscalls sur OSx bis</a><br />
<a href="https://syscalls.w3challs.com/?arch=x86_64">syscall.h</a> et <a href="https://www.thegeekstuff.com/2010/10/linux-error-codes/">errno.h</a> sur MacOS Mojave et après :<br />
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/syscall.h<br />
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/errno.h<br />
<a href="https://forums.freebsd.org/threads/is-apples-osx-based-on-a-standard-fbsd.3790/">Is Apple's OSX based on a standard FBSD? - Le point</a><br />

## Tutos et cours assembleur

<a href="https://openclassrooms.com/fr/courses/1464031-en-profondeur-avec-lassembleur">Cours OpenClassrooms - OK pour faire un tour d'horizon de l'assembleur</a> et <a href="https://openclassrooms.com/fr/courses/2288321-apprenez-a-programmer-en-assembleur-x86">celui-ci</a><br />
<a href="https://www.youtube.com/playlist?list=PLcT0DaY68xGzzmj47WSbb8XaIwWFjVlKz">Vidéos YT apprendre l'assembleur FR</a><br />
<a href="https://www.youtube.com/playlist?list=PLan2CeTAw3pFOq5qc9urw8w7R-kvAT8Yb">Vidéos YT apprendre l'assembleur EN</a><br />
<a href="https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/x64-architecture">x64 architecture</a><br />
<a href="https://magnushoff.com/blog/asmtut-1/">Tuto ASM 64 sous OSx récent</a><br />
<a href="https://www.fil.univ-lille1.fr/portail/index.php?dipl=L&sem=S6&ue=PDM&label=Documents">Cours univertité de Lille sur l'assembleur et l'architecture du processeur</a><br />
<a href="https://chamilo.grenoble-inp.fr/courses/ENSIMAG3MM1LDB/document/asm_intro.pdf">Introduction à l’architecture Intel Grenoble INP</a><br />
<a href="https://beta.hackndo.com/assembly-basics/">Base de l'assembleur</a><br />
<a href="http://www.uqac.ca/rebaine/8INF212/unbonresumeassembleur.pdf">Les instructions de l'assembleur</a><br />
<a href="https://www.it-swarm.dev/fr/assembly/quelle-est-la-fonction-des-instructions-push-pop-utilisees-sur-les-registres-de-lassemblage-x86/970218005/">Utilisation de push et pop</a>
<a href="https://beta.hackndo.com/stack-introduction/#prologue---%C3%A9pilogue">Prologue et épilogue de fonctions</a>
<a href="https://stackoverflow.com/questions/42208087/are-the-prologue-and-epilogue-mandatory-when-writing-assembly-functions">Nécessité des prologues et épilogues de fonctions</a>
<a href="https://stackoverflow.com/questions/22123863/or-al-al-in-x86-assembly">Instruction OR AL, AL</a>
<a href="https://stackoverflow.com/questions/4749585/what-is-the-meaning-of-xor-in-x86-assembly">Instruction XOR</a>
<a href="https://www.gladir.com/LEXIQUE/ASM/movsb.htm">Instruction MOVSB</a>

## La stack

<a href="https://beta.hackndo.com/stack-introduction/">Fonctionnement de la stack</a>

## CPU Flags

<a href="https://www.youtube.com/watch?v=zf1bg3WCFUI">Vidéo point et fonctionnement des différents flags EN</a><br />
<a href="https://www.youtube.com/watch?v=MxGW2WurKuM">Vidéo Carry Flag arithmétique EN</a><br />
<a href="https://www.geeksforgeeks.org/flag-register-8086-microprocessor/">Le flags register</a><br />
<a href="https://en.wikipedia.org/wiki/Direction_flag">Point sur le Direction Flag (DF)</a><br />
<a href="https://stackoverflow.com/questions/41090297/default-state-of-direction-flag-df-during-x86-program-execution">Installer NASM sur OSxDF par défaut</a><br />

## ERRNO

<a href="https://www.youtube.com/watch?v=IZiUT-ipnj0">Vidéo très bonne explication du fonctionnement de errno</a><br />
<a href="https://jameshfisher.com/2016/12/13/c-errno/">Explications define errno</a><br />
<a href="https://www.freebsd.org/doc/en_US.ISO8859-1/books/developers-handbook/x86-return-values.html">Gestion des erreurs en assembleur</a><br />
<a href="http://beefchunk.com/documentation/sys-programming/os-freebsd/asm_freebsd_fr.html">Gestion des erreurs en assembleur - moins clair mais avec plus d'infos</a><br />

