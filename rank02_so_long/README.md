# so_long... 🐟 🐬 🦈

<b>... et merci pour le poissons !</b>

Projet de l'école 42 qui prend la forme d'un petit jeu 2D. Il est fait pour travailler avec des textures, des sprites et quelques éléments de gameplay très basiques.

Les objectifs de ce projet sont : rigueur, utilisation de C, utilisation d'algorithmes de base, recherche d'informations. En tant que projet de conception graphique, il permet d'améliorer les compétences dans les domaines suivants : fenêtres, couleurs, événements, textures. Il est impératif d'utiliser la bibliothèque graphique <a href="https://github.com/42Paris/minilibx-linux">minilibX.</a>

```❗compatible seulement avec linux```


- Télécharger, installer et jouer
	- <a href="#instal">installer</a>
	- <a href="#play">jouer</a>
	- <a href="#bonus">bonus</a>
	- <a href="#map">modifier la map</a>
- Ressources:
	- <a href="#mlx">minilibX</a>
	- <a href="#leaks">Leaks</a>
	- Textures et sprites
		- <a href="#tiles">Trouver des tiles</a>
		- <a href="#sprites">Créer et modifier les tiles</a>

<img src=""
     alt="">

# Télécharger, installer et jouer

<div id=instal></div>Tout d'abord, so_long n'est compatible qu'avec une distribution linux, car il utilise la <a href="https://github.com/42Paris/minilibx-linux">minilibX linux</a>.
Pour le télécharger et compiler :

```git clone https://github.com/Mel-louie/42cursus.git && cd rank02_so_long/so_long/ && make```

Si tout s'est bien passé, un executable so_long s'est créer.

<div id=play></div>Pour le lancer :

```./so_long map.ber```

Le but est de déplacer le dauphin jusqu'à la sortie, en ayant récolté tous les poissons.
Pour se déplacer : W, A, S, D (❗ clavier en QWERTY).

<div id=bonus></div><b>BONUS</b>

Les bonus apportent quelques features en plus :
- enemies causant un game over en cas de contact
- le compteur de mouvement s'affiche sur l'écran de jeu plutôt que dans le shell
- le sprite du joueur s'anime aux changements de directions

Pour jouer avec les bonus il suffit de compiler avec la règle ```make bonus```

Puis de lancer

```./so_long map_bonus.ber```


<div id=map></div><b>MAP</b>

La map peut être mofier, en suivant certaines règles :
- elle doit être composée des char 0, 1, P, C, E (+ S en cas de map bonus)
- elle doit être entourrée de murs ('1')
- elle doit être rectangulaire (pas de retour à la ligne en fin de fichier non plus)
- son extension doit être '.ber'
- elle ne doit pas être plus grande que l'écran (NB: chaque bloc est en 64x64)

# Ressouces

<h3><div id=mlx>minilibX</div></h3>

<a href="https://elearning.intra.42.fr/searches/search?query=minilibx">Vidéos de l'intra de 42 évoquant la minilibx</a><br />
<a href="https://harm-smits.github.io/42docs/libs/minilibx.html">Tuto minilibx fait par des étudiants</a><br />
<a href="https://github.com/keuhdall/images_example">Explanations on how the images are working on minilibx</a><br />
<a href="https://github.com/qst0/ft_libgfx#minilibx">minilibx's man and ressources</a><br />

<h3><div id=leaks>Leaks</div></h3>

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

<h3>Textures et sprites</h3>

<div id=tiles></div><b>Trouver des tiles</b><br \><br \>
<a href="https://itch.io/">itch.io</a> en cherchant dans les assets ;<br \>
<a href="https://opengameart.org/">OpenGameArt</a> ;<br \>
<a href="https://www.spriters-resource.com/">The Spriters resource</a>

<div id=sprites></div><b>Créer et modifier les tiles</b><br \><br \>
Photoshop, sur tous les posts de l'école ;<br \>
<a href="https://www.gimp.org/downloads/">Gimp</a> ;<br \>
<a href="https://lospec.com/resources/">Lospec</a>, plein de ressources et outils en ligne ;<br \>
Pour utiliser des images dans la minilibX, il faut convertir les png en xpm :<br \>
<a href="https://anyconv.com/fr/convertisseur-de-png-en-xpm/">convertisseur</a>
