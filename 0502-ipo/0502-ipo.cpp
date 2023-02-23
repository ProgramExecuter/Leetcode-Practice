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
        
        while((!capPro.empty() or !profit.empty()) and k > 0) {
            cout << k << " " << currCap << " | ";
            // Tranfer all the pairs to 'profit', which can be used with 'currCap'
            // in the descending order of profit
            while(!capPro.empty() and capPro.top().first <= currCap) {
                auto tmp = capPro.top();        capPro.pop();
                cout << tmp.first << " " << tmp.second << " , ";
                profit.push(tmp.second);
            }
            cout << " | ";
            
            if(profit.empty())      return currCap;
            
            currCap += profit.top();        profit.pop();
            --k;
            cout << currCap << " " << k << endl;
        }
        
        return currCap;
    }
};