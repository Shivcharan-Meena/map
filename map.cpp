#include <map>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(int a,int b)const{
        return a>b;
    }
};    //External sorting


int main()
{
    map<int, int> m;
    pair<int, int> p(1, 2);
    m.insert(p);
    m.insert(make_pair(2, 3));
    m.insert({3, 4});
    m[4] = 5;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    m.erase(2);
    cout << "After erasing 2" << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // finding an element
    cout << "Finding 3" << endl;
    for (auto it = m.find(3); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << m.find(3)->first << endl;
    // begin() and end()
    cout << "moving iterator by begin()and end()" << endl;
    cout << m.begin()->first << endl;
    cout << (--m.end())->first << endl;

    // number of elements
    cout << "Number of elements in map" << endl;
    cout << distance(m.begin(), m.end()) << endl;
    cout << "Size of map" << endl;
    cout << m.size() << endl;

    // checking if map is empty
    if (m.empty())
    {
        cout << "Map is empty" << endl;
    }
    else
    {
        cout << "Map is not empty" << endl;
    }

    // Swap elements of queues
    // swap(map1, map2);

    // using at
    cout << "Using at()" << endl;
    cout << m.at(3) << endl;

    cout << "using find" << endl;
    // m.find(key) returns an iterator to the element with the key key
    // m.find(key) returns m.end() if key is not found
    // m.count(key) returns the number of elements with the key key
    cout << (m.find(3))->first << endl;

    // The count() in C++ is a built-in function that is used to count the occurrence of the given key in the map container
    // The count() function returns the number of elements with the key in the map
    // If the key is not found, it returns 0
    // if found returns 1
    cout << m.count(3) << endl;

    // erase function
    cout << "Erasing 3" << endl;
    // m.erase(3);
    // erasing full map
    // m.erase(m.begin(),m.end());
    // m.erase(m.begin());
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // clear function in map
    cout << "Clearing map" << endl;
   // m.clear();

   //Reverse Iterator
   cout<<"Reverse Iterator"<<endl;
   for(auto it=m.rbegin();it!=m.rend();it++){
    cout<<it->first<<" "<<it->second<<endl;

   }

   cout<<"rbegin() annd crbegin()"<<endl;
   cout<<(m.rbegin())->first<<endl;
   cout<<(m.crbegin())->first<<endl;
    cout<<"rend() and crend()"<<endl;
    cout<<(m.rend())->first<<endl;
    cout<<(m.crend())->first<<endl;


    //max_size
    cout<<"Max size of map"<<endl;
    cout<<m.max_size()<<endl;


    //lower_bound and upper_bound
    cout<<"Lower bound and upper bound"<<endl;
    cout<<m.lower_bound(3)->first<<endl;
    cout<<m.upper_bound(3)->first<<endl;

    //emplace_hint()
    // Returns an iterator to the newly inserted element. If the insertion failed because the element already exists, returns an iterator to the already existing element with the equivalent key.
    cout<<"Emplace hint"<<endl;
    cout<<m.emplace_hint(m.begin(),5,6)->first<<endl;//slower
    cout<<m.emplace_hint(m.begin(),3,6)->first<<endl;//faster

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    //The map::equal_range() is a built-in function in C++ STL which returns a pair of iterators. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k. Since the map container only contains unique key, hence the first iterator in the pair returned thus points to the element and the second iterator in the pair points to the next key which comes after key K. If there are no matches with key K and the key K is greater than largest key , the range returned is of length 1 with both iterators pointing to the an element which has a key denoting the size of map and elements as 0. Otherwise the lower bound and the upper bound points to the element just greater than the key K.
    cout << "Equal range of 3" << endl;
    auto range = m.equal_range(3);
    cout << "Lower bound: " << range.first->first<<":"<<range.first->second << endl;
    cout << "Upper bound: " << range.second->first<<":"<<range.first->second << endl;


    //External sorting
    cout<<"External sorting"<<endl;
    map<int ,int ,cmp>mm={{10,20},{30,40},{50,10},{20,0}};

    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    //getting element
    cout<<"Methods to Get Map Element at Offset in C++ STL"<<endl;


    cout<<"1.Using an iterator to begin() and offset"<<endl;
    int offset = 3;
    auto itr = mm.begin();
    int k = 1;
    // Iterate while k is <offset
    while (k < offset) {
        k++;
        itr++;
    }
    cout<<"print the key value pair at offset"<<endl;
    cout << itr->first << " " << itr->second << endl;
    cout<<endl;
    cout<<"2. Using advance() function"<<endl;
    auto it=mm.begin();
    advance(it,offset);
    cout<<"print the key value pair at offset"<<endl;
    cout << itr->first << " " << itr->second << endl;


    cout<<endl;
    cout<<"3.Using next()"<<endl;
    auto nit=next(it,offset);
    cout<<nit->first<<" "<<nit->second<<endl;

    cout<<"Search by value in a Map in C++"<<endl;
    int l=0;
    cout<<"keys corresponding to value "<<l<<endl;
    for(auto it=mm.begin();it!=mm.end();it++){
        if(it->second==l){
            cout<<it->first<<endl;
        }
    }
    return 0;
}