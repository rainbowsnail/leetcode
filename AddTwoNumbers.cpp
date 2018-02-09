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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* cur = result;
        int sum = 0;
        int tens = 0;
        int single = 0;
        int n1,n2;
        
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL) n1 = l1->val;
            else n1 = 0;
            if(l2!=NULL) n2 = l2->val;
            else n2 = 0;
            
            sum = n1 + n2 +tens;
            single = sum % 10;
            tens = sum / 10;
            cur->next = new ListNode(single);
            cur = cur->next;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(tens != 0){
            cur->next = new ListNode(tens);
        }
        return result->next;
    }
};
