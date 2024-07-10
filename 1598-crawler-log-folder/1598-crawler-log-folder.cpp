class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int currLevel = 0;
        
        for(string log : logs)
        {
            if(log == "../")
            {
                if(currLevel > 0)   --currLevel;
            }
            else if(log != "./")
                ++currLevel;
        }
        
        return currLevel;
    }
};