class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), tmpRes = -1, res = -1;
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high-low) / 2;
            int missingNumsCntTillNow = arr[mid] - (mid+1);

            if(missingNumsCntTillNow >= k) {
                tmpRes = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Now we know the index till which there are at-least k missing numbers
        if(tmpRes == -1) {
            int missingTillLastEle = arr[n-1] - n;
            res = arr[n-1] + (k - missingTillLastEle);
        } else {
            if(tmpRes-1 >= 0) {
                int missingTillPrevNum = arr[tmpRes-1] - tmpRes;
                res = arr[tmpRes-1] + (k - missingTillPrevNum);
            } else {
                res = k;
            }
        }

        return res;
    }
};