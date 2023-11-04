class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        // Maximum an ant would move in left array
        int mxLeft = 0;
        for(int x : left)   mxLeft = max(mxLeft, x);
        
        // Maximum an ant would move in right array
        int mnRight = n;
        for(int x : right)  mnRight = min(mnRight, x);
        mnRight = n - mnRight;
        
        return max(mxLeft, mnRight);
    }
};