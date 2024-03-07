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
    cout << "Enter the Expression to check the balancing of parathesis: ";
    cin >> expression;
    cout << "INFIX: " << expression << endl
         << "POSTFIX: ";

    for (int i = 0; expression[i] != '\0'; i++)
    {

        if ((int(expression[i]) >= 65 && int(expression[i]) <= 90) || (int(expression[i]) >= 97 && int(expression[i]) <= 122))
        {
            cout << expression[i];
           // cout << "nice3";
        }
        else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
        {
            while ((tos->data != '(') || (tos->data != '[') || (tos->data != '{'))
            {
                cout << tos->data;
                pop();
             //   cout << "nice4";
            }
            pop();
        } else if(((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))){
            push(expression[i]);
        }
        else
        {
           // cout << "nice5";

            if (expression[i] == '*' || expression[i] == '/')
            {
                while (tos->data != '+' || tos->data != '-' || tos != NULL || (tos->data != '(') || (tos->data != '[') || (tos->data != '{'))
                {
                    cout << tos->data;
                    pop();
                   // cout << "nice6";
                }
            }

            else
            {
               // cout << "nice8";
                
                while ((tos != NULL) && ((tos->data != '(') || (tos->data != '[') || (tos->data != '{')))
                {
               //      cout << "nice";
                    cout << tos->data;
                    pop();
                   
                }
               // cout <<"hy";
            }
         //   cout << "nice2";
            push(expression[i]);
        }
    }

    while (tos != NULL)
    {
        cout << tos->data;
        pop();
    }

    return 0;
}
