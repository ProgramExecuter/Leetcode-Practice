#define pp pair<int, int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), currCap = w;
        priority_queue<pp, vector<pp>, greater<pp>> capPro;
        priority_queue<int> profit;
        
        // Put all the pairs in the 'capPro', in ascending order of capital
        for(int i = 0; i < n; ++i)
            capPro.push({capital[i], profits[i]});
        
        // Go on until EITHER both queues are empty OR k == 0 
        while((!capPro.empty() or !profit.empty()) and k > 0) {
            // get all the profits which can be used with 'currCap', in descending order
            while(!capPro.empty() and capPro.top().first <= currCap) {
                auto tmp = capPro.top();        capPro.pop();
                profit.push(tmp.second);
            }
            
            // No elements found, we cannot go ahead
            if(profit.empty())      return currCap;
            
            currCap += profit.top();        profit.pop();
            --k;
        }
        
        return currCap;
    }
};