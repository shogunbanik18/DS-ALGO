class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) 
    {
        for(int i=N-1;i>=0;i--)
        {
            if(arr[i]==9)
            {
                arr[i]=0;
            }
            else
            {
                arr[i]++;
                return arr;
            }
        }
        arr[0]=1;
        arr.push_back(0);
        return arr;
        // code here
    }
};
