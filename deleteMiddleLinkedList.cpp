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
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        // if one element is there in linkedlist.
        if(head->next == NULL) return NULL;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next!=NULL ){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //slow will point to mid-1 index.
        
        ListNode* mid = slow->next;
        
        slow->next = mid->next;
        mid->next = NULL;
        
        delete(mid);
        
        
        return head;
        
        
        
        
        
    }
};
