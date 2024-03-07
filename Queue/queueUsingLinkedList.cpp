#include <iostream>
using namespace std;
void enqueue();
void dequeue();
void traversal();
struct node
{
    int data;
    node *next;

} *f = NULL, *r = NULL;

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

    node *p = new node;
    cout << "Enter data: ";
    cin >> p->data;
    p->next = NULL;
    if (f == NULL)
    {
        f = r = p;
    }
    else
    {
        r->next = p;
        r = p;
    }
}

void dequeue()
{

    if (f == NULL)
    {
        cout << "Queue is Empty. Deletion not possible." << endl;
    }
    else if (f->next == NULL)
    {
        cout << "Deleted element has data: " << f->data << endl;
        f = r = NULL;
    }
    else
    {
        cout << "Deleted element has data: " << f->data << endl;
        f = f->next;
    }
}

void traversal()
{
    if (f == NULL)
    {

        cout << "Queue is Empty." << endl;
    }
    else
    {

        for (node *temp = f; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
}
