class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int mxBuy = tickets[k], timeReq = 0;
        
        // Sum up max tickets each user can buy
        for(int i = 0; i < tickets.size(); ++i) {
            // If the users are ahead(or user itself), then they can only buy at max 'tickets[k]', 
            // since after those tickets are sold, k-th user will finish buying
            if(i <= k)
                timeReq += min(mxBuy, tickets[i]);
            // And users after k-th person, can only buy at max 'tcikets[k-1]', since if k-th
            // user buys his last ticket, then he will again finish buying
            else
                timeReq += min(mxBuy-1, tickets[i]);
        }
        
        return timeReq;
    }
};