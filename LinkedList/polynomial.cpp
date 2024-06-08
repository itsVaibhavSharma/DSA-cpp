#include <iostream>
using namespace std;

void create();
void addition();
void subtraction();
void display();

struct node {
    float coe;
    int exp;
    node *next;
} *p[4] = {NULL};

int main()
{
    cout << "Enter 1 for Creating Polynomial Equations." << endl
         << "Enter 2 for Addition of Polynomials." << endl
         << "Enter 3 for Subtracton of Polynomials." << endl
         << "Enter 4 to Display." << endl
         << "Enter 5 to Exit." << endl;

    int choice;

    do
    {
        cout << "Enter function number: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            addition();
            break;
        case 3:
            subtraction();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            cout << "Enter correct function no." << endl;
        }
    } while (1);

    return 0;
}

void display()
{

    for (int i = 0; i < 4; i++)
    {

        if (p[i] != NULL)
        {
            if (i == 0)
            {
                cout << "Polynomial 1: ";
            }
            else if (i == 1)
            {
                cout << "Polynomial 2: ";
            }
            else if (i == 2)
            {
                cout << "Addition: ";
            }
            else if (i == 3)
            {
                cout << "Subtraction: ";
            }

            node *temp = p[i];
            while (temp->next != NULL)
            {
                if (temp->coe > 0)
                {
                    cout << '+';
                }
                cout << temp->coe << "x^" << temp->exp;
                temp = temp->next;
            }
            if (temp->coe > 0)
            {
                cout << '+';
            }
            cout << temp->coe << "x^" << temp->exp << endl;
        }
    }
    cout << endl;
}

void create()
{
    char newT;
    node *current = NULL;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter Polynomial " << i + 1 << " :" << endl;

        do
        {

            node *a = new node;
            cout << "Enter coefficient: ";
            cin >> a->coe;
            cout << "Enter exponent: ";
            cin >> a->exp;
            a->next = NULL;
            if (p[i] == NULL)
            {
                p[i] = a;
                current = a;
            }
            else
            {
                current->next = a;
                current = a;
            }

            cout << "Do you want to add another term? (Y/N): ";
            cin >> newT;
        } while (newT == 'Y');
    }
}

void addition()
{
    node *t1 = p[0], *t2 = p[1], *t3 = p[2];
    node *current = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp < t2->exp)
        {
            node *c = new node;
            c->coe = t2->coe;
            c->exp = t2->exp;
            c->next = NULL;

            if (p[2] == NULL)
            {
                p[2] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            node *c = new node;
            c->coe = t1->coe;
            c->exp = t1->exp;
            c->next = NULL;

            if (p[2] == NULL)
            {
                p[2] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
        }
        else
        {
            node *c = new node;
            c->coe = t1->coe + t2->coe;
            c->exp = t1->exp;
            c->next = NULL;

            if (p[2] == NULL)
            {
                p[2] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    if (t1 != NULL)
    {
        while (t1 != NULL)
        {
            node *c = new node;
            c->coe = t1->coe;
            c->exp = t1->exp;
            c->next = NULL;
            if (p[2] == NULL)
            {
                p[2] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
        }
    }
    if (t2 != NULL)
    {
        while (t2 != NULL)
        {
            node *c = new node;
            c->coe = t2->coe;
            c->exp = t2->exp;
            c->next = NULL;
            if (p[2] == NULL)
            {
                p[2] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t2 = t2->next;
        }
    }
    cout << "Addition Successful." << endl;
}

void subtraction()
{
    node *t1 = p[0], *t2 = p[1], *t3 = p[3];

    node *current = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp < t2->exp)
        {
            node *c = new node;
            c->coe = -1 * (t2->coe);
            c->exp = t2->exp;
            c->next = NULL;

            if (p[3] == NULL)
            {
                p[3] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            node *c = new node;
            c->coe = t1->coe;
            c->exp = t1->exp;
            c->next = NULL;

            if (p[3] == NULL)
            {
                p[3] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
        }
        else
        {
            node *c = new node;
            c->coe = t1->coe - t2->coe;
            c->exp = t1->exp;
            c->next = NULL;

            if (p[3] == NULL)
            {
                p[3] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    if (t1 != NULL)
    {
        while (t1 != NULL)
        {
            node *c = new node;
            c->coe = t1->coe;
            c->exp = t1->exp;
            c->next = NULL;
            if (p[3] == NULL)
            {
                p[3] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t1 = t1->next;
        }
    }
    if (t2 != NULL)
    {
        while (t2 != NULL)
        {
            node *c = new node;
            c->coe = -1 * (t2->coe);
            c->exp = t2->exp;
            c->next = NULL;
            if (p[3] == NULL)
            {
                p[3] = c;
                current = c;
            }
            else
            {
                current->next = c;
                current = c;
            }
            t2 = t2->next;
        }
    }
    cout << "Subtraction Successful." << endl;
}