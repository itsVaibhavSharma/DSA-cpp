#include <iostream>
using namespace std;
const int s = 10;
int stack[s], tos = -1;
int stack_empty();
int stack_full();
void push();
void pop();
int sz();
void traversal();

int main()
{
    int choice;
    cout << "Enter 1: for PUSH AT TOP OF STACK" << endl;
    cout << "Enter 2: for POP AT TOP OF STACK" << endl;
    cout << "Enter 3: for TRAVERSAL" << endl;
    cout << "Enter 4: size of stack" << endl;
    cout << "Enter 5: is stack empty?" << endl;
    cout << "Enter 6: is stack full?" << endl;
    cout << "Enter 7 to EXIT" << endl;
    do
    {

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
            cout << "Filled Size of Stack: " << tos+1 << endl;

            break;

        case 5:
            if (stack_empty())
            {
                cout << "Stack is Empty." << endl;
            }
            else
            {
                cout << "Stack is not Empty." << endl;
            }

            break;

        case 6:

            if (stack_full())
            {
                cout << "Stack is Full." << endl;
            }
            else
            {
                cout << "Stack is not Full." << endl;
            }

            break;

        case 7:
            return 0;
        default:
            cout << "Enter valid Function no. (between 1 to 7)." << endl;
        }
    } while ((choice != 7));

    return 0;
}

int stack_empty()
{
    if (tos == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stack_full()
{
    if (tos == s - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push()
{
    if (stack_full())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> stack[++tos];
    }
}
void pop()
{
    if (stack_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Deleted element is: " ;
        cout << stack[tos--]<< endl;
    }
}
void traversal()
{
    if (stack_empty())
    {
        cout << "Empty stack" << endl;
    }
    else
    {
        for (int i = 0; i <= tos; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

