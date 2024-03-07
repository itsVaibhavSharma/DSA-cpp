#include <iostream>
using namespace std;
    void insert_beg();
    void insert_end();
    void insert_specific();
    void delete_beg();
    void delete_end();
    void delete_specific();
    void traversal();
    void display();
    void sort();

struct node
{
    string name;
    int id;
    node *next;
} *head = NULL;

int main()
{

    // node *node1 = new node;
    // node *node2 = new node;
    // node *node3 = new node;

    // head = node1;

    // node1 -> name = "NODE1";
    // node1 -> id = 1;
    // node1 -> next = node2;

    //  node2 -> name = "NODE2";
    // node2 -> id = 2;
    // node2 -> next = node3;

    //  node3 -> name = "NODE3";
    // node3 -> id = 3;
    // node3 -> next = NULL;



    int choice;

    do
    {
        
        cout << "Enter 1 for INSERTION AT BEGINNING" << endl
        << "Enter 2 for INSERTION AT END" << endl
        << "Enter 3 for INSERTION AT SPECIFIC POSITION" << endl
        << "Enter 4 for DELETION AT BEGINNING" << endl
        << "Enter 5 for DELETION AT END" << endl
        << "Enter 6 for DELETION AT SPECIFIC POSITION" << endl
        << "Enter 7 for TRAVERSAL" << endl
        << "Enter 8 for DISPLAY NODE USING INDEX" << endl
        << "Enter 9 to EXIT" << endl << endl;
        cout << "Enter Function no.: ";

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
        case 10:
            sort();
        default:
            cout << "Enter valid Function no. (between 1 to 9)." << endl;
        }
    } while (1);

    return 0;
}

void traversal()
{
    if (head == NULL)
    {
        cout << "LinkedList is empty." << endl
             << endl;
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {
            cout << t->name << ", " << t->id << " | ";
            t = t->next;
        }
        cout << t->name << ", " << t->id << endl
             << endl;
    }
}

void insert_beg()
{
    //(head)node1 -> node2 -> node3 -> NULL

    node *p = new node;
    cout << "Enter name for New Node (Student) : ";
    cin >> p->name;
    cout << "Enter id for New Node (Student) : ";
    cin >> p->id;

    
        p->next = head;
        head = p;
    
}

void insert_end()
{
    //(head) NULL

    //(head) -> node1 -> NULL

    //(head)node1 -> node2 -> node3 -> NULL

    //(head)node1 -> node2 -> node3 -> NULL
    //(head)node1 -> node2 -> node3 -> NULL
    node *p = new node;
    cout << "Enter name for New Node (Student) : ";
    cin >> p->name;
    cout << "Enter id for New Node (Student) : ";
    cin >> p->id;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {

            t = t->next;
        }
        t->next = p;
    }
}

void insert_specific()
{

    node *p = new node;
    cout << "Enter name for New Node (Student) : ";
    cin >> p->name;
    cout << "Enter id for New Node (Student) : ";
    cin >> p->id;

    int pos, count = 0;

    node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }

    cout << "Enter Position: ";
    cin >> pos;
    //    while(pos > count + 1) {
    //     cout << "Enter VALID Position: ";
    //    cin >> pos;
    //    }

    if ((pos < 1) || (pos > count + 1))
    {
        cout << "Invalid Position Entered." << endl << endl;
    }
    else
    {

        t = head;
        if (head == NULL)
        {
            p->next == NULL;
            head = p;
        }
        else if (pos == 1)
        {
            p->next = head;
            head = p;
        }
        else
        {
            while (pos > 2)
            {

                t = t->next;
                pos--;
            }
            p->next = t->next;
            t->next = p;
        }
    }
}

void delete_beg()
{

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion not Possible." << endl;
    }
    else
    {
        cout << "Deleted Node contains: " << head->name << ", " << head->id << endl << endl;

        head = head->next;
    }
}
void delete_end()
{
    //(head) node1 -> NULL

    if (head == NULL)
    {
        cout << "LinkedList is Empty. Deletion not Possible." << endl << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        node *t = head;
        while ((t->next)->next != NULL)
        {
            t = t->next;
        }
        cout << "Deleted Node contains: " << (t->next)->name << ", " << (t->next)->id << endl << endl;
        t->next = NULL;
    }
}

void delete_specific()
{

    int pos, count = 0;

    node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }

    cout << "Enter Position of Node to Delete: ";
    cin >> pos;
    //    while(pos > count + 1) {
    //     cout << "Enter VALID Position: ";
    //    cin >> pos;
    //    }

    if ((pos < 1) || (pos > count))
    {
        cout << "Invalid Position Entered."<< endl << endl;
    }
    else
    {

        //(head) NULL

        //(head) -> node1 -> NULL

        //(head)node1 -> node2 -> node3 -> NULL

        //(head)node1 -> node2 -> node3 -> node4 -> NULL
        //(head)node1 -> node2  -> node4 -> NULL
        t = head;
        if (head == NULL)
        {
            cout << "LinkedList is Empty. Deletion not Possible." << endl << endl;
        }
        else if (pos == 1)
        {
            cout << "Deleted Node contains: " << head->name << ", " << head->id << endl
                 << endl;

            head = head->next;
        }
        else
        {

            while (pos > 2)
            {

                t = t->next;
                pos--;
            }

            cout << "Deleted Node contains: " << (t->next)->name << ", " << (t->next)->id << endl
                 << endl;

            t->next = (t->next)->next;
        }
    }
}

void display()
{
    int pos, count = 0;

    node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    cout << "Enter position to Display Node: ";
    cin >> pos;

    if ((pos < 1) || (pos > count))
    {
        cout << "Invalid Position Entered.";
    }
    else
    {
        t = head;
        while (pos > 1)
        {
            t = t->next;
            pos--;
        }
        cout << t->name << ", " << t->id << endl
             << endl;
    }
}

void sort() {

    int count =0;
    node *t = head;
    while(t != NULL) {
        t = t-> next;

    }
    for(int i = 0; i < count ; i++){
        t = head;
        for(int j =i; j < count; j++){
            node *s = head;
            if((t->id) < (s->next)-> id){
                ((t) -> next)  = (s-> next) -> next;
                //t->next = (t-> next) -> next;
                (t->next) -> next =  ((t->next) -> next) -> next;

            }

            
        }
    }




}