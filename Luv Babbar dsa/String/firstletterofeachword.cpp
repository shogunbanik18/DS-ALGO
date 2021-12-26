class Solution{
public:	
	
	string firstAlphabet(string S)
	{
	    string res="";
	    res=res+S[0];
	    for(int i=0;i<S.size();i++)
	    {
	        if(S[i]==' ')
	        {
	            res=res+S[i+1];
	        }
	    }
	    return res;
	    // Your code goes here
	}
};
