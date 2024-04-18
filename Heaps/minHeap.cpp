#include <iostream>
using namespace std;

int *harr;
int CAPACITY;
int heap_size;
int parent(int);
void print();
int extractMin();
void minHeapify(int);
int left(int);
int right(int);

void insertKey(int);

int main()
{
    cout << "Enter capacity of minHeap: ";
    cin >> CAPACITY;
    harr = new int[CAPACITY];

    int ch;
    cout << "Enter 1 to insert key" << endl
         << "Enter 2 for Minimum value" << endl
         << "Enter 3 to Extract Min" << endl
         << "Enter 4 to delete key" << endl
         << "Enter 5 for linear search" << endl
         << "Enter 6 for Print minHeap Array" << endl
         << "Enter 0 to Exit" << endl;

    do
    {
        cout << "Enter Function no.: ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            break;
        case 1:
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertKey(data);
            break;
        case 3:
            if (extractMin() == INT_MAX)
            {
                cout << "Heap is empty" << endl;
            }
            else
            {
                cout << "Minimum value was: " << extractMin() << endl;
            }
            break;

        case 6:
            print();
        }
    } while (ch != 0);

    return 0;
}

void insertKey(int k)
{
    if (heap_size == CAPACITY)
    {
        cout << "Overflow: Heap Full" << endl;
    }
    else
    {
        harr[heap_size++] = k;
        int i = heap_size - 1;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
}

int parent(int i)
{
    return (i - 1) / 2;
}

void print()
{
    for (int i = 0; i < heap_size; i++)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

int extractMin()
{
    if (heap_size <= 0)
    {
        return INT_MAX;
    }
    else if (heap_size == 1)
    {
        return harr[--heap_size];
    }

    int root = harr[0];
    harr[0] = harr[--heap_size];
    minHeapify(0);
    return root;
}

void minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
    {
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        minHeapify(smallest);

    }
    
}

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int left(int i)
{
    return (2 * i + 1);
}
int right(int i)
{
    return (2 * i + 2);
}