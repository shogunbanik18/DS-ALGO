class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int n=nums.size();
        int freqEven[100001]={0};
        int freqOdd[100001]={0};
        int maxi= nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                freqEven[nums[i]]++;
            }
            else
            {
                freqOdd[nums[i]]++;
            }
            maxi=max(maxi,nums[i]);
        }
        
        int firstMaxEven=0, freqfirstMaxEven=0;
        int SecondMaxEven=0, freqSecondMaxEven=0;
        
        int firstMaxOdd=0, freqfirstMaxOdd=0;
        int SecondMaxOdd=0, freqSecondMaxOdd=0;
        
        for(int i=1;i<=maxi;i++)
        {
            if(freqEven[i]>freqfirstMaxEven)
            {
                SecondMaxEven= firstMaxEven;
                freqSecondMaxEven=freqfirstMaxEven;
                
                freqfirstMaxEven= freqEven[i];
                firstMaxEven=i;
            }
            else if(freqEven[i]>=freqSecondMaxEven)
            {
                
                freqSecondMaxEven=freqEven[i];
                SecondMaxEven= i;
            }
            
            if(freqOdd[i]>=freqfirstMaxOdd)
            {
                SecondMaxOdd= firstMaxOdd;
                freqSecondMaxOdd=freqfirstMaxOdd;
                freqfirstMaxOdd= freqOdd[i];
                firstMaxOdd=i;
            }
            else if(freqOdd[i]>=freqSecondMaxOdd)
            {
                freqSecondMaxOdd=freqOdd[i];
                SecondMaxOdd= i;
            }
        }
        
        if(firstMaxEven!=firstMaxOdd)
        {
            return n-freqfirstMaxEven-freqfirstMaxOdd;
        }
        
        return min(n-freqfirstMaxEven-freqSecondMaxOdd,n-freqSecondMaxEven-freqfirstMaxOdd);
    }
};
