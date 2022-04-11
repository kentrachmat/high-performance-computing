# ICHP TP 4

## Equipe

Ce travail est à réaliser en équipe dont les membres sont (**groupe 4 du S6 Licence 3 Informatique**) :

- BENEDICTUS KENT **RACHMAT**
- Stevenson **Pather**

### Q1)

le meilleur option d'optimisation : -march=native -mtune=native -O3

avec la commande `run.sh` nous pouvons voir qu'avec la valeur croissante de `N`, la valeur de `GFLOP/S ` diminue.

### Q2)

### Q3)

avec `#pragma omp parallel for num_threads(nn) private(j,k)` ?

Toutes les variables présentes dans la boucle sont partagées entre les différents threads, sauf le compteur de boucles (chaque thread dispose d'une copie qu'il est libre de modifier, sans conséquence pour les autres threads). Les variables à protéger sont listées dans la clause private.

### DATA

```
./matmul 512
For n=512: total computation time (with gettimeofday()) : 0.756734 s
For n=512: performance = 0.354729 Gflop/s
+6.916512e+01  +6.916512e+01
+5.918460e+01  +5.918460e+01

+7.946186e+00  +7.946186e+00
+7.936391e+00  +7.936391e+00

-march=native -mtune=native
For n=512: total computation time (with gettimeofday()) : 0.713785 s
For n=512: performance = 0.376073 Gflop/s
+6.916512e+01  +6.916512e+01
+5.918460e+01  +5.918460e+01

+7.946186e+00  +7.946186e+00
+7.936391e+00  +7.936391e+00

-march=native -mtune=native -O3
For n=512: total computation time (with gettimeofday()) : 0.230535 s
For n=512: performance = 1.1644 Gflop/s
+6.916512e+01  +6.916512e+01
+5.918460e+01  +5.918460e+01

+7.946186e+00  +7.946186e+00
+7.936391e+00  +7.936391e+00

-march=native -mtune=native -ffast-math
For n=512: total computation time (with gettimeofday()) : 0.712281 s
For n=512: performance = 0.376868 Gflop/s
+6.916512e+01  +6.916512e+01
+5.918460e+01  +5.918460e+01

+7.946186e+00  +7.946186e+00
+7.936391e+00  +7.936391e+00

-march=native -mtune=native -funrool-loops
For n=512: total computation time (with gettimeofday()) : 0.725546 s
For n=512: performance = 0.369977 Gflop/s
+6.916512e+01  +6.916512e+01
+5.918460e+01  +5.918460e+01

+7.946186e+00  +7.946186e+00
+7.936391e+00  +7.936391e+00

```

Possible Levels of Parallelization
So there are at least 6 possible ways to
achieve parallelism, from coarse grain to fine
grain:
