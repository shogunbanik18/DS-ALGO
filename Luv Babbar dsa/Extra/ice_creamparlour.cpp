vector<int> icecreamParlor(int m, vector<int> arr)
{
    vector<int> result;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==m)
            {
                result.push_back(i+1);
                result.push_back(j+1);
            }
        }
    }
    return result;
}