class Solution {
public:
    // Brute force 
    // tc:o(n*n)
    // sc:o(1)
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            int minheight=INT_MAX;
            for(int j=i;j<n;j++)
            {
                minheight = min(minheight,heights[j]);
                maxarea = max(maxarea,(j-i+1)*minheight);
            }
        }
        return maxarea;
    }
    
    
    // using next smaller element and prev smaller element 
    // tc:o(n)+o(n)
    // sc:o(n)+o(n)+o(n)
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>st;
        int leftsmall[n],rightsmall[n];
        
        // finding the left smaller element
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                leftsmall[i]=0;
            }
            else
            {
                leftsmall[i]= st.top()+1;
            }
            st.push(i);
        }
        
        // clearing the stack
        while(!st.empty())
        {
            st.pop();
        }
        
        // finding the right smaller element
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                rightsmall[i]=n-1;
            }
            else
            {
                rightsmall[i]= st.top()-1;
            }
            st.push(i);
        }
        
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            int maxi = (rightsmall[i]-leftsmall[i]+1)*heights[i];
            maxArea=max(maxArea,maxi);
        }
        return maxArea;
    }
    
    // intuition is to make the stack increasing 
    // tc:o(n)+o(n)
    // sc:o(n)
    int largestRectangleArea(vector<int>& histo)
    {
        int n=histo.size();
        stack<int>st;
        int maxarea=0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() and (i==n or histo[st.top()]>=histo[i]))
            {
                int height= histo[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width=i;
                }
                else
                {
                    width =i-st.top()-1;
                }
                maxarea =max(maxarea, height*width);
            }
            st.push(i);
        }
        return maxarea;
    }   
};
