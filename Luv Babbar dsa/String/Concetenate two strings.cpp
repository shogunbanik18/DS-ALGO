class Solution{
    public:    
    // tc :O(N)
//   dp based approach 
    long long countPairs(int N, int X, vector<int> numbers)
    {
        long long ans=0;
        unordered_map<string,int>mp;
        string tmp=to_string(X);
        for(auto i:numbers)
        {
            mp[to_string(i)]++;
        }
        
        for(int i=0;i+1<tmp.size();i++)
        {
            string p=tmp.substr(0,i+1);
            string q=tmp.substr(i+1);
            long long f1=mp[p];
            long long f2=mp[q];
            if(p==q)
            {
                ans+=f1*(f1-1);
            }
            else
            {
                ans+=f1*f2;
            }
        }
        return ans;
    }
};



// My Submission 
// wrong answer 
// long long countPairs(int N, int X, vector<int> numbers)
    // {
    //     long long count;
    //     // sort(numbers.begin(),numbers.end());
    //     vector<string>v(N,"");
    //     vector<pair<long long ,long long>>p;
        
    //     // converting each number of array to string 
    //     for(int i=0;i<N;i++)
    //     {
    //         v[i]=to_string(numbers[i]);
    //     }
        
    //     string x= to_string(X);
        
    //     for(int i=0;i<N-1;i++)
    //     {
    //         for(int j=i+1;j<N;j++)
    //         {
    //             if(v[i]!=v[j])
    //             {
    //                 if((v[i]+v[j]==x) or (v[j]+v[i]==x))
    //                 {
    //                     p.push_back({i,j});
    //                 }
    //             }
    //             else
    //             {
    //                 if(v[i]+v[j]==x)
    //                 {
    //                     p.push_back({i,j});
    //                     p.push_back({j,i});
    //                 }
    //             }
    //         }
    //     }
    //     // for(auto x:p)
    //     // {
    //     //     cout<<x.first<<" "<<x.second<<endl;
    //     // }
        
    //     count=p.size();
    //     return count;
    // }
