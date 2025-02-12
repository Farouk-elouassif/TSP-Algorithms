#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10

int n; // Nombre de clients
int graph[MAX_NODES][MAX_NODES]; // Matrice de distances
int best_path[MAX_NODES]; // Chemin optimal
int current_path[MAX_NODES]; // Chemin courant
int visited[MAX_NODES]; // Marqueurs de visite
int min_distance = INT_MAX; // Distance minimale

// Fonction pour calculer la distance totale d'un chemin
int calculate_distance(int path[]) {
    int total_distance = 0;
    for (int i = 0; i < n - 1; i++) {
        total_distance += graph[path[i]][path[i + 1]];
    }
    total_distance += graph[path[n - 1]][path[0]]; // Retour au point de départ
    return total_distance;
}

// Fonction récursive pour explorer toutes les permutations
void tsp_bruteforce(int level) {
    if (level == n) {
        int distance = calculate_distance(current_path);
        if (distance < min_distance) {
            min_distance = distance;
            for (int i = 0; i < n; i++) {
                best_path[i] = current_path[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            current_path[level] = i;
            tsp_bruteforce(level + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    // Initialisation des variables
    n = 5;
    int input_graph[MAX_NODES][MAX_NODES] = {
        {0, 29, 20, 21, 16},
        {29, 0, 15, 29, 28},
        {20, 15, 0, 15, 14},
        {21, 29, 15, 0, 4},
        {16, 28, 14, 4, 0},
    };

    // Copie de la matrice d'entrée dans la matrice globale
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = input_graph[i][j];
        }
    }

    // Initialisation des marqueurs de visite
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Appel à l'algorithme brute force
    tsp_bruteforce(0);

    // Affichage des résultats
    printf("Chemin optimal : ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", best_path[i]);
    }
    printf("%d\n", best_path[0]); // Retour au point de départ
    printf("Distance minimale : %d\n", min_distance);

    return 0;
}