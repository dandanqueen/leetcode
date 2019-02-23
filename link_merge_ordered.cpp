#include <cstdio>
#include <cstdlib>


using namespace std;


typedef struct node
{
	int data;
	struct node *next;
}Node, *NodePtr;


NodePtr merge_ordered_link(NodePtr head1, NodePtr head2){
	if(head1->next == NULL){
		return head2;
	}
	if(head2->next == NULL){
		return head1;
	}
	NodePtr head = new Node;
	head->next = NULL;
	NodePtr tail = head;
	while(head1->next && head2->next){
		NodePtr p1 = head1->next;
		NodePtr p2 = head2->next;
		if(p1->data > p2->data){
			head1->next = p1->next;
			p1->next = tail->next;
			tail->next = p1;
			tail = p1;
		}else{
			head2->next = p2->next;
			p2->next = tail->next;
			tail->next = p2;
			tail = p2;
		}
	}
	NodePtr head3 = head1->next ? head1 : head2;
	while(head3->next){
		NodePtr p = head3->next;
		head3->next = p->next;
		p->next = tail->next;
		tail->next = p;
		tail = p;
	}
	free(head1);
	free(head2);
	return head;
}

void free_link(NodePtr head){
	while(head){
		NodePtr p = head;
		head = head->next;
		free(p);
	}
}

void print_link(NodePtr head){
	NodePtr p = head->next;
	while(p){
		printf("%d,", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	NodePtr head1 = new Node;
	head1->next = NULL;
	for (int i = 0;i < 10;i ++){
		NodePtr node = new Node;
		node->data = i;
		node->next = head1->next;
		head1->next = node;
	} 
	NodePtr head2 = new Node;
	head2->next = NULL;
	for (int i = 5;i < 15;i ++){
		NodePtr node = new Node;
		node->data = i;
		node->next = head2->next;
		head2->next = node;
	}
	printf("link1:\n");
	print_link(head1);
	printf("link2:\n");
	print_link(head2);
	NodePtr head = merge_ordered_link(head1, head2);
	printf("merge:\n");
	print_link(head);
	free_link(head);
	return 0;
}