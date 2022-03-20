// Using 2 maps + checking for traversal 
// tc : o(nlogn) + o(nlogn) + o(n) + o(n)  
// sc :o(n) + o(n)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        map<int,int>mp1;
        map<int,int>mp2;
        
        // insertion in the map  
        for(auto x: tops)
        {
            mp1[x]++;
        }
        
        for(auto x: bottoms)
        {
            mp2[x]++;
        }
        
        // finding the maximum Frequency element in tops  
        int freq1   = 0;
        int maxele1 = 0;
        
        for(auto x :mp1)
        {
            if(x.second>freq1)
            {
                freq1 = x.second;
                maxele1 = x.first;
            }
        }
        
        // finding the maximum Frequency element in Bottoms 
        int freq2   = 0;
        int maxele2 = 0;
        
        for(auto x :mp2)
        {
            if(x.second>freq2)
            {
                freq2 = x.second;
                maxele2 = x.first;
            }
        }
        
        // cout<< maxele1<<" " <<freq1<<endl;
        // cout<< maxele2 << " "<<freq2<<endl;
        
        int count=0,n = tops.size();
        bool ans = true;
        
        // checking for traversal (which array to be modified top or bottom )
        if(freq1>freq2)
        {
            int maxele = maxele1;
            for(int i=0;i<n;i++)
            {
                if(bottoms[i]==maxele and tops[i]!=maxele)
                {
                    swap(bottoms[i],tops[i]);
                    count++;
                }
            }
            
            
            // Debug 
//             for(int i=0;i<n;i++)
//             {
//                 cout<<tops[i]<<" ";
//             }
//             cout<<endl;
            
//             for(int i=0;i<n;i++)
//             {
//                 cout<<bottoms[i]<<" ";
//             }
//             cout<<endl;
            
            // check for same elements 
            for(int i=1;i<n;i++)
            {
                if(tops[i]!=tops[i-1])
                {
                    ans =false;
                    break;
                }
            }
        }
        
        else
        {
            int maxele = maxele2;
            for(int i=0;i<n;i++)
            {
                if(tops[i]==maxele and bottoms[i]!=maxele)
                {
                    swap(bottoms[i],tops[i]);
                    count++;
                }
            }
            
            
            // Debug 
//             for(int i=0;i<n;i++)
//             {
//                 cout<<tops[i]<<" ";
//             }
//             cout<<endl;
            
//             for(int i=0;i<n;i++)
//             {
//                 cout<<bottoms[i]<<" ";
//             }
//             cout<<endl;
            
            
            // check for same elements 
            for(int i=1;i<n;i++)
            {
                if(bottoms[i]!=bottoms[i-1])
                {
                    ans =false;
                    break;
                }
            }
        }
        
        if(ans==false)
        {
            return -1;
        }
        else
        {
            return count;
        }
    }
};
