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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL || head->next == NULL) {
            return head;
        }
        int n = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;
        while (temp) {
            n++;
            tail = temp;
            temp = temp->next;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        int l = n - k;
        temp = head;
        ListNode* prev = NULL;
        while (l--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tail->next = head;
        return temp;
    }
};