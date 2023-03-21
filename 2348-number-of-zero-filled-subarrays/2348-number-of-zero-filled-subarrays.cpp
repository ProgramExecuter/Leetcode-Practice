class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0ll;
        int zeroCnt = 0;
        
        for(int i : nums) {
            if(i == 0) {
                ++zeroCnt;
            }
            else {
                cnt += ((1ll*(zeroCnt+1))*zeroCnt)/ 2;
                zeroCnt = 0;
            }
        }
        cnt += ((1ll*(zeroCnt+1))*zeroCnt)/ 2;
        
        return cnt;
    }
};