#include<bits/stdc++.h>
using namespace std;

class animal
{
    public : 
        int age;
        int weight;

        animal()
        {
            age = 16;
            weight = 150;
        }

        void speak()
        {
            cout<<"Animal Speaking "<<endl;
        }

};

class dog : public animal
{

};


int main()
{
    dog d;
    d.speak();

    cout<<d.age<<" "<<d.weight<<endl;

    return 0;
}