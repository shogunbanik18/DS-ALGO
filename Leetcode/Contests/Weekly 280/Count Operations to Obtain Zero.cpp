class Solution {
public:
    int countOperations(int num1, int num2)
    {
        int count=0;
        while(true)
        {
            if(num1==0 or num2==0)
            {
                break;
            }
            if(num1>=num2)
            {
                num1=num1-num2;
                count++;
            }
            else
            {
                num2=num2-num1;
                count++;
            }
        }
        return count;
    }
};
