class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int cnt = 0, res = 0, stIdx = -1;
        
        for(int i = 0; i < fruits.size(); ++i) {
            int currFruit = fruits[i];
            
            // If the map is empty
            if(mp.size() == 0) {
                stIdx = i;
            }
            else if(mp.size() == 2  and  mp.find(currFruit) == mp.end()) {
                // To be removed fruit
                int lastIdx = INT_MAX, remFruit = -1;
                
                for(auto i : mp) {
                    if(i.second < lastIdx) {
                        lastIdx = i.second;
                        remFruit = i.first;
                    }
                }
                
                mp.erase(remFruit);
                
                // Remove the elements till last index
                cnt -= (lastIdx - stIdx + 1);
                
                // Now mark the new start index
                stIdx = lastIdx + 1;
            }
            
            ++cnt;
            mp[currFruit] = i;
            
            res = max(res, cnt);
        }
        
        return res;
    }
};