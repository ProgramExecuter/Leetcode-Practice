class Solution {
    vector<string> order1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
                             "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> order2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", 
                          "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string findWord(int num)
    {
        vector<string> tmp;
        int cnt = 0, prev = 0;
        while(num > 0)
        {
            string tmpStr = "";
            if(cnt == 0)
            {
                prev = num % 10;
                if(prev > 0)
                    tmpStr = order1[num % 10];
            }
            else if(cnt == 1)
            {
                if((num % 10) == 1)
                {
                    tmp.clear();
                    int tmpCurr = 10 + prev;
                    tmpStr = order1[tmpCurr];
                }
                else
                {
                    tmpStr = order2[num % 10];
                }
            }
            else
            {
                if((num % 10) > 0)
                    tmpStr += order1[num % 10] + " Hundred";
            }
            
            tmp.push_back(tmpStr);
            num /= 10;
            ++cnt;
        }
        
        string res = "";
        for(int i = tmp.size()-1; i >= 0; --i)
        {
            if(tmp[i].size() > 0)
                res += tmp[i] + " ";
        }
        if(res.size() > 0  and  res.back() == ' ')
            res.pop_back();
        return res;
    }
    string numberToWords(int num)
    {
        int order = 0;
        vector<string> resArr;
        
        while(num > 0)
        {
            string numStr = findWord(num % 1000);
            
            if(numStr.size() > 0)
            {
                if(order == 0)
                    numStr += "";
                else if(order == 1)
                    numStr += " Thousand";
                else if(order == 2)
                    numStr += " Million";
                else if(order == 3)
                    numStr += " Billion";
                else
                    numStr += " Trillion";
            }
            
            resArr.push_back(numStr);
            ++order;
            num /= 1000;
        }
        
        string res = "";
        for(int i = resArr.size()-1; i >= 0; --i)
        {
            if(resArr[i].size() > 0)
                res += resArr[i] + " ";
        }
        if(res.size() > 0  and  res.back() == ' ')
            res.pop_back();
        
        if(res.size() == 0)
            return "Zero";
        return res;
    }
};