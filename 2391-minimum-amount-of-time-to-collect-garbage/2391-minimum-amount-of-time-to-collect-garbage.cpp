class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int lastM = -1, lastP = -1, lastG = -1;
        int len = garbage.size();
        
        for(int i = 0; i < len; ++i)
        {
            if(garbage[i].find("M") != -1)
                lastM = i;
            if(garbage[i].find("P") != -1)
                lastP = i;
            if(garbage[i].find("G") != -1)
                lastG = i;
        }
        
        int timeM = 0, timeP = 0, timeG = 0;
        for(int i = 0; i < len; ++i)
        {
            string s = garbage[i];
            
            if(i <= lastM)
            {
                timeM += count(s.begin(), s.end(), 'M');
                timeM += i == 0 ? 0 : travel[i-1];
            }
            if(i <= lastP)
            {
                timeP += count(s.begin(), s.end(), 'P');
                timeP += i == 0 ? 0 : travel[i-1];
            }
            if(i <= lastG)
            {
                timeG += count(s.begin(), s.end(), 'G');
                timeG += i == 0 ? 0 : travel[i-1];
            }
        }
        
        return timeM + timeP + timeG;
    }
};