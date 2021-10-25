#include <iostream>
#include<queue>
using namespace std;

// queue : FIFO(First in first out)

int main() {
  // std::cout << "Hello World!\n";
  queue<string> q;
  q.push("Shogun");
  q.push("Banik");
  q.push("Kumar");

  cout<<"Size before pop : "<<q.size()<<endl;
  cout<<"first element : "<<q.front()<<endl;
  q.pop();
  cout<<"first element : "<<q.front()<<endl;

  cout<<"Size after pop : "<<q.size()<<endl;
}