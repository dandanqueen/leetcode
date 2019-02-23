#include <cstdio>
#include <cstdlib>


using namespace std;


typedef struct node
{
	int data;
	struct node *next;
}Node, *NodePtr;


NodePtr find_link_midpoint(NodePtr head){
	if(head->next == NULL){
		return NULL;
	}
	NodePtr p1, p2;
	p1 = p2 = head->next;
	while(p1->next && p2->next){
		if(p1->next->next == NULL){
			break;
		}
		p1 = p1->next->next;
		p2 = p2->next;
	}
	return p2;
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
	printf("link:\n");
	print_link(head);
	NodePtr p = find_link_midpoint(head);
	printf("midpoint:%d\n", p->data);
	free_link(head);
	return 0;
}