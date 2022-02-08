class Solution {
public:
    // using iteration
    // tc:o(logn)
    int addDigits(int num)
    {
        int sum;
        while(num>9)
        {
            sum=0;
            while(num!=0)
            {
                int temp=num%10;
                sum+=temp;
                num=num/10;
            }
            num=sum;            
        }
        return num;
    }
    
    // using divisibility by 9 concept 
    // tc:o(1)
    // sc:o(1)
    int addDigits(int num)
    {
        if(num==0)
        {
            return 0;
        }
        return num%9==0?9:num%9;
    }
    
};
