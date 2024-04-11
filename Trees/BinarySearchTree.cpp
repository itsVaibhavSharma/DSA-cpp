#include <iostream>
using namespace std;

// Binary tree
struct node
{
    node *leftchild;
    int data;
    node *rightchild;
} *root = NULL;

void insertion1();
void preOrder(node *r);
void inOrder(node *r);
void postOrder(node *r);
void levelOrder();
node *insertion2(node *r, int data);
void print(node *r, int);
node *searchIt(int val);
node *searchRec(node *r, int val);
int height(node *r);
void printGivenLevel(node *r, int level);
node *deletion(node *r, int value);
node *minValue(node *r);

// insertion
// traversal - 4
// search
// printing
// deletion

int main()
{

    //           20
    //     10           25
    // 5       15    23     30

    // 1 2 4 5 3 6 7
    // 4 2 5 1 6 3 7
    // 4 5 2 6 7 3 1

    node *n1 = new node;
    node *n2 = new node;
    node *n3 = new node;
    node *n4 = new node;
    node *n5 = new node;
    node *n6 = new node;
    node *n7 = new node;

    root = n1;
    n1->data = 20;
    n1->leftchild = n2;
    n1->rightchild = n3;
    n2->data = 10;
    n3->data = 25;
    n2->leftchild = n4;
    n2->rightchild = n5;
    n3->leftchild = n6;
    n3->rightchild = n7;
    n4->data = 5;
    n5->data = 15;
    n6->data = 23;
    n7->data = 30;
    n4->leftchild = NULL;
    n4->rightchild = NULL;
    n5->leftchild = NULL;
    n5->rightchild = NULL;
    n6->leftchild = NULL;
    n6->rightchild = NULL;
    n7->leftchild = NULL;
    n7->rightchild = NULL;

    int ch;

    do
    {

        cout << "Enter 1 for Insertion (Iterative)" << endl
             << "Enter 2 for Pre-Order Traversal" << endl
             << "Enter 3 for In-Order Traversal" << endl
             << "Enter 4 for Post-Order Traversal" << endl
             << "Enter 5 for Level-Order Traversal" << endl
             << "Enter 6 for Insertion (Recursive)" << endl
             << "Enter 7 for print" << endl
             << "Enter 8 for Search (Iterative)" << endl
             << "Enter 9 for Search (Recursive)" << endl
             << "Enter 10 for Height" << endl
             << "Enter 11 for Print Given Level" << endl
             << "Enter 12 for Deletion" << endl
             << "Enter 0 to EXIT" << endl;
        
        cout << "Enter Function no.: ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            break;
        case 1:
            insertion1();
            break;
        case 2:
            preOrder(root);
            break;

        case 3:
            inOrder(root);
            break;

        case 4:
            postOrder(root);
            break;

        case 5:
            levelOrder();
            break;
        case 6:
            int data;
            cout << "Enter data for new node: ";
            cin >> data;

            root = insertion2(root, data);
            break;

        case 7:
            print(root, 0);
            break;

        case 8:
            cout << "Enter data to search: ";
            int value;
            cin >> value;
            if (searchIt(value) == NULL)
            {
                cout << "Value not found." << endl;
            }
            else
            {
                cout << searchIt(value) << endl;
            }

            break;

        case 9:
            cout << "Enter data to search: ";

            cin >> value;
            if (searchRec(root, value) == NULL)
            {
                cout << "Value not found." << endl;
            }
            else
            {
                cout << searchRec(root, value) << endl;
            }

            break;

        case 10:
            cout << height(root) << endl;
            break;

        case 11:
            int level;
            cout << "Enter level no. to print: ";
            cin >> level;
            printGivenLevel(root, level);
            break;

        case 12:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deletion(root, value);
        }

        cout << endl;

    } while (ch != 0);

    return 0;
}

// inorder ka ulta
void print(node *r, int space)
{
    if (r == NULL)
    {

        return;
    }
    else
    {
        space += 10;
        print(r->rightchild, space);
        cout << endl;
        for (int i = 0; i < space; i++)
        {
            cout << " ";
        }
        cout << r->data << endl;
        print(r->leftchild, space);
    }
}

void insertion1()
{
    //               20
    //         10             25
    //     5       15    23        30

    node *newnode = new node;
    cout << "Enter data for new node: ";
    cin >> newnode->data;
    newnode->leftchild = newnode->rightchild = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == newnode->data)
            {
                return;
            }
            else if ((newnode->data < temp->data) && (temp->leftchild == NULL))
            {
                temp->leftchild = newnode;
                break;
            }
            else if (newnode->data < temp->data)
            {
                temp = temp->leftchild;
            }
            else if ((newnode->data > temp->data) && (temp->rightchild == NULL))
            {
                temp->rightchild = newnode;
                break;
            }
            else
            {
                temp = temp->rightchild;
            }
        }
    }
}

void preOrder(node *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        cout << r->data << " ";
        preOrder(r->leftchild);
        preOrder(r->rightchild);
    }
}

void inOrder(node *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {

        inOrder(r->leftchild);
        cout << r->data << " ";
        inOrder(r->rightchild);
    }
}

void postOrder(node *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {

        postOrder(r->leftchild);
        postOrder(r->rightchild);
        cout << r->data << " ";
    }
}

void levelOrder()
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        printGivenLevel(root, i);
    }
}

node *insertion2(node *r, int data)
{
    if (r == NULL)
    {
        r = new node;
        r->leftchild = r->rightchild = NULL;
        r->data = data;
    }
    else
    {
        if (data < r->data)
        {
            r->leftchild = insertion2(r->leftchild, data);
        }
        else
        {
            r->rightchild = insertion2(r->rightchild, data);
        }
    }

    return r;
}

node *searchIt(int val)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        node *temp = root;
        while (temp != NULL)
        {
            if (val == temp->data)
            {
                return temp;
            }
            else if (val < temp->data)
            {
                temp = temp->leftchild;
            }
            else
            {
                temp = temp->rightchild;
            }
        }
        return NULL;
    }
}

node *searchRec(node *r, int val)
{
    if (r == NULL || r->data == val)
    {
        return r;
    }
    else if (val < r->data)
    {
        return searchRec(r->leftchild, val);
    }
    else
    {
        return searchRec(r->rightchild, val);
    }
}

int height(node *r)
{
    //               20
    //         10             25
    //     5       15     23        30
    //                      24

    /*
    20 lh = 1
        10 lh = 0
            5 lh =-1
              rh = -1
           rh = 0
            15 lh = -1
               rh = -1
        rh = 2
            25 lh= 1
                23 lh =-1
                   rh = 0
                    24 lh =-1
                       rh =-1

                rh = 0
                    30 lh = -1
                       rh = -1



    rh +1 = 3


    */

    if (r == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = height(r->leftchild);
        int rheight = height(r->rightchild);
        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }
    }
}

void printGivenLevel(node *r, int level)
{
    //               20                     //level0
    //         10             25            //level1
    //     5       15     23        30      //level2
    //                      24              //level3

    if (r == NULL)
    {
        return;
    }
    else if (level == 0)
    {
        cout << r->data << " ";
    }
    else
    {
        printGivenLevel(r->leftchild, level - 1);
        printGivenLevel(r->rightchild, level - 1);
    }
}

node *deletion(node *r, int value)
{

    //               20                     //level0
    //         10             25            //level1
    //     5       15     23        30      //level2
    //                      24              //level3

    //               20                     //level0
    //         10             25            //level1
    //     5       15     24        30      //level2
    //                                      //level3

    //               23                     //level0
    //         10             25            //level1
    //     5       15     24        30      //level2
    //                                      //level3

    // no child
    // single child
    // double child

    if (r == NULL)
    {
        return NULL;
    }
    else if (value < r->data)
    {
        r->leftchild = deletion(r->leftchild, value);
    }
    else if (value > r->data)
    {
        r->rightchild = deletion(r->rightchild, value);
    }
    else
    {
        if (r->leftchild == NULL)
        {
            return r->rightchild;
        }
        else if (r->rightchild == NULL)
        {
            return r->leftchild;
        }
        else
        {
            node *temp = minValue(r->rightchild);
            r->data = temp->data;
            r->rightchild = deletion(r->rightchild, temp->data);
        }
    }
    return r;

    //               23                     //level0
    //         10             25            //level1
    //     5       15     24       30       //level2
    //                                      //level3

    /*
    main
    20 |
        temp =23
        r (20) = 23
        r(23) R = 25
            25|
                25 L = 24
                    23 |

    23 main
    */
}

node *minValue(node *r)
{
    node *temp = r;
    while (temp->leftchild != NULL)
    {
        temp = temp->leftchild;
    }
    return temp;
}