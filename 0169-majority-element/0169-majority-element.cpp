class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele = -1;

        for(int num : nums) {
            if(num == ele) { ++cnt; }
            else {
                if(cnt > 1) { --cnt; }
                else {
                    cnt = 1;
                    ele = num;
                }
            }
        }

        return ele;
    }
};