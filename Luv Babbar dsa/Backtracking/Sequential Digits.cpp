class Solution {
public:
    // using recursion 
    // tc:O(9^N) +o(VLOGV)
    // declaring global variable
    vector<int>v;
    void count(int l,int h,int i,int n)
    {
        if(n>=l and n<=h)
        {
            v.push_back(n);
        }
        if(n>h or i>9)
        {
            return;
        }
        count(l,h,i+1,n*10+i);
    }
    
    vector<int> sequentialDigits(int low, int high)
    {
        for(int i=1;i<=9;i++)
        {
            count(low,high,i,0);
        }
        sort(v.begin(),v.end());
        return v;
    }
};
