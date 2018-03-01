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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; /*上次进的位*/
        ListNode head(0);
        ListNode* tail = &head;
        while(l1 && l2) {
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            ListNode* node = new ListNode(tmp % 10);
            tail->next = node;
            tail = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmp = l1->val + carry;
            carry = tmp / 10;
            ListNode* node = new ListNode(tmp % 10);
            tail->next = node;
            tail = node;
            l1 = l1->next;
        }
        while (l2) {
            int tmp = l2->val + carry;
            carry = tmp / 10;
            ListNode* node = new ListNode(tmp % 10);
            tail->next = node;
            tail = node;
            l2 = l2->next;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            tail->next = node;
        }
        return head.next;
    }
};