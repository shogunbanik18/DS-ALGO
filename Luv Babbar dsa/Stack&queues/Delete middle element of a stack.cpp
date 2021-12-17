class Solution
{
    public:
    //Function to delete middle element of a stack.
    // tc: o(n)
    // sc: o(n)
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        stack<int>temp;
        int mid=(sizeOfStack)/2;
        while(mid--)
        {
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }
};
