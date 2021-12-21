/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    int n=s.size();
    multiset<int>a;
    while(n!=0)
    {
        a.insert(s.top());
        s.pop();
        n--;
    }
    
    for(auto i:a)
    {
        s.push(i);
    }
   //Your code here
}


// concept of multi set 
// The set {a, b} contains only elements a and b, each having multiplicity 1 when {a, b} is seen as a multiset.
// In the multiset {a, a, b}, the element a has multiplicity 2, and b has multiplicity 1.
// In the multiset {a, a, a, b, b, b}, a and b both have multiplicity 3.
