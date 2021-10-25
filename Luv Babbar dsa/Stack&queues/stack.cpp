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
