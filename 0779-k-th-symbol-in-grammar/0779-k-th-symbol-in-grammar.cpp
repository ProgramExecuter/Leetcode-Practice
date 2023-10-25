class Solution {
public:
    int kthGrammar(int n, int k) {
        // Treat it as binary tree, and find parent of it(1-indexed)
        if(n == 1)
            return 0;
        
        if(k % 2 == 0)
            return kthGrammar(n-1, (k+1)/2) == 0 ? 1 : 0;
        else
            return kthGrammar(n-1, (k+1)/2) == 0 ? 0 : 1;
    }
};