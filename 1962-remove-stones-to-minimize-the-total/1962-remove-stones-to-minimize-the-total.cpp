class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int totalStones = 0;
        
        // Put each piles's stone count in heap, and also calculate the total stones
        for(int nStones : piles) {
            q.push(nStones);
            totalStones += nStones;
        }
        
        while(k--) {
            // Get the top of heap, which is largest pile
            int curr = q.top();         q.pop();
            
            // Remove the required stones, and put back remaining to heap
            int toBeRemoved = curr / 2;
            q.push(curr - toBeRemoved);
            
            // Calculate the total remaining stones
            totalStones -= toBeRemoved;
        }
        
        return totalStones;
    }
};