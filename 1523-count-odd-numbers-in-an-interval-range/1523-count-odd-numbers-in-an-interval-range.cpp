class Solution {
public:
    int countOdds(int low, int high) {
        int nEle = high - low + 1;
        
        // If there are odd no. of elements in the range, and the range starts from
        // odd number, then there will be an extra odd element than even
        if(low % 2  and  nEle % 2)
            return (nEle + 1) / 2;
        else
            return nEle / 2;
    }
};