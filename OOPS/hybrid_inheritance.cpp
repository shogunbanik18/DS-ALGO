#include <bits/stdc++.h>
using namespace std;

//     a    d
//  b      c

class a
{
public:
    void speak()
    {
        cout << "A bolchi bhai" << endl;
    }
};

class b : public a
{
    public:
    void speak1()
    {
        cout << "B bolchi bhai" << endl;
    }
};

class d
{
    public:
    void speak2()
    {
        cout << "D bolchi bhai" << endl;
    }

};

class c : public a, public d
{
    public:
    void speak4()
    {
        cout << "C bolchi bhai" << endl;
    }

};

int main()
{
    c obj;
    obj.speak4();
    obj.speak2();
    obj.speak();
}