#include <bits/stdc++.h>
using namespace std;

class animal
{
public:
    int age;
    int weight;

    animal()
    {
        age = 16;
        weight = 150;
    }

    void bark()
    {
        cout << "Animal Speaking " << endl;
    }
};

class Human
{
public:
    string color;

    void speak()
    {
        cout << "Human Speaking " << endl;
    }
};

// Multiple Inheritance 
class mix: public Human,public animal
{
    void talk()
    {
        cout<<"Taking "<<endl;
    }
};


int main()
{
    mix m1;
    m1.bark();
    m1.speak();
    return 0;
}