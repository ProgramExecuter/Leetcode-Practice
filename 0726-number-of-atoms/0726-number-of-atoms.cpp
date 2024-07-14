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
    void addPreviousFormulaToStack(string &currElement, int &currCnt, stack<string> &st)
    {
        if(currElement != "")
            st.push(newFormula(currElement, currCnt));
        currElement = "", currCnt = 0;
    }
    void addPreviousFormulaToMap(string &currElement, int &currCnt, map<string, int> &mp)
    {
        if(currElement != "")
        {
            if(currCnt == 0)
                currCnt = 1;
            mp[currElement] += currCnt;
        }
        currElement = "", currCnt = 0;
    }
    string countOfAtoms(string formula)
    {
        stack<string> st;
        
        string currElement = "";
        int currCnt = 0;
        
        for(char ch : formula)
        {
            // Start of an element name
            if(ch >= 'A' and ch <= 'Z')
            {
                // Check if there was any previous element before this
                addPreviousFormulaToStack(currElement, currCnt, st);
                
                currElement += ch;
            }
            // Maybe ongoing element name
            else if(ch >= 'a' and ch <= 'z')
                currElement += ch;
            // Calculate no. of atoms
            else if(ch >= '0' and ch <= '9')
                currCnt = currCnt * 10 + (ch - '0');
            // Start of grouped formula
            else if(ch == '(')
            {
                // Check if there was any previous element before this
                addPreviousFormulaToStack(currElement, currCnt, st);
                
                st.push(string(1, ch));
            }
            // End of grouped formula  ')'
            else
            {
                // Check if there was any previous element before this
                addPreviousFormulaToStack(currElement, currCnt, st);
                
                // Get all the elements grouped in current bracket ()
                string tmpFormula;
                while(!st.empty()  and  st.top() != "(")
                {
                    tmpFormula += st.top();
                    st.pop();
                }
                
                // Remove bracket
                st.pop();
                
                // Add complete grouped formula to the stack
                currElement = tmpFormula;
            }
        }
        addPreviousFormulaToStack(currElement, currCnt, st);
        
        
        // Create complete Formula by popping from stack
        string completeFormula = "";
        while(!st.empty())
        {
            completeFormula += st.top();
            st.pop();
        }
        
        
        // Atoms to no. of atoms mapping
        map<string, int> mp;
        currElement = "", currCnt = 0;
        
        
        // Parse complete formula for mapping
        for(auto ch : completeFormula)
        {
            // Start of new element
            if(ch >= 'A'  and  ch <= 'Z')
            {
                addPreviousFormulaToMap(currElement, currCnt, mp);
                
                currElement += ch;
            }
            // Continuation of an element name
            else if(ch >= 'a'  and  ch <= 'z')
                currElement += ch;
            // No. of atoms
            else
                currCnt = currCnt * 10  + (ch - '0');
        }
        addPreviousFormulaToMap(currElement, currCnt, mp);
        
        
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










