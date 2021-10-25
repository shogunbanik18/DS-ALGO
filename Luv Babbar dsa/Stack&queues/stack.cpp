#include <iostream>
#include<stack>
using namespace std;

// stack : LIFO(Last in first out)

int main()
{
    stack<string>s;
    s.push("Shogun");
    s.push("Banik");
    s.push("MS DHONI Fan");

    cout<<"Top Element : "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element : "<<s.top()<<endl;

  cout<<"Size of stack : "<<s.size()<<endl;
  cout<<"Empty or not : "<<s.empty()<<endl;
}


// output //
 clang++-7 -pthread -std=c++17 -o main main.cpp
 ./main
Top Element : MS DHONI Fan
Top Element : Banik
Size of stack : 2
Empty or not : 0
