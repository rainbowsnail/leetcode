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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* cur = head;
        while(l1 != NULL && l2 != NULL){
            int num;
            if(l2->val < l1->val){num = l2->val; l2 = l2->next;}
            else{num = l1->val; l1 = l1->next;}
            ListNode *tmp = new ListNode(num);
            if(head == NULL) head = cur = tmp;
            else{
                cur->next = tmp;
                cur = tmp;
            }
        }
        ListNode * rest = l1;
        if(rest == NULL) rest = l2;
        while(rest != NULL){
            int num;
            num = rest->val; 
            rest = rest->next;
            ListNode *tmp = new ListNode(num);
            if(head == NULL) head = cur = tmp;
            else{
                cur->next = tmp;
                cur = tmp;
            }
        }
        return head;
        
    }
};
