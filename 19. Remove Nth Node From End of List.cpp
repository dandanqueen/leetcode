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
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(n --) {
        	p1 = p1->next;
        }
        if (!p1) {
        	// 删除头结点
        	ListNode *tmp = head;
        	head = head->next;
        	delete tmp;
        	return head;
        }
        while(p1->next) {
        	p1 = p1->next;
        	p2 = p2->next;
        }
        ListNode *tmp = p2->next;
        if (tmp) {
        	p2->next = tmp->next;
        	delete tmp;
        }
        return head;
    }
};