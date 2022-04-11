# TP1 : OpenMP 1

## Exercice 1 - Echauffement

## Exercice 2 - Variables partagées et variables privées

a est partagée (globlal elle existe depuis le début)
b : same
c : privée car on l'a donné private(c)
d : variable local à la région pararllel donc elle est privée à chaque thread par défault
e : variable local donc privée aussi

# Exercice 3

Q3 le plus efficace est de donner une itération en plus aux N%T premiers threads 

Q4 : k = 2 : accélérations moins bonnes que k =4096. Car memory bound : bande passante du bus mémoire 

k = 4096 : accélérations linéaires : compute bound : limité par puissance de calcul : dépendra du nb coeur


