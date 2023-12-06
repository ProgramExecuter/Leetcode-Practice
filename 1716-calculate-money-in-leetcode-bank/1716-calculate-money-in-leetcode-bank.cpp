class Solution {
public:
    int totalMoney(int n)
    {
        int prevMon = 0, curr = 0, total = 0;
        
        for(int cnt = 0; cnt < n; ++cnt)
        {
            if(cnt % 7 == 0)    curr = ++prevMon;
            else                ++curr;
            
            total += curr;
        }
        
        return total;
    }
};