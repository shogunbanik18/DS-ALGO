class Solution {
public:
//   tc: o(n^2)
//   sc:o(n^2)
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        double ans=0;
        vector<vector<double>>arr(101,vector<double>(101,0));
        arr[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(arr[i][j]>=1)
                {
                    arr[i+1][j] += (arr[i][j]-1)/2;
                    arr[i+1][j+1]+=(arr[i][j]-1)/2;
                    arr[i][j]=1;
                }
            }
        }
        return arr[query_row][query_glass];
    }
};


