class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cntNum;
        
        for(int num : arr)
            ++cntNum[num];
        
        set<int> occurs;
        for(auto i : cntNum)
        {
            if(occurs.find(i.second) != occurs.end())
                return false;
            occurs.insert(i.second);
        }
        
        return true;
    }
};