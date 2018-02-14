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
    ListNode* swapPairs(ListNode* head) {
        ListNode * exhead = new ListNode(0);
        exhead->next = head;
        ListNode * prev = exhead;
        ListNode * node1 = head;
        ListNode * node2;
        while(node1 != NULL && node1->next != NULL){
            node2 = node1->next;
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
            node1 = node1->next;
        }
        return exhead->next;
    }
};
