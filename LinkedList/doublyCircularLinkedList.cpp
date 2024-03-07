#include <iostream>
using namespace std;

void insert_beg();
void insert_end();
void insert_specific();
void traversal();
void delete_beg();
void delete_end();
void delete_specific();
void display();

struct node
{
    int data;
    node *prev;
    node *next;
} *head = NULL;

int main()
{

    int choice;

    do
    {
        cout << "Enter function number: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_specific();
            break;

        case 4:
            delete_beg();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            delete_specific();
            break;

        case 7:
            traversal();
            break;

        case 8:
            display();
            break;

        case 9:
            return 0;

        default:
            cout << "Enter valid function no." << endl;
        }
    } while (1);

    return 0;
}

void traversal()
{

    if (head == NULL)
    {
        cout << "Empty LinkedList." << endl;
    }
    else
    {
        node *temp = head;

        while (temp->next != head)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << temp->data << endl;
        cout << endl;
    }
}

void insert_beg()
{

    node *p = new node; 
    cout << "Enter data for new node: ";
    cin >> p->data;

    if (head == NULL)
    {
        head = p;
        p->prev = p;
        p->next = p;
    }
    else
    {

        p->prev = head->prev;
        p->next = head;
        (head->prev)->next = p;
        head->prev = p;
        head = p;
    }
}

void insert_end()
{

    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;

    if (head == NULL)
    {

        head = p;
        p->prev = p->next = p;
    }
    else
    {

        p->prev = head->prev;
        p->next = head;
        (head->prev)->next = p;
        head->prev = p;

    }
}

void insert_specific()
{

    int pos, count = 0;
    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;
    cout << "Enter Position: ";
    cin >> pos;

    if (head == NULL)
    {
        head = p;
        p->prev = p;
        p->next = p;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }

        if (pos > count + 2)
        {
            cout << "Enter valid Position. " << endl;
        }
        else
        {

            if (pos == 1)
            {

                p->prev = head->prev;
                p->next = head;
                (head->prev)->next = p;
                head->prev = p;
                head = p;
            }
            else
            {

                temp = head;
                while (pos > 2)
                {
                    pos--;
                    temp = temp->next;
                }

                p->next = temp->next;
                p->prev = temp;
                (temp->next)->prev = p;

                temp->next = p;
            }
        }
    }
}

void delete_beg()
{

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion is not possible." << endl;
    }
    else if (head->next == head)
    {
        cout << "Deleted node contains: " << head->data << endl;
        head = NULL;
    }
    else
    {

        cout << "Deleted node contains: " << head->data << endl;

        (head->next)->prev = head->prev;
        (head->prev)->next = head->next;
        head = head->next;
    }
}

void delete_end()
{

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion is not possible." << endl;
    }
    else if (head->next == head)
    {
        cout << "Deleted node contains: " << head->data << endl;
        head = NULL;
    }
    else
    {

        cout << "Deleted node contains: " << (head->prev)->data << endl;

        ((head->prev)->prev)->next = head;
        head->prev = (head->prev)->prev;
    }
}

void delete_specific()
{

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion is not possible." << endl;
    }
    else
    {
        int pos, count = 0;
        cout << "Enter the position for deletion: ";
        cin >> pos;

        node *temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }

        if (pos > count + 1)
        {
            cout << "Limit exceeded!!" << endl;
        }
        else
        {
            if (pos == 1)
            {
                delete_beg();
            }
            else
            {

                temp = head;
                int position = pos;
                while (pos > 2)
                {
                    pos--;
                    temp = temp->next;
                }

                cout << "Deleted node contains: " << (temp->next)->data << endl;

                if (position == count + 1)
                {
                    temp->next = head;
                }
                else
                {
                    ((temp->next)->next)->prev = temp;
                    temp->next = (temp->next)->next;
                }
            }
        }
    }
}

void display()
{

    if (head == NULL)
    {
        cout << "LinkedList is empty." << endl;
    }
    else
    {
        int pos, count = 0;
        cout << "Enter position to Display: ";
        cin >> pos;

        node *temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }

        if (pos > count + 1)
        {
            cout << "Entered position does not exist." << endl;
        }
        else
        {

            temp = head;
            while (pos > 1)
            {
                temp = temp->next;
                pos--;
            }

            cout << temp->data << endl;
        }
    }
}