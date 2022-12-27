class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int extraRocks) {
        vector<int> remaining;
        int n = cap.size();
        
        // Calculate the reamaining space before full for each bag
        // then sort it in ascending order, so we fill the bags with less
        // remaining space first, so we get max. bags filled
        for(int i = 0; i < n; ++i)
            remaining.push_back(cap[i] - rocks[i]);
        sort(remaining.begin(), remaining.end());
        
        int bagsFullyFilled = 0, i = 0;
        while(extraRocks > 0 and i < n) {
            // This bag can be filled
            if(extraRocks >= remaining[i]) {
                ++bagsFullyFilled;
                extraRocks -= remaining[i++];
            }
            // Cannot be filled, BREAK
            else 
                break;
        }
        
        return bagsFullyFilled;
    }
};