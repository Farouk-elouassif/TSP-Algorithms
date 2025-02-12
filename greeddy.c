#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 6
#define MAX_EDGES (MAX_NODES * (MAX_NODES - 1)) / 2

// Structure pour représenter une arête
typedef struct {
    int src, dest, weight;
} Edge;

// Structure pour représenter un graphe
typedef struct {
    int V, E; // Nombre de nœuds et d'arêtes
    Edge edges[MAX_EDGES]; // Liste des arêtes
} Graph;

// Fonction pour créer un graphe
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

// Fonction pour ajouter une arête
void addEdge(Graph* graph, int src, int dest, int weight, int index) {
    graph->edges[index].src = src;
    graph->edges[index].dest = dest;
    graph->edges[index].weight = weight;
}

// Fonction de comparaison pour trier les arêtes par poids
int compareEdges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

// Fonction pour trouver le parent d'un nœud (utilisé pour détecter les cycles)
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Fonction pour unir deux ensembles (utilisé pour éviter les cycles)
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// Fonction pour résoudre le TSP avec une approche adaptée de Kruskal
void tspKruskal(Graph* graph, int startNode) {
    int V = graph->V;
    Edge result[V]; // Pour stocker le cycle hamiltonien
    int e = 0; // Index pour result[]
    int i = 0; // Index pour les arêtes triées

    // Trier toutes les arêtes par ordre croissant de poids
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Tableau pour suivre les parents des nœuds
    int parent[V];
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    // Construire le cycle hamiltonien
    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        // Ajouter l'arête si elle ne forme pas de cycle
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    // Ajouter l'arête de retour pour fermer le cycle
    result[e] = (Edge){result[e - 1].dest, startNode, graph->edges[i - 1].weight};

    // Afficher le cycle hamiltonien
    printf("Cycle hamiltonien (TSP) :\n");
    for (i = 0; i < V; i++) {
        printf("%d -> %d (poids %d)\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V = 6; // Nombre de nœuds
    int E = 9; // Nombre d'arêtes

    // Créer le graphe
    Graph* graph = createGraph(V, E);

    // Ajouter les arêtes (matrice d'incidence)
    addEdge(graph, 0, 1, 10, 0);
    addEdge(graph, 0, 2, 15, 1);
    addEdge(graph, 0, 3, 20, 2);
    addEdge(graph, 1, 2, 35, 3);
    addEdge(graph, 1, 4, 25, 4);
    addEdge(graph, 2, 3, 30, 5);
    addEdge(graph, 2, 5, 40, 6);
    addEdge(graph, 3, 5, 50, 7);
    addEdge(graph, 4, 5, 60, 8);

    // Résoudre le TSP avec l'approche adaptée de Kruskal
    tspKruskal(graph, 0); // Commencer à partir du nœud 0

    // Libérer la mémoire
    free(graph);

    return 0;
}