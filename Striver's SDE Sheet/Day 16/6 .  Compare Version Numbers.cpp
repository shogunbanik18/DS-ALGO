// Wrong submission
// class Solution
// {
// public:
//     int compareVersion(string version1, string version2) 
//     {
//         string s1 = "";
//         string s2 = "";
        
//         int n = version1.size();
//         int m = version2.size();
        
//         for(auto x : version1)
//         {
//             if(x == '0' or x == '.')
//             {
//                 continue;
//             }
//             else
//             {
//                 s1 += x;
//             }
//         }
        
//         for(auto y : version2)
//         {
//             if(y == '0' or y == '.')
//             {
//                 continue;
//             }
//             else
//             {
//                 s2 += y;
//             }
//         }
        
//         // cout<<s1<<" " <<s2<<endl;
        
//         int x = stoll(s1);
//         int y = stoll(s2);
        
//         // cout<<x<<" "<<y<<endl;
        
//         if(x>y)
//         {
//             return 1;
//         }
//         else if(x<y)
//         {
//             return -1;
//         }
//         else
//         {
//              return 0;
//         } 
//     }
// };


// tc : o(x or y ) which is greater
// sc : o(1)
class Solution
{
public:
    int compareVersion(string version1, string version2) 
    {
        string s1 = "";
        string s2 = "";
        
        int n = version1.size();
        int m = version2.size();
        
        int i=0,j=0;
        while(i< n or j<m)
        {
            int x = 0;
            int y = 0;
            
            // traversing the first string 
            while(i<n and version1[i]!='.')
            {
                x = x *10 + (version1[i]-'0');
                i++;
            }
            
            // traversing the second string 
            while(j<m and version2[j]!='.')
            {
                y = y *10 + (version2[j]-'0');
                j++;
            }
            
            if(x>y)
            {
                return 1;
            }
            else if(x<y)
            {
                return -1;
            }
           
            i++;
            j++;
        } 
        return 0;
    }
};
