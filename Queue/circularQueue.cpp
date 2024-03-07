#include <iostream>
using namespace std;
void enqueue();
void dequeue();
void traversal();

const int s = 6;
int q[s], f = -1, r = -1;
int main()
{

    int ch;
    cout << "Enter 1 for Insertion at Rear" << endl
         << "Enter 2 for Deletion at front" << endl
         << "Enter 3 for Traversal" << endl
         << "Enter 4 to EXIT" << endl;
    do
    {
        cout << "Enter function no.: ";

        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traversal();
            break;
        case 4:
            return 0;
        default:
            cout << "Enter valid function no.";
        }
    } while (1);

    return 0;
}

void enqueue()
{

    if ((r + 1) % s == f)
    {
        cout << "Queue is full, enqueue not possible." << endl;
    }
    else if (f == -1)
    {
        f++;
        r++;
        cout << "Enter data: ";
        cin >> q[r];
    }
    else
    {
        r = (r + 1) % s;
        cout << "Enter data: ";
        cin >> q[r];
    }
}

void dequeue()
{

    if (f == -1)
    {
        cout << "Queue is Empty. Deletion not possible." << endl;
    }
    else if (f == r)
    {
        cout << "Deleted element has data: " << q[f] << endl;
        f = r = -1;
    }
    else
    {

        cout << "Deleted element has data: " << q[f] << endl;
        f = (f + 1) % s;
    }
}

void traversal()
{
    if (f == -1)
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {

        for (int i = f; i != r; i = (i + 1) % s)
        {
            cout << q[i] << " ";
        }
        cout << q[r] << endl;
    }
}