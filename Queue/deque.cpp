#include <iostream>
using namespace std;

void enqueue_front();
void enqueue_rear();
void dequeue_front();
void dequeue_rear();
void traversal_front();
void traversal_rear();

struct node
{
    int data;
    node *next;
    node *prev;

} *f = NULL, *r = NULL;

int main()
{

    int ch;
    cout << "Enter 1 for Insertion at front" << endl
         << "Enter 2 for Insertion at rear" << endl
         << "Enter 3 for Deletion at front" << endl
         << "Enter 4 for Deletion at rear" << endl
         << "Enter 5 for Traversal from front" << endl
         << "Enter 6 for Traversal from rear" << endl
         << "Enter 7 to EXIT" << endl;
    do
    {
        cout << "Enter function no.: ";

        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue_front();
            break;
        case 2:
            enqueue_rear();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            traversal_front();
            break;
        case 6:
            traversal_rear();
            break;
        case 7:
            return 0;
        default:
            cout << "Enter valid function no.";
        }
    } while (1);

    return 0;
}

void enqueue_front()
{

    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;

    if (f == NULL)
    {
        f = p;
        p->prev = NULL;
        p->next = NULL;
        r = p;
    }
    else
    {
        p->prev = NULL;
        p->next = f;
        f->prev = p;
        f = p;
    }
}

void enqueue_rear()
{

    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;

    if (f == NULL)
    {
        f = p;
        p->prev = NULL;
        p->next = NULL;
        r = p;
    }
    else
    {
        p->next = NULL;
        p->prev = r;
        r->next = p;
        r = p;
    }
}

void dequeue_front()
{

    if (f == NULL)
    {
        cout << "Queue is Empty. Deletion is not possible." << endl;
    }
    else if (f->next == NULL)
    {
        cout << "Deleted node contains: " << f->data << endl;
        f = r = NULL;
    }
    else
    {
        cout << "Deleted node contains: " << f->data << endl;
        f = f->next;
        f->prev = NULL;
    }
}

void dequeue_rear()
{

    if (f == NULL)
    {
        cout << "Queue is Empty. Deletion is not possible." << endl;
    }
    else if (f->next == NULL)
    {
        cout << "Deleted node contains: " << f->data << endl;
        f = r = NULL;
    }
    else
    {
        cout << "Deleted node contains: " << r->data << endl;

        r = r->prev;
        r->next = NULL;
    }
}

void traversal_front()
{

    if (f == NULL)
    {
        cout << "Empty Queue." << endl;
    }
    else
    {
        node *temp = f;

        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void traversal_rear()
{

    if (r == NULL)
    {
        cout << "Empty Queue." << endl;
    }
    else
    {
        node *temp = r;

        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->prev;
        }
        cout << endl;
    }
}