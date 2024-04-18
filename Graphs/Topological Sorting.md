Topological sorting is a way of arranging the nodes of a directed graph such that for every directed edge from node A to node B, node A comes before node B in the ordering. It's essentially a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

Here's an algorithm for topological sorting:

1. Create a boolean array "visited" of size V (number of vertices), initialized to false.
2. Create a stack to store the topologically sorted order.
3. For each vertex v in the graph: a. If vertex v is not visited, call a recursive function topologicalSortDFS() starting from vertex v.
4. In the topologicalSortDFS() function: 
	1. Mark vertex v as visited. 
	2. For each adjacent vertex u of v: i. If u is not visited, recursively call topologicalSortDFS() for vertex u. 
	3. Push vertex v onto the stack.
5. After completing DFS for all vertices, print the contents of the stack. The top of the stack will contain the vertices in topologically sorted order.


```cpp
// Utility function for DFS used in topological sorting
    void topologicalSortDFS(int v, bool visited[], int stack[], int& top) {
        visited[v] = true;
  
        // Recursively visit all adjacent vertices
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                topologicalSortDFS(i, visited, stack, top);
            }
        }
  
        // Push the vertex onto the stack after visiting all its adjacent vertices
        stack[++top] = v;
    }
  
    // Function to perform topological sorting using DFS
    void topologicalSort() {
        bool *visited = new bool[V]; // Array to track visited vertices
        int *stack = new int[V]; // Array to simulate stack
        int top = -1; // Top of the stack
  
        // Initialize visited array to false
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
  
        // Perform DFS traversal for each vertex not yet visited
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortDFS(i, visited, stack, top);
            }
        }
  
        // Print the topologically sorted order
        cout << "Topological sorting: ";
        while (top != -1) {
            cout << stack[top--] << " ";
        }
        cout << endl;

    }
```

# KAHN'S ALGORITHM
Kahn's algorithm is another method for topological sorting, which is based on the concept of using indegrees of vertices. Here's the algorithm and its implementation without using any library:

### Kahn's Algorithm for Topological Sorting:

1. Calculate the indegree (number of incoming edges) for each vertex.
2. Initialize a queue and enqueue all vertices with an indegree of 0.
3. Repeat the following steps until the queue is empty:
    - Dequeue a vertex from the queue.
    - Output the dequeued vertex.
    - Reduce the indegree of all its adjacent vertices by 1.
    - If any adjacent vertex's indegree becomes 0, enqueue it.
4. If the number of vertices output is equal to the total number of vertices in the graph, then the topological sorting is successful; otherwise, the graph has a cycle.

```cpp
void topologicalSort() {
        // Array to store indegrees of vertices
        int *indegree = new int[V];
        for (int i = 0; i < V; ++i) {
            indegree[i] = 0;
        }
  
        // Calculate indegrees of vertices
        for (int i = 0; i < V; ++i) {
            Node* temp = adjList[i];
            while (temp != nullptr) {
                indegree[temp->data]++;
                temp = temp->next;
            }
       }
  
        // Initialize a queue for Kahn's algorithm
        int front = 0, rear = -1;
        int *queue = new int[V];
        // Enqueue vertices with indegree 0
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                queue[++rear] = i;
            }
        }
  
        // Variable to count vertices visited during topological sorting
        int count = 0;
  
        // Perform Kahn's algorithm
        while (front <= rear) {
            int u = queue[front++];
            cout << u << " "; // Output the vertex
            count++;
  
            // Reduce the indegree of adjacent vertices
            Node* temp = adjList[u];
            while (temp != nullptr) {
                int v = temp->data;
                indegree[v]--;
                // Enqueue vertices with indegree 0
                if (indegree[v] == 0) {
                    queue[++rear] = v;
                }
                temp = temp->next;
            }
        }
  
        // Check if the topological sorting is successful
        if (count != V) {
            cout << "Graph has a cycle." << endl;
        }
  
    }
```

