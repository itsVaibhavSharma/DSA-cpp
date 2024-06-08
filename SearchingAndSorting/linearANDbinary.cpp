#include <iostream>
using namespace std;

int *arr;
int n;

void create()
{

    cout << "Enter no. of elements in array: ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> arr[i];
    }
}

void linearSearch()
{
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    int i;
    for (i = 0; i < n; i++)
    {
        if (value == arr[i])
        {
            cout << "Value found at index: " << i << endl;
            break;
        }
    }
    if (i == n)
    {
        cout << "Value not Found." << endl;
    }
}

void binary(int value)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == value)
        {
            cout << "Value found at index: " << mid << endl;
            break;
        }
        else if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

void binarySearch(int value, int low = 0, int high = n - 1)
{

    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (value == arr[mid])
        {
            cout << "Value found at index: " << mid << endl;
            return;
        }
        else if (value < arr[mid])
        {
            binarySearch(value, low, mid - 1);
            return;
        }
        else
        {
            binarySearch(value, mid + 1, high);
            return;
        }
    }

    cout << "Value not found" << endl;
}

int main()
{
    int ch;
    do
    {
        cout << endl
             << "Enter 1 to Create array"
             << endl
             << "Enter 2 to linear search"
             << endl
             << "Enter 3 to Binary search (Iterative)"
             << endl
             << "Enter 4 to Binary search (Recursive)"
             << endl
             << "Enter 0 to Exit" << endl
             << endl;

        cout << "Enter Function number: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            linearSearch();
            break;
        case 3:
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            binary(value);
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            binarySearch(value);
            break;
        case 0:
            break;
        }
    } while (ch != 0);

    return 0;
}
