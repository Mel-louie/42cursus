<p>Ce projet est clair et efficace. Vous devez recoder printf. Vous aurez dès lors la possibilité de le réutiliser dans vos futurs projets. Ce projet porte principalement sur les arguments à taille variable.</p>

<p>:boom: Ajout de ft_dprintf : feature perso. Ne fait pas partie du sujet.</p>

# ft_printf 100%

<table>
    <tr>
        <td><b>Nom du programme</b></td>
        <td>libftprintf.a</td>
    </tr>
    <tr>
        <td><b>Fichier de rendu</b></td>
        <td>*.c, */*.c, *.h, */*.h, Makefile</td>
    </tr>
    <tr>
        <td><b>Makefile</b></td>
        <td>all, clean, fclean, re, bonus</td>
    </tr>
    <tr>
        <td><b>Fonctions externes autorisées</b></td>
        <td>malloc, free, write, va_start, va_arg, va_copy, va_end</td>
    </tr>
    <tr>
        <td><b>Libft autorisées</b></td>
        <td>oui</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>Une librairie qui contient ft_printf, une fonction qui marche comme le vrai printf</td>
    </tr>
</table>

•Le prototype de ft_printf devra être : int ft_printf(const char *, ...);

•Vous devez recoder la fonction printf de la libc

•Vous ne devez pas gérer de buffer, contrairement au vrai printf

•Vous devez gérer les conversions suivantes : cspdiuxX%

•Vous devez gérer n’importe quelle combinaison de flags ’-0.*’ et la taille de champ minimale avec toutes les conversions

•Votre rendu sera comparé au vrai printf 

```
man 3 printf / man 3 stdarg4
```
# Bonus part [non réalisés]

•Si la partie obligatoire n’est pas parfaite, ne faites pas les bonus

•Vous n’avez pas d’obligation de faire tous les bonus

•Gérez une ou plusieurs des conversions suivantes : nfge

•Gérez un ou plusieurs des flags suivants : l ll h hh

•Gérez tous les flags suivants : ’# +’ (espace est un flag valide)
