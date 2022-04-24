// // Encapsulation : Information Hiding
// // Capsule mein data members  + function ko daal do
// #include<bits/stdc++.h>
// using namespace std;

// class Student
// {
//     private :
//         string name;
//         int rollno;

//     public:
//         int getroll()
//         {
//             // this pointer stores the address
//             return this->rollno;
//         }
// };

// int main()
// {
//     Student s1;
//     // cout<<s1.getroll()<<endl;
//     cout<<"Everything ok"<<endl;

// }

// Inheritance
#include <bits/stdc++.h>
using namespace std;

// Base class
class Human
{
// public:
private: 
// protected :
    int height;

public:
    int weight;
    int age;

public:
    Human()
    {
        height = 70;
        weight = 100;
        age = 18;
    }

    int getage()
    {
        return this->age;
    }

    void setweight(int w)
    {
        this->weight = w;
    }
};

class Male : public Human
// class Male : private Human
// class Male : protected Human
{
public:
    string color;

    Male()
    {
        color = "Black";
    }

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }

    int getheight()
    {
        return this->height;
    }

};

int main()
{
    Male m1;
    cout<<m1.getheight()<<endl;

    // Male ob1;
    // cout << ob1.height << endl;
    // cout << ob1.weight << endl;
    // cout << ob1.age << endl;

    // ob1.setweight(86);
    // cout << ob1.weight << endl;

    // cout << ob1.color << endl;
    // ob1.sleep();

    return 0;
}