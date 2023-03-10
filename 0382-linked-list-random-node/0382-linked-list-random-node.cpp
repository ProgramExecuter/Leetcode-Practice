/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> vect;
public:
    Solution(ListNode* head) {
        ListNode *curr = head;
        while(curr) {
            vect.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int randIdx = rand() % (vect.size());
        // cout << randNum << endl;
        
        return vect[randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */