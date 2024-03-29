class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq; // max heap to store even numbers
        int m = INT_MAX, ans = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2)     nums[i] *= 2;
            
            pq.push(nums[i]);
            m = min(m, nums[i]);
        }
        
        while(!pq.empty()) {
            int top = pq.top();     pq.pop();
            
            ans = min(ans, top - m);
            
            if(top % 2)        break;
            
            m = min(m, top / 2);
            pq.push(top / 2);
        }
        
        return ans;
    }
};