// using stack 
// tc: o(n)
// sc: o(n) auxiliary stack space 
// class Solution {
// public:    
//     string reverseWords(string s) 
//     {
//         stack<string> st;
        
//         string temp="";
        
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i] != ' ')
//             {
//                 temp += s[i]; 
//             }
            
//             else if(temp != "")
//             {
//                 st.push(temp);
//                 temp="";
//             }
//         }
        
//         if(temp.size()>0)
//         {
//             st.push(temp);
//         }
        
//         string res="";
//         while(!st.empty())
//         {
//             res +=st.top();
//             st.pop();
//             if(!st.empty())
//             {
//                 res += ' ';
//             }
//         }
//         return res;
//     }
// };

// tc: o(n)

// using vector 
class Solution {
public:    
    string reverseWords(string s) 
    {
        vector<string> v;
        
        string temp="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                temp += s[i]; 
            }
            
            else
            {
                if(temp.size()>0)
                {
                    v.push_back(temp);
                }
                temp = "";
            }
        }
        
        if(temp.size()>0)
        {
            v.push_back(temp);
        }
        
        temp = "";
        
        for(int i=v.size()-1;i>0;i--)
        {
            temp += v[i];
            temp+= ' ';
        }
        temp += v[0];
        
        return temp;
    }
};
