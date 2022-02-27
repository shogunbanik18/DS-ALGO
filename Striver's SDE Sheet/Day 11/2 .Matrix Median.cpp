class Solution{   
public:

    // Brute force 
    // tc: o(n*n) + o(nlogn) +o(n/2);
    // sc: o(n)
    int median(vector<vector<int>> &matrix, int r, int c)
    {
      vector<int>v;
      for(int i =0;i<r;i++)
      {
          for(int j=0;j<c;j++)
          {
              v.push_back(matrix[i][j]);
          }
      }
      sort(v.begin(),v.end());
      int low =0;
      int high=v.size()-1;
      int mid = low+high/2;
      return v[mid];
               
    }

// tc: 32 * n *log2(m)
// sc: o(1)
class Solution{   
public:
    int findsmallerequltomid(vector<int>&row,int mid)
    {
        int l=0;
        int h=row.size()-1;
        while(l<=h)
        {
            int md=(l+h)/2;
            if(row[md]<=mid)
            {
                l=md+1;
            }
            else
            {
                h=md-1;
            }
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int low=1;
        int high =1e9;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            int count=0;
            for(int i=0;i<r;i++)
            {
                count = count + findsmallerequltomid(matrix[i],mid);
            }
            
            if(count<=(r*c)/2)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
        // code here          
    }
};

    
    
//     Self Dry Run 
    class Solution{   
public:
    
    int findsmallerelements(vector<int> &row,int mid)
    {
        int l=0;
        int h=row.size()-1;
        while(l<=h)
        {
            int md = (l+h)/2;
            if(row[md]<=mid)
            {
                l=md+1;
            }
            else
            {
                h=md-1;
            }
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
      int low=1;
      int high=1e9;
      while(low<=high)
      {
          int mid = (low +high)/2;
          int count=0;
          for(int i=0;i<r;i++)
          {
              count+= findsmallerelements(matrix[i],mid);
          }
           
          if(count<=(r*c)/2)
          {
              low=mid+1;
          }
          else
          {
              high=mid-1;
          }
      }
      return low;
    }

};
