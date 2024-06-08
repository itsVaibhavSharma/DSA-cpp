#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << " Enter number of elements : ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << " Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
    cout << " Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
