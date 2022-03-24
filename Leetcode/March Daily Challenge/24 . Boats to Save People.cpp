// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) 
//     {
//         int n = people.size();
        
//         sort(people.begin(),people.end());
        
//         int count=1,person=1,sum=0;
        
//         for(int i=0;i<n;i++)
//         {
//             if(sum + people[i] > limit or person>2)
//             {
//                 count += 1;
//                 sum=0;
//                 sum += people[i];
//                 person = 0;
//                 person += 1;
//             }
            
//             else
//             {
//                 sum += people[i];
//                 person++;
//             }
//         }
        
//         return count;
//     }
// };

// using 2 pointer approach 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int n = people.size();
        
        sort(people.begin(),people.end());
        
        int count=0,sum;
        
        int i=0,j=n-1;
        while(i<=j)
        {
            sum = people[i] + people[j];
            if(sum <=limit)
            {
                i++;
                j--;
                count++;
            }
            
            else
            {
                j--;
                count++;
            }
        }
        
        return count;
    }
};
