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
            gf->adj[i][j] = INT_MAX;
        }
    }

    int s, d;
    int ch;

    do
    {
        int w = 1;
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
            gf->adj[s][d] = w;
            gf->adj[d][s] = w;
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
            if (g->adj[i][j] == INT_MAX)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << g->adj[i][j] << " ";
            }
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

int find(int i, int parent[])
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j, int parent[])
{
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

void kruskalMST()
{
    int *parent = new int[G->V];

    int V = G->V;
    int **cost = G->adj;
    int mincost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

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

        cout << "Edge " << edge_count << ": (" << a << ", " << b << ") cost: " << min << endl;

        mincost += min;
        edge_count++;
    }

    cout << endl
         << "Minimum cost = " << mincost << endl;
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < G->V; ++v)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[])
{
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < G->V; ++i)
    {
        cout << parent[i] << " - " << i << "    " << G->adj[i][parent[i]] << endl;
    }
}

void primMST()
{
    int *parent = new int[G->V];
    int *key = new int[G->V];
    bool *mstSet = new bool[G->V];

    for (int i = 0; i < G->V; ++i)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < G->V - 1; ++count)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < G->V; ++v)
        {
            if (G->adj[u][v] != INT_MAX && !mstSet[v] && G->adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = G->adj[u][v];
            }
        }
    }

    printMST(parent);
}

int main()
{
    int ch;
    do
    {
        cout << "Enter 1 for Creating Graph" << endl
             << "Enter 2 to add a Vertex" << endl
             << "Enter 3 to add an Edge" << endl
             << "Enter 4 to display Adjacency Matrix" << endl
             << "Enter 5 for MCST (KRUSKAL'S ALGORITHM)" << endl
             << "Enter 6 for MCST (PRIM'S ALGORITHM)" << endl
             << "Enter 0 to Exit" << endl;

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
            kruskalMST();
            break;

        case 6:
            primMST();
            break;
        }
    } while (ch != 0);

    return 0;
}