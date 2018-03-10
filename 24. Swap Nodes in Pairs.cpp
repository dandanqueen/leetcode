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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
        	return head;
        }
        ListNode *p1, *p2, *p3;
        p1 = head;
        p3 = NULL;
        while(p1 && p1->next) {
        	p2 = p1->next;
        	p1->next = p2->next;
        	p2->next = p1;
        	if (p3) {
        		p3->next = p2;
        	}else {
        		// 交换前两个节点时头结点要改变
        		head = p2;
        	}
        	p3 = p1;
        	p1 = p1->next;
        }
        return head;
    }
};