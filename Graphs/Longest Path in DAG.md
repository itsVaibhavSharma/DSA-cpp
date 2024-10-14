In a Directed Acyclic Graph (DAG), a longest path refers to the longest possible sequence of edges in the graph that connects two vertices. 

However, it's important to note that the term "longest path" in a DAG usually refers to the longest path between two vertices, rather than the longest path in the entire graph. 

Since the graph is acyclic, there's no way to revisit a vertex once it has been visited, hence the term "directed acyclic." This means that there are no cycles or loops in the graph. Therefore, finding the longest path between two vertices is well-defined and feasible in a DAG.

The longest path in a DAG can have various applications. For example, in a project management scenario, where tasks are represented as vertices and dependencies between tasks are represented as directed edges, finding the longest path can help determine the critical path of the project, which is the sequence of tasks that must be completed without delay to ensure that the project is completed as quickly as possible.

Finding the longest path in a DAG is typically done using dynamic programming algorithms such as topological sorting followed by dynamic programming on the topological order.
### Algorithm:
1. Perform topological sorting on the DAG.
2. Initialize an array `dist` to store the longest path length to each vertex. Initialize all distances to negative infinity except the source vertex, which is set to 0.
3. For each vertex in topologically sorted order, update the longest path length to its adjacent vertices.
4. The maximum value in the `dist` array after processing all vertices will be the length of the longest path.

```cpp
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

#define MAX 1000

// Graph data structure
int graph[MAX][MAX];  // Adjacency matrix
int n;                // Number of nodes in the graph

// A utility function to do topological sort using DFS
void topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // Push current vertex to stack which stores the topological sort
    Stack.push(v);
}

// Function that calculates the longest path
void longestPath(int src) {
    stack<int> Stack;
    bool visited[MAX];

    // Initialize visited array as false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Perform topological sort on all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // Initialize distances to all vertices as minus infinity
    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MIN;
    }
    dist[src] = 0;  // Distance to source is 0

    // Process vertices in topological order
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices of u
        if (dist[u] != INT_MIN) {
            for (int i = 0; i < n; i++) {
                if (graph[u][i] && dist[i] < dist[u] + graph[u][i]) {
                    dist[i] = dist[u] + graph[u][i];
                }
            }
        }
    }

    // Print the calculated longest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MIN) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Sample graph input (Adjacency matrix)
    n = 6;  // Number of nodes
    int edges[][3] = {
        {0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, 
        {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 5, 1}, 
        {3, 4, -1}, {4, 5, -2}
    };

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u][v] = w;
    }

    int src = 1;  // Starting node
    cout << "Longest distances from node " << src << ":\n";
    longestPath(src);

    return 0;
}
```
### Explanation of the `longestPath` function:

The `longestPath` function computes the longest path from a given source vertex in a Directed Acyclic Graph (DAG). Here's a step-by-step explanation:

1. **Initialization:**
   - `Stack`: Used to store the topological order of vertices.
   - `visited[]`: A boolean array to track which vertices have been visited during the DFS traversal.
   - `dist[]`: An array to store the longest distances from the source to all other vertices. Initially, all distances are set to `INT_MIN` (representing negative infinity) except for the source vertex, which is set to `0`.

2. **Topological Sorting:**
   - We perform a **topological sort** of the DAG using DFS. A DAG has a valid topological ordering where, for every directed edge `(u, v)`, vertex `u` appears before vertex `v` in the ordering.
   - We visit every node using the helper function `topologicalSortUtil`, which recursively processes all unvisited vertices. Once a vertex is fully explored, it is pushed onto the `Stack`, ensuring that when it's popped later, all its dependencies have already been processed.

3. **Processing the Topological Order:**
   - After obtaining the topological order from the `Stack`, we process each vertex `u` in this order.
   - For every vertex `u`, if the distance from the source to `u` is not `INT_MIN` (i.e., it has been reached from the source), we check all its adjacent vertices `v`.
   - For each adjacent vertex `v`, we relax the edge `(u, v)` by checking if the current longest path to `v` can be updated by traveling through `u`. This is done by comparing the current value of `dist[v]` with `dist[u] + weight_of_edge(u, v)`.

4. **Result:**
   - Once all vertices have been processed, the `dist[]` array will contain the longest distances from the source to every other vertex. If a vertex is unreachable from the source, its distance remains `INT_MIN`.

### Algorithm

#### Input:
- A directed acyclic graph (DAG) represented as an adjacency matrix.
- Source vertex `src` from which the longest path needs to be calculated.

#### Output:
- An array `dist[]` that contains the longest path distances from the source to every other vertex in the graph.

#### Steps:
1. **Topological Sort:**
   - Initialize a stack `Stack` and an array `visited[]` to track visited vertices.
   - For every unvisited vertex `v`, perform a DFS traversal:
     - Mark `v` as visited.
     - Recursively visit all unvisited adjacent vertices.
     - Once all adjacent vertices are processed, push `v` onto `Stack`.

2. **Initialize Distances:**
   - Create an array `dist[]` and set all distances to `INT_MIN` (negative infinity).
   - Set the distance of the source vertex `src` to `0`.

3. **Process Vertices in Topological Order:**
   - While `Stack` is not empty:
     - Pop a vertex `u` from `Stack`.
     - If the distance to `u` is not `INT_MIN`, for each adjacent vertex `v` of `u`:
       - If `dist[v] < dist[u] + weight_of_edge(u, v)`, update `dist[v]` with the new value `dist[u] + weight_of_edge(u, v)`.

4. **Print or Return Distances:**
   - Print the longest distances for each vertex. If a vertex is unreachable, its distance will remain `INT_MIN`.

### Pseudo-code:

```
function longestPath(src):
    1. Initialize Stack and visited array:
       Stack = empty stack
       visited[] = array of size n, all initialized to false
       
    2. Perform Topological Sort:
       for i = 0 to n-1:
           if visited[i] == false:
               topologicalSortUtil(i, visited, Stack)
    
    3. Initialize distances:
       dist[] = array of size n, all initialized to INT_MIN
       dist[src] = 0  // Distance to source is 0
    
    4. Process vertices in topological order:
       while Stack is not empty:
           u = Stack.top()
           Stack.pop()
           
           if dist[u] != INT_MIN:
               for each adjacent vertex v of u:
                   if dist[v] < dist[u] + weight_of_edge(u, v):
                       dist[v] = dist[u] + weight_of_edge(u, v)
    
    5. Print distances:
       for each vertex i in 0 to n-1:
           if dist[i] == INT_MIN:
               print "INF"
           else:
               print dist[i]
```

### Time Complexity:
- **Topological Sorting**: The DFS-based topological sort takes \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.
- **Longest Path Calculation**: After topological sorting, processing each vertex and relaxing edges also takes \(O(V + E)\).
  
Thus, the overall time complexity is \(O(V + E)\).

