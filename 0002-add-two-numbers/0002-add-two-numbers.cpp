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
    ListNode* revLL(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        while (curr != NULL) {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode(-1);
        ListNode* anss = ans;

        ListNode* f1 = temp1;
        ListNode* f2 = temp2;

        int car = 0;
        while (f1 != NULL && f2 != NULL) {
            int dat = (f1->val + f2->val) + car;
            int rem = dat % 10;
            car = dat / 10;
            ListNode* f3 = new ListNode(rem);
            ans->next = f3;
            ans = f3;
            f1 = f1->next;
            f2 = f2->next;
        }

        while (f1 != NULL) {
            int dat = f1->val + car;
            int rem = dat % 10;
            car = dat / 10;
            ListNode* f3 = new ListNode(rem);
            ans->next = f3;
            ans = f3;
            f1 = f1->next;
        }

        while (f2 != NULL) {
            int dat = f2->val + car;
            int rem = dat % 10;
            car = dat / 10;
            ListNode* f3 = new ListNode(rem);
            ans->next = f3;
            ans = f3;
            f2 = f2->next;
        }

        if(car != 0){
            ListNode* tempNode = new ListNode(car);
            ans->next = tempNode;
            ans = tempNode;
        }

        return anss->next;
    }
};