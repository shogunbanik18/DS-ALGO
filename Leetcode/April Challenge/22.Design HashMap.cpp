// Brute 
class MyHashMap
{
public:

    vector<pair<int,int>> v;
    
    MyHashMap()
    {
        
    }
    
    void put(int key, int value) 
    {
        bool found = false; 
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first == key)
            {
                found = true;
                v[i].second = value;
            }
        }
        
        if(found==false)
        {
            v.push_back({key,value});
        }
    }
    
    int get(int key)
    {
        int ans ;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first == key)
            {
                if(v[i].second==-1)
                {
                    return -1;
                }
                ans = v[i].second ;
                return ans;
            }
        }
        
        return -1;  
    }
    
    void remove(int key)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first == key)
            {
                v[i].second =-1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
