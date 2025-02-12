# TSP-Algorithms
Projet de Structure de Données - Problème du Voyageur de Commerce (TSP)

Description du Projet

Ce projet a été réalisé dans le cadre du module "Structures des données avancées et Théorie des graphes" à la Faculté des Sciences et Techniques de Tanger. L'objectif principal est d'explorer les différentes méthodes de résolution du problème du voyageur de commerce (TSP), un problème classique en optimisation combinatoire et en recherche opérationnelle.

Auteurs

Farouk El Ouassif

Oussama Saouabeddine

Saad Mime

Youssef Belfalah

Zakaria Ouhchouch

Encadrant

Pr. Oufae Baida

Objectifs du Projet

Comprendre les fondements théoriques du TSP.

Implémenter plusieurs algorithmes de résolution, notamment :

Algorithme du plus proche voisin (Nearest Neighbor)

Algorithme de l'insertion la plus proche (Nearest Insertion)

Algorithme de l'insertion la plus lointaine (Farthest Insertion)

Algorithme de force brute (Brute Force)

Comparer les performances des algorithmes en termes de complexité et d'efficacité.

Implémentation

Le projet est implémenté en langage C et utilise une représentation sous forme de matrice d'adjacence pour modéliser le graphe du problème.

Algorithmes Utilisés

Plus Proche Voisin (Nearest Neighbor)

Algorithme glouton qui choisit à chaque étape le sommet non visité le plus proche.

Complexité : O(n^2)

Avantages : Rapidité d'exécution.

Inconvénients : Peut donner des solutions sous-optimales.

Insertion la Plus Proche (Nearest Insertion)

Construit progressivement le circuit en insérant les sommets proches de manière optimale.

Complexité : O(n^2)

Avantages : Meilleure solution que Nearest Neighbor.

Inconvénients : Légèrement plus complexe.

Insertion la Plus Lointaine (Farthest Insertion)

Commence avec un petit circuit et ajoute progressivement les sommets les plus éloignés.

Complexité : O(n^2)

Avantages : Fournit de meilleures solutions que les approches gloutonnes classiques.

Inconvénients : Plus lent que Nearest Neighbor.

Force Brute (Brute Force)

Explore toutes les permutations possibles du circuit pour trouver la solution optimale.

Complexité : O(n!)

Avantages : Garantie de l'optimalité.

Inconvénients : Temps de calcul exponentiel, impraticable pour des grandes instances.

Comparaison des Algorithmes

Algorithme

Complexité

Distance trouvée

Temps d'exécution

Force Brute

O(n!)

Optimal

Long

Nearest Neighbor

O(n^2)

Sous-optimal

Rapide

Nearest Insertion

O(n^2)

Bonne qualité

Moyenne

Farthest Insertion

O(n^2)

Très bonne qualité

Moyenne

Installation et Exécution

Prérequis

Compilateur C (GCC ou tout autre compilateur compatible)

Environnement de développement (CodeBlocks, Visual Studio Code, etc.)

Compilation

gcc tsp.c -o tsp -lm

Exécution

./tsp

Conclusion

Ce projet a permis d'explorer et de comparer plusieurs approches algorithmiques pour la résolution du problème du voyageur de commerce. Nous avons mis en évidence les compromis entre optimalité et temps d'exécution et discuté des applications réelles du TSP dans divers domaines (logistique, transport, biologie, etc.). 
