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
    bool hasCycle(ListNode *head) {
    	if(head == NULL || head->next == NULL){
    		return false;
    	}
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        while(p1->next && p2->next){
        	if(p1->next->next == NULL){
        		break;	
        	}
        	if(p1 == p2 || p1->next == p2){
        		return true;
        	}
        	p1 = p1->next->next;
        	p2 = p2->next;
        }
        return false;
    }
};
