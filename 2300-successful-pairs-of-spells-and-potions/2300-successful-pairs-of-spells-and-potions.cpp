class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort (potions.begin(), potions.end());
        
        int nP = potions.size();
        vector<int> res;
        
        for (int spell : spells) {
            int low = 0, high = nP-1;
            
            while(low < high) {
                int mid = low + (high - low) / 2;
                
                if(1ll * spell * potions[mid]  >=  success) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            
            int nSuccessPairs = 0;
            
            if(1ll * spell * potions[low]  >= success)
                nSuccessPairs = nP - low;
                
            res.push_back(nSuccessPairs);
        }
        
        return res;
    }
};