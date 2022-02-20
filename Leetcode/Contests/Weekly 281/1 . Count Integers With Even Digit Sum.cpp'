class Solution {
public:
    bool checksum(int n)
    {
        int ans=0;
        while(n)
        {
            int temp=n%10;
            ans+=temp;
            n=n/10;
        }
        
        if(ans%2==0)
        {
            return true;
        }
        return false;
    }
    
    int countEven(int num) 
    {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            if(checksum(i))
            {
                count++;
            }
        }
        return count;
    }
};
