// FloydWarshall
#include <iostream>
#include <cstdio>

#define INF 1000000000
#define MAXN 100

void initializeGraph(int graph[MAXN][MAXN], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}

void readEdges(int graph[MAXN][MAXN], int m) {
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // assuming undirected graph
    }
}

void floydWarshall(int graph[MAXN][MAXN], int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }

            }
        }
    }
}

void printResult(int graph[MAXN][MAXN], int source, int sink) {
    if (graph[source][sink] == INF) {
        std::cout << "No path" << std::endl;
    } else {
        std::cout << graph[source][sink] << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int graph[MAXN][MAXN];
    initializeGraph(graph, n);
    readEdges(graph, m);

    int source, sink;
    std::cin >> source >> sink;

    floydWarshall(graph, n);
    printResult(graph, source, sink);

    return 0;
}

//Warshall
#include <iostream>
#include <cstdio>

#define MAXN 100

// Function to initialize the graph
void initializeGraph(int graph[MAXN][MAXN], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = 0; // Initially no paths between nodes
        }
    }
}

// Function to read the edges and update the adjacency matrix
void readEdges(int graph[MAXN][MAXN], int m) {
    int u, v;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        graph[u][v] = 1; // There is an edge from u to v
    }
}

// Warshall Algorithm to compute transitive closure (reachability matrix)
void warshall(int graph[MAXN][MAXN], int n) {
    // Apply the Warshall algorithm to compute reachability
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j]=graph[i][j] || graph[i][k] &&graph[k][j];
            }
        }
    }
}

// Function to print the result (reachability matrix)
void printResult(int graph[MAXN][MAXN], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;  // n = number of nodes, m = number of edges

    int graph[MAXN][MAXN];
    initializeGraph(graph, n);
    readEdges(graph, m);

    // Compute the transitive closure (reachability matrix)
    warshall(graph, n);

    // Output the result: reachability matrix
    printResult(graph, n);

    return 0;
}
