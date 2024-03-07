#include <iostream>
using namespace std;
void push();
void pop();
void traversal();

struct node
{
    int data;
    node *next;
} *tos = NULL;

int main()
{
    int choice;

    do
    {

        cout << "Enter 1 for PUSH AT TOP" << endl
             << "Enter 2 for POP AT TOP" << endl
             << "Enter 3 for TRAVERSAL" << endl
             << "Enter 4 to EXIT" << endl
             << endl;
        cout << "Enter Function no.: ";

        cin >> choice;
        switch (choice)
        {

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            traversal();
            break;
        case 4:
            return 0;
        default:
            cout << "Enter valid Function no. (between 1 to 4)." << endl;
        }
    } while (1);

    return 0;
}
void push()
{
    node *p = new node;
    cout << "Enter data" << endl;
    cin >> p->data;
    if (tos == NULL)
    {
        p->next = NULL;
    }
    else
    {
        p->next = tos;
    }
    tos = p;
}
void pop()
{
    if (tos == NULL)
    {
        cout << "Deletion is not possible" << endl;
    }
    else
    {
        cout << "Deleted element is " << tos->data << endl;
        tos = tos->next;
    }
}
void traversal()
{
    if (tos == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        node *t = tos;
        while (t != NULL)
        {
            cout << "Data"
                 << " " << t->data << endl;
            t = t->next;
        }
    }
}