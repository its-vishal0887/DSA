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
    ListNode* insertAtTail(int n, ListNode*& head, ListNode*& tail) {
        ListNode* temp = new ListNode(n);
        if (tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* temp = head;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
            // head = delFrmHead(head);
        }

        int i = left - 1, j = right - 1;
        while (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        for (int i = 0; i < arr.size(); i++) {
            curr = insertAtTail(arr[i], curr, prev);
        }
        return curr;
    }
};