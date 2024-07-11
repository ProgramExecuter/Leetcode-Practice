class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char> st;
        
        for(char ch : s)
        {
            if(ch == ')')
            {
                string tmp = "";
                while(!st.empty() and st.top() != '(')
                {
                    tmp += st.top();
                    st.pop();
                }
                
                if(!st.empty())
                    st.pop();
                
                for(char curr : tmp)
                    st.push(curr);
            }
            else
                st.push(ch);
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
