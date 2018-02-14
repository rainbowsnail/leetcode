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
    static void swap(vector<pair<int,int>> & heap, int index1,int index2){
        pair<int,int> tmp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = tmp;
        return;
    }
    static void insert(pair<int,int> num, vector<pair<int,int>> & heap){
        int size = heap.size();
        heap.push_back(num);
        int father = (size - 1)/2;
        int cur = size;
        while(father != cur){
            if(heap[father].first > heap[cur].first)
                Solution::swap(heap, father,cur);
            cur = father;
            father = (father - 1)/2;
        }
        return;
    }
    static pair<int,int> getMin(vector<pair<int,int>> & heap){
        pair<int,int> min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        int cur = 0;
        while(2 * cur + 1 < heap.size()){
            if(2 * cur + 2 == heap.size() && 
               heap[cur].first > heap[2*cur + 1].first){
                Solution::swap(heap, cur, 2*cur + 1);
                cur = cur*2 + 1;
            }else if(heap[cur].first > heap[2*cur + 1].first &&
                     heap[2*cur + 1].first <= heap[2*cur + 2].first){
                Solution::swap(heap, cur, 2*cur + 1);
                cur = cur*2 + 1;
            }else if(heap[cur].first > heap[2*cur + 2].first &&
                     heap[2*cur + 1].first > heap[2*cur + 2].first){
                Solution::swap(heap, cur, 2*cur + 2);
                cur = cur*2 + 2;
            }else break;
            
        }
        return min;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        ListNode * cur = NULL;
        vector<pair<int,int>> heap;
        for(int i = 0;i < lists.size(); ++i){
            if(lists[i] != NULL) {
                Solution::insert(make_pair(lists[i]->val, i), heap);
                lists[i] = lists[i]->next;
            }
        }
        while(heap.size() > 0){
            pair<int,int> curnum = Solution::getMin(heap);
            if(head == NULL){
                head = new ListNode(curnum.first);
                cur = head;
            }else{
                cur->next = new ListNode(curnum.first);
                cur = cur->next;
            }
            if(lists[curnum.second] != NULL){
                Solution::insert(make_pair(lists[curnum.second]->val, curnum.second), heap);
                lists[curnum.second] = lists[curnum.second]->next;
            }
            
        }
        return head;
    }
};
