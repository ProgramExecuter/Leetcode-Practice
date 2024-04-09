class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int len = nums.size();
        
        vector<int> pre(len, 1), suf(len, 1);
        int preMul = nums[0], sufMul = nums[len-1];
        
        for(int i = 1; i < len; ++i)
        {
            pre[i-1] = preMul;
            preMul *= nums[i];
        }
        
        for(int i = len-2; i >= 0; --i)
        {
            suf[i+1] = sufMul;
            sufMul *= nums[i];
        }
        
        vector<int> res;
        for(int i = 0; i < len; ++i)
        {
            int curr = 1;
            
            if(i != 0)          curr *= pre[i-1];
            if(i != len-1)      curr *= suf[i+1];
            
            res.push_back(curr);
        }
            
        return res;
    }
};