#include <iostream>
using namespace std;

struct node
{
    int data;
    int weight;
    node *next;
};

struct graph
{
    int V;
    bool dir;
    bool weighted;
    node **adj;
    char *data;
} *G = NULL;

void addVertex(graph *g)
{
    node **newAdj = new node *[++(g->V)];
    char *newData = new char[g->V];

    for (int i = 0; i < (g->V); i++)
    {

        if (i == (g->V) - 1)
        {
            newAdj[i] = NULL;
        }
        else
        {
            newAdj[i] = g->adj[i];
            newData[i] = g->data[i];
        }

        // for (int j = 0; j < (g->V); j++)
        // {
        //     if ((i < (g->V) - 1) && (j < (g->V) - 1))
        //     {
        //         newAdj[i][j] = g->adj[i][j];
        //     }
        //     else
        //     {
        //         newAdj[i][j] = 0;
        //     }
        // }
    }
    cout << "Enter data for new vertex "
         << ": ";
    cin >> newData[(g->V) - 1];
    g->adj = newAdj;
    g->data = newData;
}

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

    gf->adj = new node *[gf->V];

    gf->data = new char[gf->V];
    for (int i = 0; i < gf->V; i++)
    {
        gf->adj[i] = NULL;
        cout << "Enter data for vertex " << i << ": ";
        cin >> gf->data[i];
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
                if (s >= gf->V || d >= gf->V)
                {
                    cout << "Not a valid input." << endl;
                }
            }
            else
            {
                cout << "Enter edge (source  destination): ";
                cin >> s >> d;
                if (s >= gf->V || d >= gf->V)
                {
                    cout << "Not a valid input." << endl;
                }
            }
            node *newnode = new node;
            newnode->data = d;
            newnode->next = gf->adj[s];
            newnode->weight = w;
            gf->adj[s] = newnode;

            node *newnode2 = new node;
            newnode2->data = s;
            newnode2->weight = w;
            newnode2->next = gf->adj[d];
            gf->adj[d] = newnode2;
        }
        else
        {
            if (gf->weighted)
            {
                cout << "Enter edge (source, destination, weight): ";
                cin >> s >> d >> w;
                if (s >= gf->V || d >= gf->V)
                {
                    cout << "Not a valid input." << endl;
                }
            }
            else
            {
                cout << "Enter edge (source  destination): ";
                cin >> s >> d;
                if (s >= gf->V || d >= gf->V)
                {
                    cout << "Not a valid input." << endl;
                }
            }
            node *newnode = new node;
            newnode->data = d;
            newnode->next = gf->adj[s];
            newnode->weight = w;
            gf->adj[s] = newnode;
        }
        cout << "Do you want to add more edges? (0/1): ";
        cin >> ch;
    } while (ch != 0);

    return gf;
}

void displayADJ(graph *g)
{
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < g->V; ++i)
    {
        cout << g->data[i] << " -> ";
        node *temp = g->adj[i];
        while (temp != nullptr)
        {
            cout << g->data[temp->data] << " ";
            temp = temp->next;
        }
        cout << endl;
    }
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
            if (s >= gf->V || d >= gf->V)
            {
                cout << "Not a valid input." << endl;
                return;
            }
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d;
            if (s >= gf->V || d >= gf->V)
            {
                cout << "Not a valid input." << endl;
                return;
            }
        }
        node *newnode = new node;
        newnode->data = d;
        newnode->next = gf->adj[s];
        newnode->weight = w;
        gf->adj[s] = newnode;

        node *newnode2 = new node;
        newnode2->data = s;
        newnode2->weight = w;
        newnode2->next = gf->adj[d];
        gf->adj[d] = newnode2;
    }
    else
    {
        if (gf->weighted)
        {
            cout << "Enter edge (source, destination, weight): ";
            cin >> s >> d >> w;
            if (s >= gf->V || d >= gf->V)
            {
                cout << "Not a valid input." << endl;
                return;
            }
        }
        else
        {
            cout << "Enter edge (source  destination): ";
            cin >> s >> d;
            if (s >= gf->V || d >= gf->V)
            {
                cout << "Not a valid input." << endl;
                return;
            }
        }
        node *newnode = new node;
        newnode->data = d;
        newnode->next = gf->adj[s];
        newnode->weight = w;
        gf->adj[s] = newnode;
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
             << "Enter 4 to display Adjacency List" << endl
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

    return 0;
}