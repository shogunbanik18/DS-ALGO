// // Compile time polymorphism 
// // poly -> many
// // morphs -> forms
// Function Overloading 

// #include<bits/stdc++.h>
// using namespace std;

// class A
// {
//     public:

//     void say()
//     {
//         cout<<"Banik_ji"<<endl;
//     }

//     void say(string name)
//     {
//         cout<<"Banik_ji"<<name<<"Boliye"<<endl;
//     }

//     int say(string name,int x)
//     {
//         // cout<<"Banik_ji"<<name<<"Boliye"<<endl;
//         return x;
//     }

// };

// int main()
// {
//     A obj;
//     obj.say();
//     cout<<obj.say("shogun",2);

//     return 0;
// }


// Compile time polymorphism 
// poly -> many
// morphs -> forms
// operator overloading 
#include<bits/stdc++.h>
using namespace std;

class B
{
    public:
    int a;
    int b;

    void operator+(B &obj)
    {
        int val1 = this->a;
        int val2= obj.a;
        cout<<"Output "<<val2-val1<<endl;
    }
    
    void operator() ()
    {
        cout<<"Ami Bracket bolchi bhai"<<endl;
        cout<<this->a<<endl;
    }
    
};

int main()
{
    B obj1,obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    return 0;
}