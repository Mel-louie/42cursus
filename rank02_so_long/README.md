# so_long... WIP

... et merci pour le poissons !
Projet de l'école 42 qui prend la forme d'un petit jeu 2D. Il est fait pour travailler avec des textures, des sprites et quelques éléments de gameplay très basiques.
Les objectifs de ce projet sont : rigueur, utilisation de C, utilisation d'algorithmes de base, recherche d'informations, etc. En tant que projet de conception graphique, il permet d'améliorer les compétences dans les domaines suivants : fenêtres, couleurs, événements, textures, etc. Il est impératif d'utiliser la bibliothèque graphique minilibx.

<img src=""
     alt="">

# Ressouceslol

## Minilibx

<a href="https://elearning.intra.42.fr/searches/search?query=minilibx">Vidéos de l'intra de 42 évoquant la minilibx</a><br />
<a href="https://harm-smits.github.io/42docs/libs/minilibx.html">Tuto minilibx fait par des étudiants</a><br />
<a href="https://github.com/keuhdall/images_example">Explanations on how the images are working on minilibx</a><br />
<a href="https://github.com/qst0/ft_libgfx#minilibx">minilibx's man and ressources</a><br />

## LEAKS
```
• SOLONG=so_long;MAP=map.ber;valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrind_log ./$SOLONG $MAP;grep -A1 "valgrind" valgrind_log|grep $SOLONG
• valgrind --leak-check=yes ./so_long map.ber
Cependant, valgrind a tendance à segfault avec la mlx.
Donc utiliser : 
-> la commande leaks avec un while (1) avant exit()
-> -fsanitize=address pour les overflows
-> astuces pour forcer leaks à être plus précis :
Placer un while (1) avant exit() qui traite l'event "Je veux quitter le
programme".
Recompiler le programme avec -g (sans fsanitize), et l'executer. Lancer le programme avec
MallocStackLogging=1 en ligne de commande.
Exemple : MallocStackLogging=1 ./a.out
Faire les tests, quitter le programme. Grâce au while, le programme se met en pause sur
exit(), et ne quitte pas. Dans un terminal séparé, lancer 'leaks [nom]'. Il devrait alors
afficher tous les détails des leaks, notamment la stack d'appel des fonctions jusqu'au
malloc de base. 
Pour libs externes incluses au projet (libft, mlx...) penser aussi à les compiler avec -g,
pour avoir une précision de debug maximale. 
```

## Textures et sprites
