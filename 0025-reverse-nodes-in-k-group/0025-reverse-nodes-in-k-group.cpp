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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* currant = head;
        int cnt = 0;
        while(currant != NULL && cnt < k){
            currant = currant->next;
            cnt++;
        }

        if(cnt < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr =  head;
        ListNode* nexNode = NULL;
        int i = 0;

        while(curr != NULL && i < k){
            nexNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexNode;
            i++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};