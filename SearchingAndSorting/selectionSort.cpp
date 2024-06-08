#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
