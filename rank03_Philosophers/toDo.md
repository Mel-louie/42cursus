🔘 check si mes explications sont bonnes (cheat sheet bullet points dans le cahier)
🔘 reviser (onglets mac school)
🔘 tester sur mac os
🔘 tester tous les tests de la cheatsheet
<br />
✅ normer
✅ probleme quand philo dies apres que tous est pris une fork (ne sort pas du prog) > voir test_one
✅ commenter et documenter 
✅ tester valgrind leaks (linux)
✅ parsing
✅ vérif le nb max de philos en correction
✅ add time to die et number must eat
✅  nettoyer blocknum/moni
✅  nettoyer fflush
✅  print les changements de status


cheatsheet

test 	resultat attendu 
./philo 1 200 200 200 	philo 1 ne prend qu'une fourchette et meurt au bout de 200 ms
./philo 1 800 200 200
./philo 2 800 200 200 	personne ne meurt
./philo 5 800 200 200 	personne ne meurt
./philo 5 800 200 200 7 	la simulation s'arrete quand chaque philo a mange 7 fois
./philo 4 410 200 200 	personne ne meurt
./philo 4 310 200 200 	un philo meurt
./philo 4 500 200 1.2 	argument invalide
./philo 4 0 200 200 	argument invalide
./philo 4 -500 200 200 	argument invalide
./philo 4 500 200 2147483647 	un philo meurt au bout de 500 ms
./philo 4 2147483647 200 200 	personne ne meurt
./philo 4 214748364732 200 200 	argument invalide
./philo 4 200 210 200 	un philo meurt, il faut afficher la mort avant 210 ms