#include <bits/stdc++.h>
using namespace std;

class a
{
public:
    void speak()
    {
        cout << "A speaking" << endl;
    }
};

class b : public a
{
public:
    void talk()
    {
        cout << "b speaking" << endl;
    }
};

// hierarchical inheritance
class c : public a
{
public:
    void ta()
    {
        cout << "C speaking " << endl;
    }
};

int main()
{
    a obj;
    obj.speak();

    b obj1;
    obj.speak();
    obj1.talk();

    c obj2;
    obj2.speak();
    obj2.ta();
    
    return 0;
}