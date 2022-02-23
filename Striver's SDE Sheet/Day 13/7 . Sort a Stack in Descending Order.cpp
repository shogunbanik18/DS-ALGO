
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
// using recursion
void insert(int x,stack<int>&s)
{
    if(s.empty() or s.top()<x)
    {
        s.push(x);
    }
    else
    {
        int a =s.top();
        s.pop();
        insert(x,s);
        s.push(a);
    }
}
void reverse(stack<int>&s)
{
    if(s.size()>0)
    {
        int x=s.top();
        s.pop();
        reverse(s);
        insert(x,s);
    }
}

void SortedStack :: sort()
{
   reverse(s);
}
