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
    int len(ListNode* &head){
        int i =0;
        ListNode *temp = head;
        while(temp != NULL){
            i++;
            temp = temp->next;
        }
        return i;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* faste = head;
        ListNode* prev = head;
        int l = len(head);
        if(head->next == NULL) return NULL;

        while (faste != NULL && faste->next != NULL) {
            prev = slow;
            slow = slow->next;
            faste = faste->next->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;
    }
};