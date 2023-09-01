class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        
        for(int i = 0; i <= n; ++i) {
            int tmp = i, cnt = 0;
            while(tmp) {
                cnt += tmp % 2;
                tmp /= 2;
            }
            res[i] = cnt;
        }
        
        return res;
    }
};