int getTotalX(vector<int> a, vector<int> b)
{
    int count=0;
    int n=a.size();
    int m=b.size();
    int x1 =a[n-1];
    int x2 =b[0];

    for(int i=x1;i<=x2;i++)
    {
        bool a_pass=true,b_pass=true;
        
        for(int k=0;k<n;k++)
        {
            if(i%a[k]!=0)
            {
                a_pass=false;
                break;
            }
        }
        
        for(int j=0;j<m;j++)
        {
            if(b[j]%i!=0)
            {
                b_pass=false;
                break;
            }
        }
        
        if(a_pass==true and b_pass==true)
        {
            count++;
        } 
    }
    return count;
}
