class Solution {
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int, int>> st;
        
        pair<int, int> currPos;
        st.insert(currPos);
        
        for(char ch : path)
        {
            if(ch == 'N')   ++currPos.second;
            if(ch == 'S')   --currPos.second;
            if(ch == 'E')   ++currPos.first;
            if(ch == 'W')   --currPos.first;
            
            if(st.find(currPos) != st.end())
                return true;
            st.insert(currPos);
        }
        
        return false;
    }
};