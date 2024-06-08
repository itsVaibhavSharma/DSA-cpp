#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Number of elements : " ;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements  " << i + 1 << " : ";
        cin >> a[i];
    }
    int count = 0;
    while (count < n)
    {
        for (int i = 0; i < n - count - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        count++;
    }
     cout <<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
       
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}