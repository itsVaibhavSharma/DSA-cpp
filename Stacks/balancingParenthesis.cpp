#include <iostream>
using namespace std;

struct node
{
    char data;
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
    cout << "ASSIGNMENT 1 (Q1: BALANCING OF PARENTHESIS)" << endl
         << "MADE BY VAIBHAV SHARMA (0901AD231069)" << endl
         << endl;
    string expression;
    bool validity = true;

    while (expression != "exit")
    {
        tos = NULL;
        cout << "Enter the Expression (Enter 'exit' to exit): ";
        cin >> expression;
        if (expression == "exit")
        {
            break;
        }

        for (int i = 0; expression[i] != '\0'; i++)
        {
            if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))
            {
                push(expression[i]);
            }
            else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
            {
                if (tos == NULL)
                {
                    validity = false;

                    break;
                }
                else if (((tos->data == '(') && expression[i] == ')') || ((tos->data == '[') && expression[i] == ']') || ((tos->data == '{') && expression[i] == '}'))
                {
                    pop();
                }
                else
                {
                    validity = false;

                    break;
                }
            }
        }

        if (validity)
        {
            cout << "EXPRESSION IS VALID" << endl;
        }
        else
        {
            cout << "EXPRESSION IS INVALID" << endl;
        }
    }
    return 0;
}