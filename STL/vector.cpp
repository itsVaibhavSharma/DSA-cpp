#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v1;
    vector<int> v2(5); // empty

    v1.push_back(2);  // 2
    v1.push_back(5);  // 2 5
    v1.push_back(23); // 2 5 23
    v1.push_back(10); // 2 5 23 10

    cout << v1.size() << endl;
    cout << v1[0] << " " << v1[1] << " " << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<int>::iterator iter;

    for (iter = v1.begin(); iter != v1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> v3(6, 4);
    for (auto element : v3)
    {
        cout << element << " ";
    }

    cout << endl
         << endl;
    for (auto element : v1)
    {
        cout << element << " ";
    }
    cout << endl;

    for (auto element : v3)
    {
        cout << element << " ";
    }
    cout << endl;

    swap(v1, v3);

    for (auto element : v1)
    {
        cout << element << " ";
    }
    cout << endl;

    for (auto element : v3)
    {
        cout << element << " ";
    }
    cout << endl;

    // sort(v3.begin(), v3.end());

    cout << v3.at(2) << " " << v3.at(3) << " " << endl;

    // assign
    v3.assign(3, 4);
    for (auto element : v3)
    {
        cout << element << " ";
    }
    cout << endl;

    // end
    // cout << v3.end() << " ";
    cout << v3.back() << " ";
    cout << endl;

    // pop
    v3.pop_back();

    for (auto element : v3)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<char> v4(6);
    v4.push_back('m');
    v4.push_back('i');
    v4.push_back('n');
    v4.push_back('i');

    for (auto element : v4)
    {
        cout << "el->" << element << endl;
    }
    cout << endl;

    cout << v4.size() << " " << v4.capacity() << " " << v4.max_size() << endl;
    cout << boolalpha << "Empty: " << v4.empty() << endl;
    v4.clear();

    cout << boolalpha << "Empty: " << v4.empty() << endl;

    v4.push_back('m');
    v4.push_back('i');
    v4.push_back('n');
    v4.push_back('i');

    for (auto element : v4)
    {
        cout << "el->" << element << endl;
    }
    cout << endl;

    // erase
    v4.erase(v4.begin() + 1, v4.end() - 1);
    for (auto element : v4)
    {
        cout << "el->" << element << endl;
    }
    cout << endl;

    v4  = {'m','i','n','i'};
      for (auto element : v4)
    {
        cout << "el->" << element << endl;
    }
    cout << endl;

    // front -> first element value
    // back -> last element value
    // begin -> points to first element
    // end -> points next to last element
    // clear -> empty the vector
    // assign -> delete and replace with new values
    // size -> gives the size of vector
    // empty -> bool return 1 if empty
    // push_back -> inserts element at end
    // pop_back -> removes element at end
    // at(i) -> give element at i
    

    return 0;
}