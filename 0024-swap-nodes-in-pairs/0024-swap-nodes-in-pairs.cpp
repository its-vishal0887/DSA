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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode* temp = head;
        int i = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nNode = head;
        while (temp != NULL && i < 2) {
            nNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nNode;
            i++;
        }
        head->next = swapPairs(curr);
        return prev;
    }
};