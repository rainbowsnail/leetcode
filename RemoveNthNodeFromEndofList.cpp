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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> pointers;
        ListNode * cur = head;
        int len = 0;
        while(cur != NULL){
            pointers.push_back(cur);
            len++;
            cur = cur->next;
        }
        if (n == 1){
            if(len == 1)return NULL;
            pointers[len - 2]->next = NULL;
            return head;
        }else if(n == len){
            return head->next;
        }else{
            ListNode* prev = pointers[len - n - 1];
            ListNode* next = pointers[len - n + 1];
            prev->next = next;
            return head;
        }
        
    }
};
