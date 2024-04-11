class Solution
{
public:
    void changeRes(char& currCh, int& cnt, vector<char>& chars, int& resIdx, int& resCnt)
    {
        chars[resIdx++] = currCh;
        if(cnt == 1)
        {
            resCnt += 1;
            return;
        }

        vector<char> tmp;
        
        while(cnt > 0)
        {
            tmp.push_back('0' + (cnt % 10));
            cnt /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        
        for(char ch : tmp)
            chars[resIdx++] = ch;
        
        resCnt += 1 + tmp.size();
    }
    int compress(vector<char>& chars)
    {
        char currCh = chars[0];
        int len = chars.size(), idx = 1, cnt = 1, resIdx = 0, resCnt = 0;
        
        for(int idx = 1; idx < len; ++idx)
        {
            if(chars[idx] != currCh)
            {
                changeRes(currCh, cnt, chars, resIdx, resCnt);
                
                currCh = chars[idx];    cnt = 0;
            }
            ++cnt;
        }
        changeRes(currCh, cnt, chars, resIdx, resCnt);
        
        return resCnt;
    }
};