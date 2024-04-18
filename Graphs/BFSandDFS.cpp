#include <iostream>
using namespace std;

struct graph
{
    int V;
    bool dir;
    bool weighted;
    int **adj;
    char *data;
} *G = NULL;

graph *adjMat()
{
    graph *gf = new graph;
    cout << "Enter no. of vertices: ";
    cin >> gf->V;
    cout << "Is graph directed? (1/0) ";
    cin >> gf->dir;
    cout << "Is graph Weighted? (1/0) ";
    cin >> gf->weighted;

    gf->adj = new int *[gf->V];

    gf->data = new char[gf->V];
    for (int i = 0; i < gf->V; i++)
    {
        gf->adj[i] = new int[gf->V];
        cout << "Enter data for vertex " << i << ": ";
        cin >> gf->data[i];
        for (int j = 0; j < gf->V; j++)
        {
            gf->adj[i][j] = 0;
        }
    }

    int s, d;
    int ch;

    do
    {
        int w = 1;
        if (gf->weighted)
        {
            cout << "Enter edge (source, destination, weight): ";
            cin >> s >> d >> w;
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d;
        }
        if (!(gf->dir))
        {

            gf->adj[s][d] = w;
            gf->adj[d][s] = w;
        }
        else
        {

            gf->adj[s][d] = w;
        }
        cout << "Do you want to add more edges? (0/1): ";
        cin >> ch;
    } while (ch != 0);

    return gf;
}

void displayADJ(graph *g)
{
    cout << "  ";
    for (int k = 0; k < g->V; k++)
    {
        cout << g->data[k] << " ";
    }
    cout << endl;
    for (int i = 0; i < g->V; i++)
    {

        cout << g->data[i] << " ";
        for (int j = 0; j < g->V; j++)
        {
            cout << g->adj[i][j] << " ";
        }
        cout << endl;
    }
}

void addVertex(graph *g)
{
    (g->V)++;
    int **newAdj = new int *[g->V];
    char *newData = new char[g->V];

    for (int i = 0; i < (g->V); i++)
    {
        newAdj[i] = new int[g->V];
        newData[i] = g->data[i];
        for (int j = 0; j < (g->V); j++)
        {
            if ((i < (g->V) - 1) && (j < (g->V) - 1))
            {
                newAdj[i][j] = g->adj[i][j];
            }
            else
            {
                newAdj[i][j] = 0;
            }
        }
    }
    cout << "Enter data for new vertex "
         << ": ";
    cin >> newData[(g->V) - 1];

    g->data = newData;
    g->adj = newAdj;
}

void addEdge(graph *gf)
{
    int s, d, w = 1;
    if (!(gf->dir))
    {

        if (gf->weighted)
        {
            cout << "Enter edge (source, destination, weight): ";
            cin >> s >> d >> w;
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d;
        }
        if (s >= gf->V || d >= gf->V)
        {
            cout << "Not a valid input." << endl;
            return;
        }
        else
        {
            gf->adj[s][d] = w;
            gf->adj[d][s] = w;
        }
    }
    else
    {
        if (gf->weighted)
        {
            cout << "Enter edge (source, destination, weight): ";
            cin >> s >> d >> w;
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d;
        }
        if (s >= gf->V || d >= gf->V)
        {
            cout << "Not a valid input." << endl;
            return;
        }
        else
        {
            gf->adj[s][d] = w;
        }
    }
}

void bfs(int start)
{
    cout << "BFS using adjacency matrix starting from vertex " << start << ":" << endl;

    bool *visited = new bool[G->V];
    for (int i = 0; i < G->V; ++i)
    {
        visited[i] = false;
    }

    int *queue = new int[G->V];
    int front = 0, rear = 0; // 3-> 0 1 2 | front 3/ rear 3

    visited[start] = true;
    queue[rear++] = start;

    while (front != rear)
    {
        int u = queue[front++];
        cout << G->data[u] << " ";

        for (int v = 0; v < G->V; ++v)
        {
            if (G->adj[u][v] && !visited[v])
            {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }

    cout << endl;
}

void dfs(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " "; // 0 1 2 3

    for (int i = 0; i < G->V; ++i)
    {
        if (G->adj[v][i] && !visited[i])
        {
            dfs(i, visited); // 2
        }
    }
}

void dfsStack(int start)
{
    cout << "DFS using adjacency matrix starting from vertex " << start << ":" << endl;

    bool *visited = new bool[G->V];
    for (int i = 0; i < G->V; ++i)
    {
        visited[i] = false;
    }

    int *stack = new int[G->V];
    int top = -1;

    visited[start] = true;
    stack[++top] = start;

    while (top != -1)
    {
        int u = stack[top--];
        cout << u << " ";

        for (int v = (G->V) - 1; v >= 0; --v)
        {
            if (G->adj[u][v] && !visited[v])
            {
                visited[v] = true;
                stack[++top] = v;
            }
        }
    }

    cout << endl;
    // delete[] visited;
    // delete[] stack;
}

int main()
{
    cout << "Enter 1 for Creating Graph" << endl
         << "Enter 2 to add a Vertex" << endl
         << "Enter 3 to add an Edge" << endl
         << "Enter 4 to display Adjacency Matrix" << endl
         << "Enter 5 for Breadth First Search Traversal (BFS)" << endl
         << "Enter 6 for Depth First Search Traversal (DFS)" << endl
         << "Enter 7 for Depth First Search Traversal (DFS) using STACK" << endl
         << "Enter 0 to Exit" << endl;
    int ch;
    do
    {

        cout << "Enter Function no.: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            break;
        case 1:
            G = adjMat();
            break;
        case 2:
            addVertex(G);
            break;
        case 3:
            addEdge(G);
            break;
        case 4:
            displayADJ(G);
            break;
        case 5:
            bfs(0);
            break;
        case 6:
        {
            cout << "DFS using adjacency matrix starting from vertex " << 0 << ":" << endl;

            bool *visited = new bool[G->V];
            for (int i = 0; i < G->V; ++i)
            {
                visited[i] = false;
            }

            dfs(0, visited);

            cout << endl;
        }
        break;

        case 7:
            dfsStack(0);
            break;
        }
    } while (ch != 0);

    return 0;
}