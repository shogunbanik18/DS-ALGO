// using 2 maps 
// 1 for the frequency cnt 
// 1 for the group stack and max frequncy variable 

// tc : o(n)
// sc : o(1)
class FreqStack {
public:
    map<int,int> freq;
    map<int, stack<int>> group;
    int max_freq = 0;
    
    FreqStack() 
    {
        
    }
    
    void push(int val)
    {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() 
    {
        // find the element with max frequncy 
        int top_max_freq = group[max_freq].top();
        group[max_freq].pop();
        
        // decresaing the max frequency 
        freq[top_max_freq]--;
        
        // checking for the size 
        if(group[max_freq].size()==0)
        {
            max_freq--;
        }
        
        return top_max_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
