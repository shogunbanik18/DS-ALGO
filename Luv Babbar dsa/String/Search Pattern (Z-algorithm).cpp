class Solution
{
    public:
    // naive approach 
    // tc :o(s*t)
        vector <int> search(string pat, string txt)
        {
            vector<int>v;
            int n=txt.size();
            for(int i=0;i<n-pat.size()+1;i++)
            {
                if(txt.substr(i,pat.size())==pat)
                {
                        v.push_back(i+1);
                }
            }
            if(v.empty())
            {
                v.push_back(-1);
            }
            return v;
            //code hee.
        }
};
