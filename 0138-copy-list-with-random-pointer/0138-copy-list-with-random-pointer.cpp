/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)       return NULL;
        
        Node* dummy = new Node(0);
        Node* curr = head;
        
        // Insert copy nodes in original list
        while(curr) {
            Node* nxt = curr->next;                         // Save 'next'
            
            curr->next = new Node(curr->val);               // Create the copy node
            curr->next->next = nxt;                         // Put copied node, next to orginal
            
            curr = nxt;                                     // Move Ahead
        }
        
        // Assign random pointers to new list
        curr = head;
        while(curr) {
            Node* nxt = curr->next->next;
            
            if(curr->random)
                curr->next->random = curr->random->next;
            
            curr = nxt;
        }
        
        // Unlink 2 linked lists
        Node* prev = dummy;
        curr = head;
        while(curr) {
            Node* nxt = curr->next->next;                       // Save next original node
            
            if(nxt)                                             // Point copy node, to its
                curr->next->next = nxt->next;                   // next copy node
            
            prev->next = curr->next;                            // Link this copy node in list
            prev = prev->next;                                  // and move ahead in copy list
            
            curr->next = nxt;                                   // Mark next for original node
            
            curr = curr->next;                                  // Move ahead
        }

        return dummy->next;                                     // Send copy list's head
    }
};