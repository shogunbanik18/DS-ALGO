
// Solution 1: Brute Force Solution
// brute force 
// generating all the permutaions of a given string and sorting then finding the kth element

class Solution 
{
private:
    
    void f(string s,int ind, vector<string>& ds)
    {
        if(ind==s.size())
        {
            ds.push_back(s);
            return;
        }
        
        for(int i=ind;i<s.size();i++)
        {
            swap(s[i],s[ind]);
            f(s,ind+1,ds);
            swap(s[i],s[ind]);
        }
    }
    
public:
    string getPermutation(int n, int k)
    {
        string s;
        
        for(int i=1;i<=n;i++)
        {
            s.push_back(i + '0');
        }
        
        vector<string>ds;
        
        f(s,0,ds);
        
        sort(ds.begin(),ds.end());
        
        string res;
        res = ds[k-1];
        
        return res;
        // auto it = ds.begin() + (k - 1);
        // return *it;
    }
};



// Approach:  

// The extreme naive solution is to generate all the possible permutations of the given sequence.  This is achieved using recursion and every permutation generated is stored in 
// some other data structure (here we have used a vector). Finally, we sort the data structure in which we have stored all the sequences and return the Kth sequence from it.

class Solution {
public:
    
//     optimised approach 
    // tc: O(N) * O(N) = O(N^2)
    // sc:o(n)
    string getPermutation(int n, int k) 
    {
        vector<int>numbers;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        k=k-1;
        while(true)
        {
            ans=ans+ to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0)
            {
                break;
            }
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
    }
};
