class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        
        for(int x : nums) {
            st.insert(x);
            int revNum = 0;
            stack<int> tmp;
            while(x) {
                revNum = revNum * 10 + (x % 10);
                x /= 10;
            }
            
            st.insert(revNum);
        }
        
        return int(st.size());
    }
};