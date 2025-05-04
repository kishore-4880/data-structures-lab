#include <iostream>
using namespace std;
//Program for Graph ADT with Prim’s, Kruskal’s, and Dijkstra’s algorithms 
const int MAX_VERTICES = 100;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function prototypes
void insertEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], Edge edges[], int& edgeCount, int n, int src, int dest, int weight);
void displayGraph(Edge edges[], int edgeCount);
void primMST(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n);
void kruskalMST(Edge edges[], int edgeCount, int n);
void dijkstra(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int start);

// Helper function prototypes for Kruskal's
int find(int parent[], int i);
void unionSets(int parent[], int rank[], int x, int y);

//Main program
int main() {
    int n;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeCount = 0;

    cout << "Enter the number of vertices in the graph (max " << MAX_VERTICES << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_VERTICES) {
        cout << "Invalid number of vertices. Program exiting.\n";
        return 0;
    }

    int choice, src, dest, weight, start;
    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's Algorithm (MST)\n";
        cout << "4. Kruskal's Algorithm (MST)\n";
        cout << "5. Dijkstra's Algorithm (SSSP)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source, destination and weight (0 to " << n-1 << "): ";
                cin >> src >> dest >> weight;
                insertEdge(adjMatrix, edges, edgeCount, n, src, dest, weight);
                break;
            case 2:
                displayGraph(edges, edgeCount);
                break;
            case 3:
                primMST(adjMatrix, n);
                break;
            case 4:
                kruskalMST(edges, edgeCount, n);
                break;
            case 5:
                cout << "Enter starting vertex (0 to " << n-1 << "): ";
                cin >> start;
                if (start >= 0 && start < n) {
                    dijkstra(adjMatrix, n, start);
                } else {
                    cout << "Invalid starting vertex.\n";
                }
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

// Function definitions

//Function to insert an edge
void insertEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], Edge edges[], int& edgeCount, int n, int src, int dest, int weight) {
    if (src >= 0 && src < n && dest >= 0 && dest < n && weight > 0) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight; 
        edges[edgeCount].src = src;
        edges[edgeCount].dest = dest;
        edges[edgeCount].weight = weight;
        edgeCount++;
        cout << "Edge inserted.\n";
    } else {
        cout << "Invalid input.\n";
    }
}

//Function to display the graph
void displayGraph(Edge edges[], int edgeCount) {
    cout << "Edges in the graph:\n";
    for (int i = 0; i < edgeCount; i++) {
        cout << edges[i].src << " -- " << edges[i].dest << " == " << edges[i].weight << endl;
    }
}

//Function to find MST using Prim's Algorithm
void primMST(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n) {
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) return; // No more reachable vertices

        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    cout << "Prim's MST edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " -- " << i << " == " << adjMatrix[i][parent[i]] << endl;
    }
}

//Function to find MST using Kruskal's Algorithm
void kruskalMST(Edge edges[], int edgeCount, int n) {
    Edge result[MAX_VERTICES];
    int e = 0;
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES] = {0};

    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges using simple bubble sort
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    cout << "Kruskal's MST edges:\n";
    for (int i = 0; i < edgeCount && e < n - 1; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            result[e++] = edges[i];
            unionSets(parent, rank, x, y);
        }
    }

    for (int i = 0; i < e; i++) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }
}

//Function to perform Dijkstra's Algorithm
void dijkstra(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) return; // No more reachable vertices

        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To vertex " << i << " = " << dist[i] << endl;
    }
}

//Helper function to find parent in DSU
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

//Helper function to union two sets in DSU
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
