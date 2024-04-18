In the context of a graph, a shortest path refers to the path between two vertices with the minimum possible total weight or cost. This weight could represent various metrics, such as distance, time, cost, etc., depending on the application.

Now, let's delve into the differences between Dijkstra's algorithm and Bellman-Ford algorithm:

1. **Dijkstra's Algorithm**:
   - Dijkstra's algorithm is used to find the shortest path from a single source vertex to all other vertices in a weighted graph (with non-negative weights).
   - It works by iteratively selecting the vertex with the smallest distance (or cost) from the source vertex and relaxing the edges connected to that vertex.
   - Dijkstra's algorithm maintains a priority queue (min-heap) to efficiently select the next vertex with the smallest distance.
   - It's efficient when dealing with graphs with non-negative edge weights.
   - Time complexity: O((V + E) log V) with a priority queue (binary heap) or O(V^2) with an array implementation, where V is the number of vertices and E is the number of edges.

2. **Bellman-Ford Algorithm**:
   - Bellman-Ford algorithm is used to find the shortest path from a single source vertex to all other vertices in a weighted graph, even if the graph contains negative weight edges or negative weight cycles.
   - It works by iteratively relaxing all edges in the graph |V| - 1 times, where |V| is the number of vertices. After each iteration, it updates the shortest distances to all vertices.
   - Bellman-Ford algorithm can detect negative weight cycles in the graph.
   - It's less efficient compared to Dijkstra's algorithm but more versatile as it can handle graphs with negative edge weights.
   - Time complexity: O(V * E), where V is the number of vertices and E is the number of edges.

In summary, the key differences between Dijkstra's algorithm and Bellman-Ford algorithm lie in their handling of edge weights and their efficiency. Dijkstra's algorithm is faster and suitable for graphs with non-negative edge weights, while Bellman-Ford algorithm is slower but capable of handling graphs with negative edge weights and detecting negative weight cycles.

# 1. Dijkstra Algorithm
### Algorithm:

1. Initialize an array `dist` to store the shortest distance from the source vertex to each vertex. Initialize all distances to infinity except the source vertex, which is set to 0.
2. Initialize a boolean array `visited` to track visited vertices.
3. Repeat the following steps until all vertices are visited:
    - Find the vertex `u` with the minimum distance from the source vertex among the unvisited vertices.
    - Mark vertex `u` as visited.
    - Update the distance to each adjacent vertex `v` of `u` if the distance through `u` is shorter than the current distance to `v`.
4. The array `dist` will contain the shortest distance from the source vertex to each vertex.

```cpp
 // Function to find the vertex with the minimum distance among unvisited vertices
    int minDistance(int dist[], bool visited[]) {
        int minDist = INT_MAX, minVertex;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minVertex = i;
            }
        }
        return minVertex;
    }
  
    // Function to perform Dijkstra's algorithm for shortest path
    void dijkstra(int source) {
        int *dist = new int[V]; // Array to store shortest distance from source
        bool *visited = new bool[V]; // Array to track visited vertices
  
        // Initialize dist array to infinity and visited array to false
        for (int i = 0; i < V; ++i) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[source] = 0; // Distance from source to itself is 0
  
        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; ++count) {
            int u = minDistance(dist, visited); // Vertex with minimum distance
            visited[u] = true; // Mark the vertex as visited
  
            // Update distance to adjacent vertices of u

          Node* temp = adjList[u];
            while (temp != nullptr) {
                int v = temp->data;
                int weight = temp->weight;
                if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight <<dist[v]) {
                    dist[v] = dist[u] + weight;
                }
                temp = temp->next;
            }
        }
  
        // Print shortest distances from source
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                cout << "Vertex " << i << ": No path" << endl;
            } else {
                cout << "Vertex " << i << ": " << dist[i] << endl;
            }
        }
    }
```


# 2. Bellman Ford Algorithm
### Algorithm:

1. Initialize an array `dist` to store the shortest distance from the source vertex to each vertex. Initialize all distances to infinity except the source vertex, which is set to 0.
2. Repeat the following steps for `V-1` iterations, where `V` is the number of vertices in the graph:
    - For each edge `(u, v)` in the graph, update the distance to vertex `v` if the distance through `u` is shorter than the current distance to `v`.
3. After `V-1` iterations, if there are no negative cycles, the array `dist` will contain the shortest distance from the source vertex to each vertex.

```cpp
 // Function to perform Bellman-Ford algorithm for shortest path
    bool bellmanFord(int source) {
        int *dist = new int[V]; // Array to store shortest distance from source
  
        // Initialize dist array to infinity
        for (int i = 0; i < V; ++i) {
            dist[i] = INT_MAX;
        }
        dist[source] = 0; // Distance from source to itself is 0
  
        // Relax all edges |V|-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (int u = 0; u < V; ++u) {
                Node* temp = adjList[u];
                while (temp != nullptr) {
                    int v = temp->data;
                    int weight = temp->weight;
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                    temp = temp->next;
                }
            }
        }
  
        // Check for negative cycles
        for (int u = 0; u < V; ++u) {
            Node* temp = adjList[u];
            while (temp != nullptr) {
                int v = temp->data;
                int weight = temp->weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    // Negative cycle found
                    delete[] dist;
                    return false;
                }
                temp = temp->next;
            }
        }
  
        // Print shortest distances from source
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {

               cout << "Vertex " << i << ": No path" << endl;
            } else {
                cout << "Vertex " << i << ": " << dist[i] << endl;
            }
        }
  
        return true;
    }
```

# 3. Floyd Warshal Algorithm : Shortest path between all pair of vertices

The "shortest paths between all pairs of vertices" refers to finding the shortest path from every vertex in a graph to every other vertex. In other words, it computes the shortest path between every possible pair of vertices in the graph.
### Algorithm:

1. Initialize a 2D array `dist` to store the shortest distances between all pairs of vertices. Initialize `dist[i][j]` to the weight of the edge from vertex `i` to vertex `j` if there is an edge, otherwise set it to infinity.
2. For each intermediate vertex `k` from 0 to `V-1`:
    - For each pair of vertices `i` and `j`, update `dist[i][j]` if the path through `k` is shorter than the current distance between `i` and `j`.
3. The array `dist` will contain the shortest distances between all pairs of vertices.

```cpp
// Function to perform Floyd-Warshall algorithm for shortest paths
    void floydWarshall() {
        int **dist = new int*[V]; // Array to store shortest distances between all pairs of vertices
  
        // Copy adjacency matrix to dist array
        for (int i = 0; i < V; ++i) {
            dist[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                dist[i][j] = adjMatrix[i][j];
            }
        }
  
        // Update shortest distances between all pairs of vertices
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
  
        // Print shortest distances between all pairs of vertices
        cout << "Shortest distances between all pairs of vertices:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INT_MAX) {
                    cout << "INF\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }
```

