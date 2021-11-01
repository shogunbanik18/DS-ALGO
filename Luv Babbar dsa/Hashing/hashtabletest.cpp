// Hashtable test .cpp

#include <bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> h;
    h.insert("mango", 100);
    h.insert("apple", 120);
    h.insert("banana", 140);
    h.insert("orange", 200);
    h.insert("Kiwi", 210);
    h.insert("Papaya", 220);
    h.insert("lichi", 230);

    h.print();
    string fruit;
    cin >> fruit;

    int *price = h.search(fruit);
    if (price != NULL)
    {
        cout << "Price of Fruit is : " << *price << endl;
    }
    else
    {
        cout << "Fruit is not present " << endl;
    }
    return 0;
}