class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for(string ch : tokens) {
            if(ch == "+") {
                int num2 = st.top();    st.pop();
                int num1 = st.top();    st.pop();
                st.push(num1 + num2);
            }
            else if(ch == "-") {
                int num2 = st.top();    st.pop();
                int num1 = st.top();    st.pop();
                st.push(num1 - num2);
            }
            else if(ch == "*") {
                int num2 = st.top();    st.pop();
                int num1 = st.top();    st.pop();
                st.push(1ll * num1 * num2);
            }
            else if(ch == "/") {
                    int num2 = st.top();    st.pop();
                    int num1 = st.top();    st.pop();
                    st.push(num1 / num2);
            }
            else {
                st.push(stol(ch));
            }
        }
        
        return st.top();
    }
};