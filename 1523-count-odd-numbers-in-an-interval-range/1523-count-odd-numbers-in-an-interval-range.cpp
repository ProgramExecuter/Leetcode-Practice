class Solution {
public:
    int countOdds(int low, int high) {
        int nEle = high - low + 1;
        
        if(low % 2  and  nEle % 2)
            return (nEle + 1) / 2;
        else
            return nEle / 2;
    }
};