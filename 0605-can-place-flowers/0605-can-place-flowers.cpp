class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int nCanPlant = 0;
        
        for(int i = 0; i < flowerbed.size(); ++i) {
            bool back = true, curr = true, next = true;
            
            // Check back
            if(i > 0  and  flowerbed[i-1] == 1)
                back = false;
            
            // Check current
            if(flowerbed[i] == 1)
                curr = false;
            
            // Check next
            if(i < flowerbed.size()-1  and  flowerbed[i+1] == 1)
                next = false;
            
            if(back and curr and next) {
                flowerbed[i] = 1;
                ++nCanPlant;
            }
        }
        
        return nCanPlant >= n;
    }
};