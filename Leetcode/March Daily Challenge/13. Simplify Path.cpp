// using stack <string>
// tc: o(n)
// sc: o(n) (stack space)
class Solution {
public:
    string simplifyPath(string s)
    {
        stack<string>st;
        
        int n=s.size();
     
        for(int i=0;i<n;i++)
        {
            if(s[i]=='/')
            {
                continue;
            }
            
            string temp="";
            while(i<s.size() and s[i]!='/')
            {
                temp+=s[i];
                i++;
            }
            
            if(temp == ".")
            {
                continue;
            }
            
            else if(temp=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
                
            }
            else
            {
                st.push(temp);
            }
        }
        
        string res="";
        while(!st.empty())
        {
            res = "/" + st.top() +res;
            st.pop();
        }
        
         if(res.size()==0)
         {
             return "/";
         }
        
        return res;
    }
};


// cannot pop when s[i] == '.' or s[i]==".." 
// wrong ans use stack of strings 
// class Solution {
// public:
//     string simplifyPath(string s)
//     {
//         stack<char>st;
        
//         int n=s.size();
     
//         for(int i=0;i<n;i++)
//         {
//             // if(s[i]=='/')
//             // {
//             //     continue;
//             // }
            
//             if(i==n-1 and s[i]=='/')
//             {
//                 continue;
//             }
            
//             else if(s[i]=='/' and !st.empty() )
//             {
//                 if( st.top()=='/')
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     st.push(s[i]);
//                 }
//             }
            
//             else if(s[i] == '.')
//             {
//                 continue;
//             }
            
//             else
//             {
//                 st.push(s[i]);
//             }
//         }
        
//         string res="";
//         while(!st.empty())
//         {
//             res += st.top();
//             st.pop();
//         }
        
//         reverse(res.begin(),res.end());
//          if(res.size()==0)
//          {
//              return "/";
//          }
        
//         return res;
//     }
// };
