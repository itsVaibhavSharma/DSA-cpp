A Minimum Cost Spanning Tree (MCST) is a tree that spans all the vertices in a connected, undirected graph with the minimum possible total edge weight.

In simpler terms, it's a subset of the edges of the graph that forms a tree (i.e., connected and acyclic) and includes all the vertices of the graph. The sum of the weights of the edges in the tree is minimized.

Several algorithms can find the minimum cost spanning tree of a graph, such as:

- **Kruskal's Algorithm**: This algorithm greedily selects edges in increasing order of weight while ensuring that no cycle is formed until all vertices are included, resulting in a minimum cost spanning tree.
    
- **Prim's Algorithm**: This algorithm starts from an arbitrary vertex and grows the minimum cost spanning tree by adding the closest vertex not yet included until all vertices are covered, resulting in a minimum cost spanning tree.
    
- **Borůvka's Algorithm**: This algorithm repeatedly adds the minimum weight edge incident to each tree in the forest, eventually connecting all trees into a single minimum cost spanning tree.

# 1. PRIM'S ALGORITHM
### Algorithm:

1. Initialize an array `key` to store the minimum weight of edges connecting each vertex to the MST. Initialize all values to infinity except the first vertex, which is set to 0.
2. Initialize an array `parent` to store the parent vertex of each vertex in the MST.
3. Repeat the following steps until all vertices are included in the MST:
    - Choose the vertex `u` with the minimum key value that is not yet in the MST.
    - Add `u` to the MST and update the key values of its adjacent vertices.
4. The MST can be reconstructed using the `parent` array.

```cpp
    // Function to find the vertex with minimum key value
    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, minIndex;
        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
  
    // Function to print the MST using parent array
    void printMST(int parent[]) {
        cout << "Edge   Weight" << endl;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << "    " << adjMatrix[i][parent[i]] << endl;
        }
    }
  
    // Function to perform Prim's algorithm for MST
    void primMST() {
        int *parent = new int[V]; // Array to store parent vertices of MST
        int *key = new int[V]; // Array to store key values of vertices
        bool *mstSet = new bool[V]; // Array to track vertices included in MST
  
        // Initialize key values and mstSet array
        for (int i = 0; i < V; ++i) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        key[0] = 0; // Start from the first vertex
        parent[0] = -1; // First vertex is the root of MST
  
       // Construct MST
        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet); // Choose the vertex with minimum key value
            mstSet[u] = true; // Add u to MST
  
            // Update key values of adjacent vertices of u
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] != INT_MAX && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // Print the MST
        printMST(parent);

    }
```

# 2. KRUSKAL ALGORITHM
### **Algorithm:**
1. **Initialization**:
   1.1. Initialize `parent[]` array with indices representing vertices.
   1.2. Initialize `mincost` to zero.
   1.3. Initialize `edge_count` to zero.

2. **Define Find Function**:
   2.1. **Function FIND(i, parent[])**:
       2.1.1. Initialize `i` as the input vertex index.
       2.1.2. While `parent[i]` is not equal to `i`, update `i` to `parent[i]`.
       2.1.3. Return `i`.

3. **Define Union Function**:
   3.1. **Function UNION(i, j, parent[])**:
       3.1.1. Find the representatives of vertices `i` and `j` using `FIND` function: `a = FIND(i, parent)` and `b = FIND(j, parent)`.
       3.1.2. Set `parent[a]` to `b`.

4. **Kruskal's Algorithm**:
   4.1. Initialize disjoint sets for each vertex: `parent[i] = i` for all vertices `i`.
   4.2. Repeat until `edge_count` equals `V - 1`, where `V` is the number of vertices in the graph:
       4.2.1. Find the minimum-weight edge that does not form a cycle:
           4.2.1.1. Initialize `min` to infinity, `a` and `b` to -1.
           4.2.1.2. Iterate over all vertices `i` and `j`:
                     - Check if `FIND(i, parent)` is not equal to `FIND(j, parent)` and `cost[i][j]` is less than `min`.
                     - If true, update `min`, `a`, and `b`.
       4.2.2. Union the sets containing the endpoints of the selected edge using the `UNION` function: `UNION(a, b, parent)`.
       4.2.3. Print the selected edge and update `mincost`:
           4.2.3.1. Print "Edge `edge_count`: (`a`, `b`, `parent`) cost: `min`".
           4.2.3.2. Update `mincost` by adding `min` to it.
       4.2.4. Increment `edge_count` by 1.

5. **Output**:
   5.1. Print the total minimum cost of the MST: "Minimum cost = `mincost`".

6. **Main Function**:
   6.1. Define the graph's adjacency matrix `cost`.
   6.2. Call the `kruskalMST` function with the adjacency matrix as input.

```cpp
int *parent ;
// Find set of vertex i
int find(int i, int parent[])
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
  
// Does union of i and j. It returns false if i and j are already in the same set.
void union1(int i, int j, int parent[])
{
    int a = find(i,parent);
    int b = find(j, parent);
    parent[a] = b;
}
  
// Finds MST using Kruskal's algorithm
void kruskalMST()
{
    parent = new int[G->V];
  
    int V = G->V;
    int **cost = G->adj;
    int mincost = 0; // Cost of min MST.
  
    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;
  
    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < V - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i, parent) != find(j, parent) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
  
        union1(a, b, parent);
  
        // Print the edge
        cout << "Edge " << edge_count << ": (" << a << ", " << b << ") cost: " << min << endl;
 
        mincost += min;
        edge_count++;
    }
  
    cout << "\nMinimum cost = " << mincost << endl;
}
```
