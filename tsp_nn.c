#include <stdio.h>
#include <stdbool.h>
#include <float.h> // Pour DBL_MAX (valeur infinie)

// Définitions
#define MAX_CLIENTS 6

// Fonction pour trouver le voisin le plus proche
int trouver_voisin_proche(int client_actuel, bool visites[], int nombre_clients, double graphe[MAX_CLIENTS][MAX_CLIENTS]) {
    double distance_min = DBL_MAX; // Initialiser avec l'infini
    int voisin_proche = -1;

    for (int i = 0; i < nombre_clients; i++) {
        if (!visites[i] && i != client_actuel && graphe[client_actuel][i] < distance_min) {
            distance_min = graphe[client_actuel][i];
            voisin_proche = i;
        }
    }

    return voisin_proche;
}


double resoudre_tsp_nn(double graphe[MAX_CLIENTS][MAX_CLIENTS], int nombre_clients, int chemin[]) {
    bool visites[MAX_CLIENTS] = {false}; // Indique si un client a été visité
    double distance_totale = 0.0;

    // Début à partir du premier client (indice 0)
    int client_actuel = 0;
    chemin[0] = client_actuel;
    visites[client_actuel] = true;

    // Construction du chemin
    for (int i = 1; i < nombre_clients; i++) {
        int prochain_client = trouver_voisin_proche(client_actuel, visites, nombre_clients, graphe);
        chemin[i] = prochain_client;
        distance_totale += graphe[client_actuel][prochain_client];
        visites[prochain_client] = true;
        client_actuel = prochain_client;
    }

    // Retour au point de départ
    distance_totale += graphe[client_actuel][0];
    chemin[nombre_clients] = 0; // Retour au point de départ

    return distance_totale;
}

// Fonction pour afficher le chemin
void afficher_chemin(int chemin[], int nombre_clients, double distance_totale) {
    printf("Chemin trouvé : ");
    for (int i = 0; i <= nombre_clients; i++) { // Inclut le retour au départ
        printf("client %d ", chemin[i]);
    }
    printf("\nDistance totale : %.2f\n", distance_totale);
}

int main() {
    // Matrice d'adjacence des distances
    double graphe[MAX_CLIENTS][MAX_CLIENTS] = {
        {0, 10, 15, 20, 0, 0},   // Client 0
        {10, 0, 35, 0, 25, 0},   // Client 1
        {15, 35, 0, 30, 0, 40},  // Client 2
        {20, 0, 30, 0, 0, 50},   // Client 3
        {0, 25, 0, 0, 0, 60},    // Client 4
        {0, 0, 40, 50, 60, 0}

    };
    int nombre_clients = 6; // Nombre total de clients

    // Résoudre le TSP avec NN
    int chemin[MAX_CLIENTS + 1]; // Stocke le chemin (y compris retour au départ)
    double distance_totale = resoudre_tsp_nn(graphe, nombre_clients, chemin);

    // Afficher les résultats
    afficher_chemin(chemin, nombre_clients, distance_totale);

    return 0;
}
