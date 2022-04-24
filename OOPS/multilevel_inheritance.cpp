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

class German_shepherd : public dog
{

};


int main()
{
    German_shepherd g;
    g.speak();

    cout<<g.age<<" "<<g.weight<<endl;

    return 0;
}