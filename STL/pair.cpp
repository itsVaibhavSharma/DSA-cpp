#include <iostream>
#include <vector>
using namespace std;

int main()
{

    pair<int, char> p;
    p.first = 23;
    p.second = 'm';

    vector<pair<int, char>> vec;
    vec.push_back(p);
    vec.push_back(make_pair(3, 'v'));

    for (auto element : vec)
    {
        cout << element.first << " " << element.second << endl;
    }

    return 0;
}