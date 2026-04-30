class Solution {
public:
    int cntMadeBouqet(vector<int>& bloomDay, int& n, int& cntNeed, int& days) {
        int cntBloomed = 0, currIdx = 0, startIdx = 0, totalBouquets = 0;
        
        while(currIdx < n) {
            if(bloomDay[currIdx] <= days) {
                ++cntBloomed;
            }

            // We've got a window
            if(currIdx-startIdx+1 == cntNeed) {
                if(cntBloomed == cntNeed) {
                    ++totalBouquets;
                    startIdx = currIdx + 1;
                    cntBloomed = 0;
                } else {
                    // Slide starting element of this window forward
                    if(bloomDay[startIdx] <= days)  --cntBloomed;
                    ++startIdx;
                }
            }

            ++currIdx;
        }

        return totalBouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Not enough flowers for bouquet
        if(1ll*m*k > n)     return -1;

        int low = 1, high = 1, res = -1;
        for(int num : bloomDay)     high = max(high, num);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int bouquetCnt = cntMadeBouqet(bloomDay, n, k, mid);

            if(bouquetCnt >= m) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};