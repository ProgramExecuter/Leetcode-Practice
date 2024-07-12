class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        stack<char> st;
        char alreadyPresent = 'b', foundNext = 'a';
        int higherVal = y, lowerVal = x, res = 0;
        
        if(x > y)
        {
            alreadyPresent = 'a';
            foundNext = 'b';
            higherVal = x;
            lowerVal = y;
        }
        
        // Remove higher score chars
        for(char ch : s)
        {
            if(ch == foundNext and !st.empty()  and  st.top() == alreadyPresent)
            {
                st.pop();
                res += higherVal;
            }
            else
                st.push(ch);
        }
        
        // Remove lower score chars
        string tmpStr = "";
        while(!st.empty())
        {
            tmpStr.push_back(st.top());
            st.pop();
        }
        reverse(tmpStr.begin(), tmpStr.end());
        
        
        for(char ch : tmpStr)
        {
            if(ch == alreadyPresent and !st.empty()  and  st.top() == foundNext)
            {
                st.pop();
                res += lowerVal;
            }
            else
            {
                st.push(ch);
            }
        }
        
        return res;
    }
};

