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
    static bool mutipleNum(ListNode *head, int k){
        for(int i = 0; i < k; ++i){
            if(head == NULL) return false;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* exhead = new ListNode(0);
        exhead->next = head;
        ListNode* prev = exhead;
        if(k < 2){
            return head;
        }
        while(Solution::mutipleNum(prev->next, k)){
            ListNode* firstnode = prev->next;
            ListNode* node1 = prev->next;
            ListNode* node2 = node1->next;
            ListNode* nextNode;
            for(int i = 0;i < k - 1;++i){
                nextNode = node2->next;
                node2->next = node1;
                node1 = node2;
                node2 = nextNode;
            }
            prev->next->next = nextNode;
            prev->next = node1;
            prev = firstnode;
        }
        return exhead->next;
    }
};
