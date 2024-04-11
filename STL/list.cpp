#include <iostream>
#include <list>
using namespace std;

int main() {

    list<int> list1;
    list <char> list2 = {'m','i','n','i'};


    list1.push_back(10);
    list1.push_back(2004);
    list1.push_front(23);

    for(auto element:list1){
        cout << element << " ";
    } cout << endl;
    list1.pop_front();
     for(auto element:list1){
        cout << element << " ";
    } cout << endl;

    list<int> :: iterator it;
    list<char> :: iterator itchar;
    for(itchar = list2.begin(); itchar != list2.end(); itchar++){
         cout << *itchar<< " ";
    } cout << endl;

    list1 = {5,6,34,2,6,7,2,2,6,7,24,34,4,33};
     for(auto element:list2){
        cout << element << " ";
    } cout << endl;

    


    return 0;
}