
#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int **adj; // Adjacency matrix

public:
    Graph(int v) {
        vertices = v;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adj[i][j] = 0; // Initialize adjacency matrix with 0
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    void BFS(int start) {
        bool *visited = new bool[vertices] {false};
        int queue[vertices], front = 0, rear = 0;

        // Enqueue the starting vertex
        queue[rear++] = start;
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (front != rear) {
            int current = queue[front++]; // Dequeue
            cout << current << " ";

            // Explore all adjacent vertices
            for (int i = 0; i < vertices; i++) {
                if (adj[current][i] == 1 && !visited[i]) {
                    queue[rear++] = i; // Enqueue
                    visited[i] = true;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.BFS(0); // Start BFS from vertex 0
    return 0;
}


// DFS
#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int **adj; // Adjacency matrix

    void DFSUtil(int v, bool visited[]) {
        // Mark the current node as visited
        visited[v] = true;
        cout << v << " ";

        // Recur for all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

public:
    Graph(int v) {
        vertices = v;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adj[i][j] = 0; // Initialize adjacency matrix with 0
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    void DFS(int start) {
        bool *visited = new bool[vertices] {false};
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.DFS(0); // Start DFS from vertex 0
    return 0;
}
