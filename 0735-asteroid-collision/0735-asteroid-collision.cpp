class Solution {
public:
    bool hasSameSign(int x, int y)
    {
        if((x <= 0 and y <= 0) || (x >= 0 and y >= 0))
            return true;
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> st;
        
        for(int curr : asteroids)
        {
            if(st.empty() || curr > 0)
            {   st.push(curr);      continue;   }
            
            // curr < 0
            while(!st.empty())
            {
                int tmp = st.top();

                if(tmp < 0)
                {   st.push(curr);  curr = 0;   }
                else
                {
                    if(abs(tmp) > abs(curr))
                    {   curr = 0;   break;  }
                    else if(abs(tmp) == abs(curr))
                    {   st.pop();   curr = 0;   break;  }
                    else
                    {   st.pop();   }
                }
            }
            if(curr != 0)   st.push(curr);
        }
        
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};