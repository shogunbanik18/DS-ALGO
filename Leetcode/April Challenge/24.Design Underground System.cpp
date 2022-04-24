// using 2 maps 
// implementation
class UndergroundSystem
{
public:
    
    map< int , pair<string  , int> > mp1;
    map<pair<string,string> , vector<int>> mp2;
    
    UndergroundSystem() 
    {
        
    }
    
    void checkIn(int id, string stationName, int t)
    {
        mp1[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t)
    {
        
        if(mp1.find(id) != mp1.end())
        {
            mp2[{mp1[id].first , stationName}].push_back(t-mp1[id].second );
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        double sum=0;
        double count = 0;
        
        if(mp2.find({startStation,endStation}) != mp2.end())
        {
            for(auto x : mp2[{startStation,endStation}] )
            {
                 sum += x;
                count++;
            }
        }
        
        return sum/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
