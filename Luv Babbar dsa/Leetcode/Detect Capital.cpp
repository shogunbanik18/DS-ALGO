class Solution {
public:
    // deal with cases 
    // using stl
    // tc:O(n)
    // sc:o(1)
    bool detectCapitalUse(string word)
    {
        int n=word.size();
        // checking for 1st letter 
        if(isupper(word[0]))
        {
              // checking for 2nd letter 
            if(isupper(word[1]))
            {
                for(int i=2;i<n;i++)
                {
                    if(islower(word[i]))
                    {
                        return false;
                    }
                }
            }
            else
            {
                for(int i=1;i<n;i++)
                {
                    if(isupper(word[i]))
                    {
                        return false;
                    }
                }
            }
        }
        // checking for 1st letter 
        else
        {
            for(int i=0;i<n;i++)
            {
                if(isupper(word[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
