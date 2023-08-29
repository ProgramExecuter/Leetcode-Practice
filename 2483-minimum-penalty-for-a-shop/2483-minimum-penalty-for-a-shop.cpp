class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size(), front = 0, back = 0;
        vector<int> penSt(n, 0), penEn(n, 0);
        
        for(int i = 0; i < n; ++i) {
            if(cust[n-1-i] == 'Y')  ++back;
            
            penSt[i] = front;
            penEn[n-1-i] = back;
            
            if(cust[i] == 'N')      ++front;
        }
        
        int res = n, minPen = penSt[n-1];
        
        for(int i = n-1; i >= 0; --i) {
            int pen = penSt[i] + penEn[i];
            
            if(pen <= minPen) {
                minPen = pen;
                res = i;
            }
        }
        
        return res;
    }
};