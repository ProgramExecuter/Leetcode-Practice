class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Find a XOR b
        int aXORb = 0;
        for(int x : nums)   aXORb ^= x;
        
        // Find a set bit in "a XOR b"
        // 9 bits are enough for num <= 1023
        int bit = 0;
        for(int i = 0; i <= 9; ++i) {
            // Found the bit which is set
            if( ((1<<i) & aXORb) != 0 ) {
                bit = i;
                break;
            }
        }
        
        // Take 2 sets of numbers's XOR, where in 1st set (bit)-th bit is set
        // and in other set it's unset
        int setBit = 0, unsetBit = 0;
        for(int x : nums) {
            if( ((1<<bit) & x) != 0 ) {
                setBit ^= x;
            }
            else {
                unsetBit ^= x;
            }
        }
        
        vector<int> ans;
        ans.push_back(setBit);
        ans.push_back(unsetBit);
        
        return ans;
    }
};