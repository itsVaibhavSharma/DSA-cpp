#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *tos = NULL;

void push(char ch)
{
    node *p = new node;
    p->data = ch;

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
        cout << "Deletion not possible." << endl;
    }
    else
    {

        tos = tos->next;
    }
}

int main()
{
    cout << "ASSIGNMENT 1 (Q3: EVALUATION OF POSTFIX)" << endl
         << "MADE BY VAIBHAV SHARMA (0901AD231069)" << endl
         << endl;
    string expression;

    while (expression != "exit")
    {
        tos = NULL;
        cout << "Enter the expression in POSTFIX (enter 'exit' to exit): ";
        cin >> expression;

        if (expression == "exit")
        {
            break;
        }

        cout << "POSTFIX: " << expression << endl
             << "EVALUATED VALUE: ";

        for (int i = 0; expression[i] != '\0'; i++)
        {
            if ((int(expression[i]) >= 48 && int(expression[i]) <= 57))
            {
                push(int(expression[i]) - 48);
            }
            else
            {
                int a = tos->data;
                pop();
                int b = tos->data;
                pop();
                switch (expression[i])
                {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if (a == 0)
                    {
                        cout << "Division by 0 is not possible" << endl;
                    }
                    else
                    {
                        push(b / a);
                    }
                    break;
                default:
                    cout << "Invalid expression." << endl;
                }
            }
        }
        
            cout << tos->data << endl;
        
    }

    return 0;
}