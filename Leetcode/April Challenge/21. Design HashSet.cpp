// Brute 
class MyHashSet 
{
public:
    
    vector<int>v;
    
    MyHashSet()
    {
        
    }
    
    void add(int key) 
    {
         bool present = false;
        if(v.size()==0)
        {
            v.push_back(key);
        }
        
        else
        {
           for(auto x : v) 
            {
                if(x==key)
                {
                    present = true;
                }
            } 
        }
        
        if(present==false)
        {
            v.push_back(key);
        }
        
        
    }
    
    void remove(int key) 
    {
        vector<int>a;
        for(auto x : v)
        {
            if(x!=key)
            {
                a.push_back(x);
            }
        }
        
        v = a;
    }
    
    bool contains(int key) 
    {
         bool present = false;
           for(auto x : v)
            {
                if(x==key)
                {
                    present = true;
                }
            } 
        return present;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
