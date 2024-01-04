class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        map<int, int> mp;
        
        for(int i : nums)       ++mp[i];
        
        int res = 0;
        for(auto curr : mp)
        {   
            // Cannot be removed
            if(curr.second == 1)
                return -1;
            
            res += curr.second / 3;
            res += (curr.second % 3 > 0);
        }
            
        return res;
    }
};
