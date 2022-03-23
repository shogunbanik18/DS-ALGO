// class Solution 
// {
// private: 
    
//     int solve(int start , int target)
//     {
//         int mid = target/2;
//         int count=0;
        
//         while(start!=target)
//         {
//             if(start <=mid)
//             {
//                 start = start *2;
//                 count++;
//             }

//             else if(start>mid and start<=target)
//             {
//                 start = start *2;
//                 count++;
//             }

//             else if(start>target and start>mid)
//             {
//                 start = start-1;
//                 count++;
//             }
//         }
//         return count;
//     }
    
// public:
//     int brokenCalc(int startValue, int target)
//     {
//         return solve(startValue,target);
//     }
// };


// tc: o(nlogn)
// sc :o(1)

// using iteration 
// class Solution 
// {
// private: 
    
//     int solve(int start , int target)
//     {
//         int count=0;
        
//         while(target> start)
//         {
//             if(target%2==0)
//             {
//                 target = target/2;
//                 count++;
//             }
            
//             else if(target%2!=0)
//             {
//                 target = target + 1;
//                 count++;
//             }
//         }

//         return count + start -target;
//     }
    
// public:
//     int brokenCalc(int startValue, int target)
//     {
//         return solve(startValue,target);
//     }
// };


// using recursion 
class Solution 
{
public:
    int brokenCalc(int startValue, int target)
    {
        if(startValue >= target)
        {
            return startValue-target;
        }
        
        if(target&1)
        {
            return 1 + brokenCalc(startValue,target+1);
        }
        return 1 + brokenCalc(startValue,target/2);
    }
};
