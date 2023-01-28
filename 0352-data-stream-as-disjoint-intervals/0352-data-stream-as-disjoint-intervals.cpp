class SummaryRanges {
public:
    map<int, vector<int>> mpNumInt;
    set<vector<int>> intervals;
    
    SummaryRanges() { ; }
    
    void addNum(int value) {
        // Already present
        if(mpNumInt.find(value) != mpNumInt.end())      return;
        
        vector<int> currInt = {value, value};
        
        // Check if we have its previous present
        if(mpNumInt.find(value-1) != mpNumInt.end()) {
            auto prevInt = mpNumInt[value-1];
            currInt[0] = min(currInt[0], prevInt[0]);
            currInt[1] = max(currInt[1], prevInt[1]);
            intervals.erase(prevInt);
        }
        
        // Check if we have its next present
        if(mpNumInt.find(value+1) != mpNumInt.end()) {
            auto nextInt = mpNumInt[value+1];
            currInt[0] = min(currInt[0], nextInt[0]);
            currInt[1] = max(currInt[1], nextInt[1]);
            intervals.erase(nextInt);
        }
        
        // Assign respective intervals to all the integers
        for(int i = currInt[0]; i <= currInt[1]; ++i)
            mpNumInt[i] = currInt;
        
        intervals.insert(currInt);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        
        for(auto i : intervals)
            res.push_back(i);
        
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */