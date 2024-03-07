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
    cout << "ASSIGNMENT 1 (Q2: INFIX TO POSTFIX)" << endl
         << "MADE BY VAIBHAV SHARMA (0901AD231069)" << endl
         << endl;
    string expression;

    while (expression != "exit")
    {
        tos = NULL;
        cout << "Enter the expression in INFIX (Enter 'exit' to exit): ";
        cin >> expression;
        if (expression == "exit")
        {
            break;
        }

        cout << "INFIX: " << expression << endl
             << "POSTFIX: ";

        for (int i = 0; expression[i] != '\0'; i++)
        {

            if ((int(expression[i]) >= 65 && int(expression[i]) <= 90) || (int(expression[i]) >= 97 && int(expression[i]) <= 122) || (int(expression[i]) >= 48 && int(expression[i]) <= 57))
            {
                cout << expression[i];
            }
            else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
            {
                while ((tos->data != '(') && (tos->data != '[') && (tos->data != '{'))
                {
                    cout << tos->data;
                    pop();
                }
                pop();
            }
            else
            {

                if (expression[i] == '+')
                {
                    if (tos != NULL)
                    {
                        while ((tos != NULL) && (tos->data == '-' || tos->data == '*' || tos->data == '/' || tos->data == '^'))
                        {
                            cout << tos->data;
                            pop();
                        }
                    }
                }
                if (expression[i] == '-')
                {
                    if (tos != NULL)
                    {
                        while ((tos != NULL) && (tos->data == '*' || tos->data == '/' || tos->data == '^'))
                        {
                            cout << tos->data;
                            pop();
                        }
                    }
                }
                else if (expression[i] == '*')
                {
                    if (tos != NULL)
                    {
                        while ((tos != NULL) && (tos->data == '/') || (tos->data == '^'))
                        {
                            cout << tos->data;
                            pop();
                        }
                    }
                }
                else if (expression[i] == '/')
                {
                    if (tos != NULL)
                    {
                        while ((tos != NULL) && tos->data == '^')
                        {
                            cout << tos->data;
                            pop();
                        }
                    }
                }
                push(expression[i]);
            }
        }

        while (tos != NULL)
        {
            cout << tos->data;
            pop();
        }
        cout << endl;
    }

    return 0;
}