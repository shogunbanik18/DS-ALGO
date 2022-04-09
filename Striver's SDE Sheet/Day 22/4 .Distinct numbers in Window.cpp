GFG

// Brute Force 
// tc : o(n^2)
// sc : o(1)
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> v;
        
        for(int i=0;i<= n-k;i++)
        {
            set<int>set;
            for(int j = i;j<=(i+k-1) ;j++)
            {
                set.insert(A[j]);
            }
            v.push_back(set.size());
        }
        return v;
    }
};


// using hashing 
// tc : o(nlogn)
// sc : o(1)
// class Solution{
//   public:
//     vector <int> countDistinct (int A[], int n, int k)
//     {
//       vector<int>v;
//       map<int,int>mp;
       
//       for(int i=0;i<k;i++)
//       {
//           mp[ A[i] ]++;
//       }
       
//       v.push_back(mp.size());
       
//       for(int i=k;i<n;i++)
//       {
//           if(mp[A[i-k]] ==1 )
//           {
//               mp.erase(A[i-k]);
//           }
//           else
//           {
//               mp[A[i-k]]--;
//           }
           
//             mp[A[i]]++;
           
//             v.push_back(mp.size());
//       }
       
//     //   cout<<mp.size()<<endl;
//       return v;
//     }
// };

// using hashing 
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
       vector<int>v;
       map<int,int>mp;
       
       for(int i=0;i<k;i++)
       {
           mp[ A[i] ]++;
       }
       
       v.push_back(mp.size());
       
       for(int i=k;i<n;i++)
       {
           if(mp.find(A[i-k]) != mp.end())
           {
               if(mp[A[i-k]] ==1 )
               {
                   mp.erase(A[i-k]);
               }
               else
               {
                   mp[A[i-k]]--;
               }
           }
            mp[A[i]]++;
           
            v.push_back(mp.size());
       }
       
    //   cout<<mp.size()<<endl;
       return v;
    }
};

// Interview Bit 
// using map
vector<int> Solution::dNums(vector<int> &A, int B) 
{
    vector<int>v; 

    int n = A.size();
    map<int,int> mp;

    for(int i=0;i<B;i++)
    {
        mp[ A[i] ]++;
    }

    v.push_back(mp.size());

    for(int i =B;i<n;i++)
    {
        if(mp.find(A[i-B]) != mp.end())
        {
            if(mp [A[i-B]] == 1)
            {
                mp.erase(A[i-B]);
            }
            else
            {
                mp[A[i-B]] --;
            }

        }

        mp[ A[i] ]++;

        v.push_back(mp.size());
    }

    return v;

}
