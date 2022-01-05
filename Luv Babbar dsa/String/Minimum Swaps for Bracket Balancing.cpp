class Solution{   
public:
    int minimumNumberOfSwaps(string S)
    {
        int count=0;
        int sum=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==']')
            {
                count=count+1;
            }
            else
            {
                if(count>0)
                {
                    sum=sum+count;
                }
                count=count-1;
            }
        }
        return sum;
        // code here 
    }
};
