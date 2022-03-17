// TLE 
// class Solution {
// public:
//     int scoreOfParentheses(string s)
//     {
//         stack<char>st;
//         int n = s.size();
//         int count = 0;
        
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='(')
//             {
//                 st.push(s[i]);
//             }
            
            
//             else if(s[i]==')')
//             {
//                 if(!st.empty() and st.top() == '(' )
//                 {
//                     count++;
//                     st.pop();
//                 }
//             }
            
//             while(!st.empty())
//             {
//                 if(s[i]==')' and st.top() == '(')
//                 {
//                     count = 2*count;
//                     st.pop();
//                 }
//             }
//         }
//         return count;
//     }
// };

// tc: o(n)
// sc: o(n) stack space 
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        stack<char>st;
        int n = s.size();
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(count);
                count=0;
            }
            
            
            else if(s[i]==')')
            {
                count = st.top() + max(2*count,1);
                st.pop();
            }
        }
        return count;
    }
};
