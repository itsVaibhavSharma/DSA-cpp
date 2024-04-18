Both BFS and DFS are commonly used for various applications, such as finding the shortest path, connected components, cycle detection, and topological sorting, among others. The choice between BFS and DFS depends on the specific requirements of the problem and the properties of the graph or tree being traversed.

### **Breadth-First Search (BFS):**
BFS is an algorithm used for traversing or searching tree or graph data structures. It starts at a given vertex (often referred to as the "source" vertex) and explores all of the neighbor vertices at the present depth before moving on to the vertices at the next depth level. BFS uses a queue data structure to keep track of vertices to visit next.

Algorithm:
1. Initialize an empty queue and a set to keep track of visited vertices.
2. Enqueue the source vertex into the queue and mark it as visited.
3. While the queue is not empty, do the following:
   a. Dequeue a vertex from the queue.
   b. Process the dequeued vertex.
   c. Enqueue all adjacent vertices of the dequeued vertex that have not been visited yet and mark them as visited.
4. Continue until the queue is empty.


### Function for Breadth-First Search (BFS) using adjacency matrix
```cpp
void bfsMatrix(int start)
{
    cout << "BFS using adjacency matrix starting from vertex " << start << ":" << endl;
  
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
    }
  
    int *queue = new int[V];
    int front = 0, rear = 0;
  
    visited[start] = true;
    queue[rear++] = start;
  
    while (front != rear)
    {
        int u = queue[front++];
        cout << u << " ";
  
        for (int v = 0; v < V; ++v)
        {
            if (adjMatrix[u][v] && !visited[v])
            {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }
  
    cout << endl;
    //delete[] visited;
    //delete[] queue;
}
```


### Function for Breadth-First Search (BFS) using adjacency list
```cpp
    void bfsList(int start) {
        cout << "BFS using adjacency list starting from vertex " << start << ":" << endl;
  
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
  
        int *queue = new int[V];
        int front = 0, rear = 0;
  
        visited[start] = true;
        queue[rear++] = start;
  
        while (front != rear) {
            int u = queue[front++];
            cout << u << " ";
  
            Node* temp = adjList[u];
            while (temp != nullptr) {
                int v = temp->data;
                if (!visited[v]) {
                    visited[v] = true;
                    queue[rear++] = v;
                }
                temp = temp->next;
            }
        }
  
        cout << endl;
        //delete[] visited;
        //delete[] queue;
    }
```


### **Depth-First Search (DFS):**
DFS is another algorithm used for traversing or searching tree or graph data structures. It starts at a given vertex (source vertex) and explores as far as possible along each branch before backtracking. DFS uses a stack data structure (or recursion) to keep track of vertices to visit next.

Algorithm:
1. Initialize a stack (or use recursion) and a set to keep track of visited vertices.
2. Push the source vertex onto the stack (or recursively call the DFS function for the source vertex) and mark it as visited.
3. While the stack is not empty (or the recursion base case is reached), do the following:
   a. Pop a vertex from the stack (or return if using recursion).
   b. Process the popped vertex.
   c. Push (or recursively call DFS) all adjacent vertices of the popped vertex that have not been visited yet and mark them as visited.
4. Continue until the stack is empty (or recursion returns).

### Function for Depth-First Search (DFS) using adjacency matrix
```cpp
 // Utility function for DFS using adjacency matrix
    void dfsMatrixUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
  
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                dfsMatrixUtil(i, visited);
            }
        }
    }
  
    // Function for Depth-First Search (DFS) using adjacency matrix
    void dfsMatrix(int start) {
        cout << "DFS using adjacency matrix starting from vertex " << start << ":" << endl;
  
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
  
        dfsMatrixUtil(start, visited);
  
        cout << endl;
        //delete[] visited;
    }
```

### Function for Depth-First Search (DFS) using adjacency list
```cpp
// Utility function for DFS using adjacency list
    void dfsListUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
  
        Node* temp = adjList[v];
        while (temp != nullptr) {
            int i = temp->data;
            if (!visited[i]) {
                dfsListUtil(i, visited);
            }
            temp = temp->next;
        }
    }
  
    // Function for Depth-First Search (DFS) using adjacency list
    void dfsList(int start) {
        cout << "DFS using adjacency list starting from vertex " << start << ":" << endl;
  
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
  
        dfsListUtil(start, visited);
  
        cout << endl;
        //delete[] visited;
    }
```

### DFS using adjacency matrix (using stack)
```cpp
 void dfsMatrix(int start) {
        cout << "DFS using adjacency matrix starting from vertex " << start << ":" << endl;
  
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
  
        int *stack = new int[V];
        int top = -1;
  
        visited[start] = true;
        stack[++top] = start;
  
        while (top != -1) {
            int u = stack[top--];
            cout << u << " ";
  
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    stack[++top] = v;
                }
            }
        }
  
        cout << endl;
        //delete[] visited;
        //delete[] stack;
    }
```

