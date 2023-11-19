class Solution {
public:
    int reductionOperations(vector<int>& nums)
    {
        map<int, int> mp;
        int mn = nums[0];
        
        for(int num : nums)
        {
            ++mp[num];
            mn = min(mn, num);
        }
        
        int res = 0, sumCnt = 0;
        for(auto curr = mp.rbegin(); curr != mp.rend(); ++curr)
        {
            int ele = curr->first, cnt = curr->second;
            
            if(ele == mn)   break;
            
            sumCnt += cnt;
            res += sumCnt;
        }
        
        return res;
    }
};