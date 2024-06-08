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
    node *next;
} *head = NULL;

int main()
{

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    head = node1;

    node1->data = 23;
    node1->next = node2;

    node2->data = 10;
    node2->next = node3;

    node3->data = 4;
    node3->next = node1;

    int choice;

    do
    {
        cout << "Enter function number: " << endl;
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
            cout << "Enter Valid Function no." << endl;
        }
    } while (1);

    return 0;
}

void traversal()
{

    node *temp = head;
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    else
    {
        while ((temp->next) != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " " << endl
             << endl;
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
        p->next = p;
    }
    else
    {
        p->next = head;
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = p;
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

        p->next = p;
        head = p;
    }
    else
    {

        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = p;
        p->next = head;
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

    node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;

    if ((pos < 1) || (pos > count + 1))
    {
        cout << "Enter valid position." << endl;
    }
    else
    {

        if (pos == 1)
        {

            if (head == NULL)
            {
                head = p;
                p->next = p;
            }
            else
            {

                p->next = head;
                node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = p;
                head = p;
            }
        }
        else
        {
            // (head) N1 -> N2 -> N3 -> N4 -> head

            temp = head;
            while (pos > 2)
            {
                pos--;
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
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
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
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
        // (head) N1 -> N2 -> N3 -> N4 -> head
        // (head) N1 -> N2 -> N3 -> head

        node *temp = head;
        while ((temp->next)->next != head)
        {
            temp = temp->next;
        }
        cout << "Deleted node contains: " << (temp->next)->data << endl;
        temp->next = head;
    }
}

void delete_specific()
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
    count++;

    if ((pos < 1) || (pos > count))
    {
        cout << "Limit exceeding!!" << endl;
    }
    else
    {

        if (head == NULL)
        {
            cout << "LinkedList is Empty. Deletion is not possible." << endl;
        }
        else if (pos == 1)
        {
            cout << "Deleted node contains: " << head->data << endl;

            if (head->next == head)
            {

                head = NULL;
            }
            else
            {
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
            }
        }
        else
        {

            temp = head;
            while (pos > 2)
            {
                pos--;
                temp = temp->next;
            }

            cout << "Deleted node contains: " << (temp->next)->data << endl;
            temp->next = (temp->next)->next;
        }
    }
}

void display()
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
    count++;

    if ((pos < 1) || (pos > count))
    {
        cout << "Entered position does not exist." << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "LinkedList is empty." << endl;
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