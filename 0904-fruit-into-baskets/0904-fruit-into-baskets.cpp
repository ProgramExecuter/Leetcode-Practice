class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int cnt = 0, res = 0, stIdx = -1;
        
        for(int i = 0; i < fruits.size(); ++i) {
            int currFruit = fruits[i];
            
            // If the map is empty, mark a new starting
            if(mp.size() == 0)
                stIdx = i;
            // New element to be added and one of old element to be removed
            else if(mp.size() == 2  and  mp.find(currFruit) == mp.end()) {
                // To be removed fruit and its last index
                int lastIdx = INT_MAX, remFruit = -1;
                
                // Find the fruit whose last index is lesser
                for(auto i : mp) {
                    if(i.second < lastIdx) {
                        lastIdx = i.second;
                        remFruit = i.first;
                    }
                }
                
                // Remove the fruit from range
                mp.erase(remFruit);
                
                // Remove the elements till last index
                cnt -= (lastIdx - stIdx + 1);
                
                // Now mark the new start index
                stIdx = lastIdx + 1;
            }
            
            // Add this fruit to the range, and mark its last index
            ++cnt;
            mp[currFruit] = i;
            
            // Find the most amount of fruits
            res = max(res, cnt);
        }
        
        return res;
    }
};