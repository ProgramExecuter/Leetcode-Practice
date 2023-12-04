class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string res = "", curr = "";
        
        for(int idx = 0; idx < num.size(); ++idx)
        {
            curr += num[idx];
            if(idx >= 3)    curr.erase(curr.begin());
            
            if(curr[0] == curr[1] && curr[1] == curr[2])
                res = res.compare(curr) < 0 ? curr : res;
        }
        
        return res;
    }
};