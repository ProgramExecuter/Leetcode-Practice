class Solution {
public:
    vector<int> minOperations(string boxes) {
        int currBall = 0, currSum = 0, n = boxes.size();
        vector<int> pre(n, 0), post(n, 0);
        
        for(int i = 0; i < n; ++i) {
            pre[i] = currBall + currSum;
            currSum = pre[i];
            if(boxes[i] == '1')     ++currBall;
        }
        
        currBall = 0, currSum = 0;
        for(int i = n-1; i >= 0; --i) {
            post[i] = currBall + currSum;
            currSum = post[i];
            if(boxes[i] == '1')     ++currBall;
        }
        
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
            res[i] = pre[i] + post[i];
        
        return res;
    }
};