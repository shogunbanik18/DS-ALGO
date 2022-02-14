
// Solution 1: Brute Force Solution

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
