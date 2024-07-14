class Solution {
public:
    string newFormula(string str, int cnt)
    {
        if(cnt == 0)
            return str;
        
        string res = "";
        
        string currEle = "";
        int currCnt = 0;
        
        for(char ch : str)
        {
            if(ch >= 'A'  and  ch <= 'Z')
            {
                if(currEle != "")
                {
                    res += currEle;
                    if(currCnt == 0)        currCnt = 1;
                    
                    res += to_string(1ll * cnt * currCnt);
                }
                currEle = "", currCnt = 0;
                
                currEle += ch;
            }
            else if(ch >= 'a'  and  ch <= 'z')
            {
                currEle += ch;
            }
            else
            {
                currCnt = currCnt * 10  + (ch - '0');
            }
        }
        if(currEle != "")
        {
            res += currEle;
            if(currCnt == 0)        currCnt = 1;
                    
            res += to_string(1ll * cnt * currCnt);
        }
        
        return res;
    }
    void addStringToStack(string &currElement, int &currCnt, stack<string> &st)
    {
        if(currElement != "")
            st.push(newFormula(currElement, currCnt));
        currElement = "", currCnt = 0;
    }
    string countOfAtoms(string formula)
    {
        stack<string> st;
        
        string currElement = "";
        int currCnt = 0;
        
        for(char ch : formula)
        {
            if(ch >= 'A' and ch <= 'Z')
            {
                addStringToStack(currElement, currCnt, st);
                currElement += ch;
            }
            else if(ch >= 'a' and ch <= 'z')
                currElement += ch;
            else if(ch >= '0' and ch <= '9')
                currCnt = currCnt * 10 + (ch - '0');
            else if(ch == '(')
            {
                addStringToStack(currElement, currCnt, st);
                st.push(string(1, ch));
            }
            else
            {
                addStringToStack(currElement, currCnt, st);
                
                vector<string> tmp;
                string tmpFormula;
                
                while(!st.empty()  and  st.top() != "(")
                {
                    tmp.push_back(st.top());
                    st.pop();
                }
                cout << "\n";
                reverse(tmp.begin(), tmp.end());
                
                for(string curr : tmp)
                    tmpFormula += curr;
                
                // Remove bracket
                if(!st.empty())
                    st.pop();
                
                currElement = tmpFormula;
            }
        }
        addStringToStack(currElement, currCnt, st);
        
        
        // Create complete Formula
        string completeFormula = "";
        while(!st.empty())
        {
            completeFormula += st.top();
            st.pop();
        }
        
        // Parse complete formula for mapping
        map<string, int> mp;
        currElement = "", currCnt = 0;
        for(auto ch : completeFormula)
        {
            if(ch >= 'A'  and  ch <= 'Z')
            {
                if(currElement != "")
                {
                    if(currCnt == 0)
                        currCnt = 1;
                    mp[currElement] += currCnt;
                }
                currElement = "", currCnt = 0;
                
                currElement += ch;
            }
            else if(ch >= 'a'  and  ch <= 'z')
            {
                currElement += ch;
            }
            else
            {
                currCnt = currCnt * 10  + (ch - '0');
            }
        }
        if(currElement != "")
        {
            if(currCnt == 0)
                currCnt = 1;
            mp[currElement] += currCnt;
        }
        
        
        // Resultant Formula for returning
        string resFormula = "";
        for(auto i : mp)
        {
            resFormula += i.first;
            if(i.second > 1)
                resFormula += to_string(i.second);
        }
        
        return resFormula;
    }
};










