class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x, res = 1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(1ll*mid*mid == x) {
                return mid;
            } else if(1ll*mid*mid < x) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};