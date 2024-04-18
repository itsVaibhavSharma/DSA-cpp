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
    // cout << "Enter no. of Edges: ";
    // cin >> gf->E;

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

    // for(int i = 0; i < gf->V; i++){
    //     for(int j = 0; j< gf->V; j++){

    //     }
    // }

    // do{
    // if(!gf->dir){
    //     cout << "Enter edge (source, destination): ";
    //     cin >> s, d;
    //     gf->adj[s][d] = gf->adj[d][s] = 1;

    // } else{
    //     int w;
    //     cout << "Enter edge (source, destination, weight): ";
    //     cin >> s, d, w;
    //     gf->adj[s][d] =  w;
    // }
    // cout << "Do you want to add more edges? (0/1): ";
    // cin>> ch1;
    // }while(ch1!=0);
    int s, d;
    int ch;
    do
    {
        int w = 1;
        if (gf->weighted)
        {
            cout << "Enter edge (source, destination, weight): ";
            cin >> s >> d >> w; // 0 2 5
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d; // 0 2 1
        }

        if (!(gf->dir))
        {

            gf->adj[s][d] = w;
            gf->adj[d][s] = w;
            // cout << "Enter edge (source  destination): ";
            // cin >> s;
            // cin >> d;
            // gf->adj[s][d] = 1;
            // gf->adj[d][s] = 1;
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
    // 4 -> 0 1 2 3
    (g->V)++; // 5 -> 0 1 2 3 4
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
    cin >> newData[(g->V) - 1]; // 4

    g->data = newData;
    g->adj = newAdj;
}

void addEdge(graph *gf)
{
    int s, d, w = 1;
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

        // cout << "Enter edge (source  destination): ";
        // cin >> s;
        // cin >> d;
        // gf->adj[s][d] = 1;
        // gf->adj[d][s] = 1;
    }
    else
    {

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

int main()
{
    int ch;
    do
    {
        cout << "Enter 1 for Creating Graph" << endl
             << "Enter 2 to add a Vertex" << endl
             << "Enter 3 to add an Edge" << endl
             << "Enter 4 to display Adjacency Matrix" << endl
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
        }
    } while (ch != 0);

    // graph *g1 = adjMat();
    // displayADJ(g1);

    // addEdge(g1);
    // addEdge(g1);
    // addEdge(g1);

    // displayADJ(g1);

    return 0;
}