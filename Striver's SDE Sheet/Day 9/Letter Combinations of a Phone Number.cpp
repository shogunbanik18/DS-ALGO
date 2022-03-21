// recursion + hashing 
// tc: o(2^n)
// sc: o(n)stack space +o(n) hashing
// similar to subset sum
class Solution 
{
private : 
        void solve(string digits, int index,string output,vector<string> mapping,vector<string>& ans)
        {
            // base case 
            if(index == digits.size())
            {
                ans.push_back(output);
                return;
            }

            int num = digits[index]-'0';
            string value = mapping[num];

            for(int i=0;i<value.size();i++)
            {
                output.push_back(value[i]);
                solve(digits , index+1 ,output , mapping, ans);
                output.pop_back();
            }
        }
    
    public:
        vector<string> letterCombinations(string digits) 
        {

            vector<string>ans;
            string output = "";

            if(digits.size()==0)
            {
                return ans;
            }

            // use frequncy array of strings
            vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            int index=0;

            solve(digits,index,output,mapping,ans);    
            return ans;
        }
};

//         map<int,string> mp;
        
//         mp[2] = "abc";
//         mp[3] = "def";
//         mp[4] = "ghi";
//         mp[5] = "jkl";
//         mp[6] = "mno";
//         mp[7] = "pqrs";
//         mp[8] = "tuv";
//         mp[9] = "wxyz";
        
//         Debug
//         for(auto x : mp)
//         {
//             cout<<x.first<<" "<<x.second<<endl;
//         }
