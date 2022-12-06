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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

        ListNode* oddpointer =  head;
        ListNode* evenpointer = head->next;
        ListNode* startofeven = head->next;

        while(oddpointer->next && evenpointer->next){
                oddpointer->next = evenpointer->next;
                evenpointer->next = oddpointer->next->next;

                oddpointer = oddpointer->next;
                evenpointer = evenpointer->next;

        }

        // connect the even pointer to the odd pointer.
        oddpointer->next = startofeven;

        return head;

    }
};
