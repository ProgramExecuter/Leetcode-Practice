class Solution {
public:
    string getStr(int num, int len)
    {
        string res = "";
        
        while(num)
        {
            res += char('0' + (num % 2));
            num /= 2;
        }
        
        int l = res.size();
        for(int i = 1; i <= len-l; ++i)    res += "0";
        reverse(res.begin(), res.end());
        
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int num = 0;
        
        for(string s : nums)
        {
            if(getStr(num, len) == s)
                ++num;
            else if(getStr(num, len) < s)
                break;
        }
        
        return getStr(num, len);
    }
};