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

    

    int choice;

    do
    {
        cout << "Enter function number: " ;
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
            cout << "Dimag lagao sahi value dalo" << endl;
        }
    } while (1);

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
        while (temp->next != NULL)
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
    p->next = head;
    head = p;

    return;
}

void insert_end()
{

    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;

    p->next = NULL;

    if (head == NULL)
    {

        head = p;
    }
    else
    {

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }
}

/*
void insert_end(){
    CREATE NEW NODE node* p = new node
    p -> next = NULL;
    INPUT p-> data;
    IF head == NULL
        head = p;
    ELSE
        CREATE NEW NODE node*temp = head;
        WHILE temp-> next != NULL
             temp = temp-> next;
        temp -> next = p;
}



*/

void insert_specific()
{
    // (head) N1 -> N2 -> N3 -> N4 -> NULL

    int pos, count = 0;
    node *p = new node;
    cout << "Enter data for new node: ";
    cin >> p->data;
    cout << "Enter Position: ";
    cin >> pos;

    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count + 1)
    {
        cout << "Sahi position dalo " << endl;
    }
    else
    {
        // pos =3
        // (head) N1 -> N2 -> N3 -> N4 -> NULL

        if (pos == 1)
        {

            p->next = head;
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
    else
    {
        cout << "Deleted node contains: " << head->data << endl;
        head = head->next;
    }

}
/*
void delete_beg(){
    IF head == NULL
        PRINT "linkedlist is empty"
    ELSE
        PRINT "DELETED NODE: " + head -> data;
        head = head-> next;
}

1. start
2. If head == null then print error
3. else 
     deleted node : head-> data
     head = head-> next
4. end



*/

void delete_end()
{

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion is not possible." << endl;
    }
    else if (head->next == NULL)
    {
        cout << "Deleted node contains: " << head->data << endl;
        head = NULL;

    }
    else
    {
        // (head) N1 -> N2 -> N3 -> N4 -> NULL
        node *temp = head;
        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Deleted node contains: " << (temp->next)->data << endl;
        temp->next = NULL;
    }
}

void delete_specific()
{
    // (head) N1 -> N2 -> N3 -> N4 -> NULL

    int pos, count = 0;
    cout << "Enter the position for deletion: ";
    cin >> pos;

    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count)
    {
        cout << "Limit exceeding!!" << endl;
    }
    else
    {
        // (head) N1 -> N2 -> N3 -> N4 -> NULL
        if (head == NULL)
        {
            cout << "LinkedList is Empty. Deletion is not possible." << endl;
        }
        else if (pos == 1)
        {
            cout << "Deleted node contains: " << head->data << endl;
            head = head->next;
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
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count)
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
            // (head) N1 -> N2 -> N3 -> N4 -> NULL

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