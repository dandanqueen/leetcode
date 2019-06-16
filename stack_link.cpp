#include <cstdio>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}Node, *NodeP;

class LinkStack{
public:
	LinkStack(){
		head = new Node;
		if(head == NULL){
			throw -1;
		}
		head->data = 0;
		head->next = NULL;
		count = 0;
	}
	~LinkStack(){
		while(head){
			NodeP tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	bool push(int num){
		NodeP tmp = new Node;
		if(tmp == NULL){
			return false;
		}
		tmp->data = num;
		tmp->next = head->next;
		head->next = tmp;
		count ++;
		return true;
	}
	int pop(){
		if(head->next == NULL){
			return 0;
		}
		NodeP tmp = head->next;
		head->next = tmp->next;
		int num = tmp->data;
		delete tmp;
		count --;
		return num;
	}
	int top(){
		if (head->next == NULL){
			return 0;
		}
		return head->next->data;
	}
private:
	NodeP head;
	int count;
};

int main(int argc, char const *argv[])
{
	LinkStack stack = LinkStack();
	for (int i = 0;i < 10;i ++){
		stack.push(i+1);
		printf("%d ", i+1);
	}
	printf("\n");
	while(stack.top()){
		int num = stack.pop();
		printf("%d ", num);
	}
	printf("\n");
	return 0;
}
