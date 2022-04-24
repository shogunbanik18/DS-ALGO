#include<bits/stdc++.h>
using namespace std;

class animal
{
    public:
        void speak()
        {
            cout<<"Speaking"<<endl;
        }
};

class dog : public animal
{
    public:

        void speak()
        {
            cout<<"Barking"<<endl;
        }

};

int main()
{
    dog obj;
    obj.speak();

    return 0;
}