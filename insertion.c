#include <stdio.h>
#include <limits.h>
#define MAX 6

void nearestInsertion(int graph[MAX][MAX], int n) {
    int path[MAX + 1], visited[MAX] = {0};
    int pathLength = 2;
    int currentNode = 0, nextNode = -1, minDistance = INT_MAX;
    
    // Initialisation du chemin
    path[0] = 0;
    visited[0] = 1;
    printf("Insertion initiale : Client 0\n");
    
    // Trouver le premier voisin le plus proche
    for (int i = 1; i < n; i++) {
        if (graph[0][i] < minDistance) {
            minDistance = graph[0][i];
            nextNode = i;
        }
    }
    path[1] = nextNode;
    visited[nextNode] = 1;
    printf("Insertion du voisin le plus proche : Client %d (Distance = %d)\n", nextNode, minDistance);
    
    // Boucle principale d'insertion
    while (pathLength < n) {
        int bestIncrease = INT_MAX, bestCity = -1, bestPosition = -1;
        
        // Pour chaque ville non visitée
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // Tester toutes les positions possibles d'insertion
                for (int j = 0; j < pathLength; j++) {
                    int next = (j + 1) % pathLength;
                    // Calcul de l'augmentation de la distance
                    int increase = graph[path[j]][i] + graph[i][path[next]] - graph[path[j]][path[next]];
                    if (increase < bestIncrease) {
                        bestIncrease = increase;
                        bestCity = i;
                        bestPosition = j + 1;
                    }
                }
            }
        }
        
        // Décalage des éléments pour l'insertion
        for (int k = pathLength; k > bestPosition; k--) {
            path[k] = path[k - 1];
        }
        path[bestPosition] = bestCity;
        visited[bestCity] = 1;
        printf("Insertion du client %d (augmentation de distance = %d)\n", bestCity, bestIncrease);
        pathLength++;
    }
    
    // Fermeture du cycle
    path[pathLength] = path[0];
    
    // Affichage du résultat
    printf("\nChemin optimal approximé trouvé :\n");
    int totalDistance = 0;
    for (int i = 0; i <= pathLength; i++) {
        printf("Client %d", path[i]);
        if (i < pathLength) {
            printf(" -> ");
            totalDistance += graph[path[i]][path[i + 1]];
        }
    }
    printf("\nDistance totale du chemin : %d\n", totalDistance);
}

int main() {
    int n = 6;
    int graph[MAX][MAX] = {
        {0, 10, 15, 20, 0, 0},   // Client 0

        {10, 0, 35, 0, 25, 0},   // Client 1

        {15, 35, 0, 30, 0, 40},  // Client 2

        {20, 0, 30, 0, 0, 50},   // Client 3

        {0, 25, 0, 0, 0, 60},    // Client 4

        {0, 0, 40, 50, 60, 0}    // Client 5
    };
    nearestInsertion(graph, n);
    return 0;
}
