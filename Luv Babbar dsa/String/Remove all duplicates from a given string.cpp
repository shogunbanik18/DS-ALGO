class Solution{
public:
// using unordered map 
	string removeDuplicates(string str) 
	{
	    unordered_map<char,int>mp;
	    string res="";
	    for(int i=0;i<str.size();i++)
	    {
	        if(mp[str[i]]==0)
	        {
	            res+=str[i];
	            mp[str[i]]++;
	        }
	    }
	    return res;
	    // code here
	}
};
