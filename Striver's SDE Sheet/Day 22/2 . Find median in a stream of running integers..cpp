// // TLE 
// class MedianFinder 
// {
// public:
    
//     vector<int>v;
    
//     MedianFinder() 
//     {
        
//     }
    
//     void addNum(int num) 
//     {
//         v.push_back(num);
        
//     }
    
//     double findMedian() 
//     {
//         int n = v.size();
//         sort(v.begin() , v.end());
        
//         double mid;
        
//         if(n%2!=0)
//         {
//             mid = v[n/2];
//         }
        
//         else
//         {
//             double mid1 = v[(n-1)/2];
//             double mid2 = v[n/2];
            
//             mid = (mid1+mid2)/2;
//         }    
//         return mid;
//     }
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */


// using the concept of priority queue
// tc : o(nlogn)
// sc : o(1)
class MedianFinder 
{
public:
    
    priority_queue<int , vector<int> , greater<int> > minheap; 
    priority_queue<int> maxheap;
        
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(maxheap.empty() or maxheap.top() > num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        
        
        if(maxheap.size() > minheap.size() + 1 )
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        else if(minheap.size() > maxheap.size() + 1 )
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() 
    {
       if(minheap.size() == maxheap.size())
       {
           if(maxheap.empty())
           {
               return 0;
           }
           
           else
           {
               double ans = (maxheap.top() + minheap.top()) /2.0;
               return ans;
           }
       }
        
        else
        {
            if(maxheap.size() > minheap.size())
            {
                return maxheap.top();
            }
            else
            {
                return minheap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
