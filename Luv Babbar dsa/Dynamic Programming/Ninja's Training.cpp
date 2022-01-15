// Recursive solution
// tc: O(N*4)*3
// sc:o(n) stack space +o(n*4)
int f(int day,int last,vector<vector<int>>&points)
{
//     base case 
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+f(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(n-1,3,points);
}


// Using 2d dp 
// Memoisation using dp 
// tc: O(N*4)*3
// sc:o(n)+o(n*4)
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp)
{
//     base case 
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+f(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}


// Bottom up approach
// tabular form 
// space optimisation 
// tc: O(N*4)*3
// sc:o(n*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,0));
//     selection procedure 
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

// space optimisation 
// tc: O(N*4)*3
// sc:o(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4,0);
//     selection procedure 
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][1],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++)
    {
        vector<int>temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
            
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }    
        }
        prev=temp;
    }
    return prev[3];
}
