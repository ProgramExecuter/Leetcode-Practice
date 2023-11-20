class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        travel.insert(travel.begin(), 0);
        
        int lastM = -1, lastP = -1, lastG = -1;
        int len = garbage.size(), res = 0, sum = 0;
        
        for(int i = 0; i < len; ++i)
        {
            res += garbage[i].size();       // We will pick all the trash, regardless
            sum += travel[i];               // Sum the travel time till current index
            travel[i] = sum;
            
            if(garbage[i].find("M") != -1)  // Find last index for each type of garbage
                lastM = i;
            if(garbage[i].find("P") != -1)
                lastP = i;
            if(garbage[i].find("G") != -1)
                lastG = i;
        }
        
        // Add the travel time for different types of garbage(may not travel same distance)
        if(lastM >= 0)      res += travel[lastM];
        if(lastP >= 0)      res += travel[lastP];
        if(lastG >= 0)      res += travel[lastG];
        
        return res;
    }
};