class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        stack<int> st;
        vector<int> res;

        for(int num : nums) {
            int tmp = num;
            while(tmp) {
                st.push(tmp % 10);
                tmp /= 10;
            }
            while(!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }
        }

        return res;
    }
};