#include <cstdio>
#include <cstdlib>


using namespace std;


typedef struct node
{
	int data;
	struct node *next;
}Node, *NodePtr;


void reverse_link(NodePtr head){
	if(head->next == NULL){
		return;
	}
	NodePtr last = NULL;
	NodePtr cur = head->next;
	while(cur){
		NodePtr next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}
	head->next = last;
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
	printf("before reverse\n");
	print_link(head);
	reverse_link(head);
	printf("after reverse\n");
	print_link(head);
	free_link(head);
	return 0;
}