// Resolving  using scope Resolution Operator 
#include <bits/stdc++.h>
using namespace std;

class a
{
public:
    void func()
    {
        cout << "A bolchi Bhai" << endl;
    }
};

class b
{
public:
    void func()
    {
        cout << "B bolchi Bhai" << endl;
    }
};

class c :public a,public b
{
public:
    void fun3()
    {
        cout << "C bolchi Bhai !! Kire" << endl;
    }
};

int main()
{
    c obj;
    obj.fun3();
    obj.a::func();
    obj.b::func();

    return 0;
}