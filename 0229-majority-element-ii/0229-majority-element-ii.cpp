class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MAX, ele2 = INT_MAX, cnt1 = 0, cnt2 = 0, len = nums.size();

        // Find possible majority elements
        for(int num : nums) {
            if(cnt1 == 0  &&  num != ele2) { ele1 = num; cnt1 = 1; }
            else if(cnt2 == 0  &&  num!= ele1) { ele2 = num; cnt2 = 1; }
            else if(num == ele1) { ++cnt1; }
            else if(num == ele2) { ++cnt2; }
            else { --cnt1;  --cnt2; }
        }

        // Check Occurance
        cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if(num == ele1) { ++cnt1; }
            if(num == ele2) { ++cnt2; }
        }
        
        vector<int> res;
        if(cnt1 > len/3) { res.push_back(ele1); }
        if(cnt2 > len/3) { res.push_back(ele2); }

        return res;
    }
};