// class Solution {
// public:
//     int countCollisions(string directions) 
//     {
//         int i=1;
//         while(i<n)
//         {
//             if(directions[i] != directions[i-1] and (directions[i]!='S' or directions[i-1]!='S'))
//             {
//                    count+=2;
//                    i+=2;
//             }
            
//             else
//             {
                
//                 i++;   
//             }
//         }
        
//     }
// };

// using stack ds 
class Solution {
public:
    int countCollisions(string directions) 
    {
        stack<char>st;
        int n = directions.size();
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(directions[i]);
            }
            
            else if(st.top()=='S'  and directions[i]=='L')
            {
                count+=1;
            }
            
            else if(st.top()=='R' and directions[i]=='L')
            {
                st.pop();
                directions[i]='S';
                i--;
                count+=2;
            }
            
             else if(st.top()=='R' and directions[i]=='S')
            {
                st.pop();
                directions[i]='S';
                i--;
                count+=1;
            }
            
            else
            {
                st.push(directions[i]);
            }
        }
        return count;
    }
};
