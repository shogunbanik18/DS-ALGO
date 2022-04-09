// TLE
// median found in asorted way ??
// tc : o(n*n)
// sc : o(n)
// class MedianFinder 
// {
// public:
//     vector<int>v;
    
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) 
//     {
//         v.push_back(num);
//     }
    
//     double findMedian()
//     {
//         sort(v.begin(),v.end());
//         int n = v.size();
//         double mid;
        
//         if(n%2==0)
//         {
//             int mid1 = n/2;
//             int mid2 = (n-1)/2;
            
//             // type casting 
//             mid = (double)(v[mid1] + v[mid2])/(double)2;
//         }
        
//         else
//         {
//             mid = v[n/2];
//         }
        
//         return mid;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Using the concept of priority queue
// tc : o(nlogn)
// sc : o(1)
// using 2 heap concept 
class MedianFinder 
{
public:
    
    priority_queue<int> maxheap;
    priority_queue< int,vector<int> , greater<int> > minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(maxheap.empty() or  maxheap.top() > num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        
        // check for sizes
        if(maxheap.size() > minheap.size() + 1 )
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        else if(minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian()
    {
        double mid;
        if(maxheap.size() == minheap.size())
        {
            if(maxheap.empty())
            {
                return 0;
            }
            
            else
            {
                // type casting 
                mid = (double)(maxheap.top() + minheap.top())/(double)2;
            }
        }
        
        else
        {
            if(maxheap.size() > minheap.size())
            {
                mid = maxheap.top();
            }
            
            else
            {
                mid = minheap.top();
            }
        }
        
        return mid;
    }
};
