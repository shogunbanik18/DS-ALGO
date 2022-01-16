class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N)
    {
        vector<int>v;
        for(int i=0;i<N-2;i++)
        {
            if((A[i]+A[i+1]>A[i+2]) and (A[i+1]+A[i+2]>A[i]) and (A[i]+A[i+2]>A[i+1]))
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
        // code here
    }
}; 
