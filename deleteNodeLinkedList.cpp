/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* nextNode = node->next;
        
        // step 1. 
        node->val = nextNode->val;
        
        // step2;
        node->next = nextNode->next;
        
        //step3
        nextNode->next = NULL;
        
        //step4
        delete(nextNode);
        
        
    }
};
