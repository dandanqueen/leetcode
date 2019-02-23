#include <cstdio>
#include <cstdlib>


using namespace std;


typedef struct node
{
	int data;
	struct node *next;
}Node, *NodePtr;


void del_link_tail_n(NodePtr head, int n){
	if(head->next == NULL || n <= 0){
		return;
	}
	NodePtr p1 = head->next;
	while(n && p1){
		p1 = p1->next;
		n--;
	}
	if(n){
		return;
	}
	NodePtr p2 = head;
	while(p1){
		p1 = p1->next;
		p2 = p2->next;
	}
	NodePtr p = p2->next;
	p2->next = p->next;
	free(p);
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
	NodePtr head = new Node;
	head->next = NULL;
	for (int i = 0;i < 10;i ++){
		NodePtr node = new Node;
		node->data = i;
		node->next = head->next;
		head->next = node;
	} 
	printf("before del\n");
	print_link(head);
	del_link_tail_n(head, 10);
	printf("after del\n");
	print_link(head);
	free_link(head);
	return 0;
}