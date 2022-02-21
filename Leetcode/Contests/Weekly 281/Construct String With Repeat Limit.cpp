class Solution {
public:
    // using priority queue 
    // implementation 
//     tc:o(nlogn)
    string repeatLimitedString(string s, int repeatLimit)
    {
        int cnt[26]={0};
        for(auto x:s)
        {
            cnt[x-'a']++;
        }
        
        priority_queue<pair<int,int>>pq;
    
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>0)
            {    
                pq.push({i,cnt[i]});
            }
        }
        
        string ans="";
        while(!pq.empty())
        {
            int chr1= pq.top().first;
            int freq1=pq.top().second;
            pq.pop();
            
            if(ans.size()==0 || ans.back()!= (char)(chr1+'a'))
            {
                int times=min(freq1,repeatLimit);
                
                for(int j=0;j<times;j++)
                {
                    ans+=(char)(chr1+'a');
                }
                freq1-=times;
                if(freq1)
                {
                    pq.push({chr1,freq1});
                }
            }
            
            else
            {
                if(pq.size()==0)
                {
                    break;
                }
                int chr2= pq.top().first;
                int freq2=pq.top().second;
                pq.pop();
                
                ans+=(char)(chr2+'a');
                freq2--;
                if(freq2)
                {
                    pq.push({chr2,freq2});
                }
                pq.push({chr1,freq1});
            }
        }
        return ans;
    }
};
