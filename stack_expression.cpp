#include <cstdio>
#include <cstring>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}Node, *NodeP;

typedef class LinkStack{
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
			throw -1;
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
			throw -1;
		}
		return head->next->data;
	}
	int countt(){
		return count;
	}
private:
	NodeP head;
	int count;
}Stack;

int calculate(char op, int numl, int numr){
	if (op == '+') return numl + numr;
	else if (op == '-') return numl - numr;
	else if (op == '*') return numl * numr;
	else if (op == '/') return numl / numr;
	else throw -1;
}

int expression(const char *str){
	if (str == NULL) throw -1;
	int leng = strlen(str);
	if (leng == 0) throw -1;
	Stack stack_op = Stack();
	Stack stack_num = Stack();
	char stop[3][4] = {{'('},{'+', '-', '('},{'('}};
	int op, num, numr, numl;
	for(int stop_idx, i = 0;i < leng;i ++){
		stop_idx = -1;
		if(48 <= str[i] && str[i] <= 57) stack_num.push(str[i]-48);
		else if(str[i] == '(') stack_op.push(str[i]);
		else if(str[i] == '+' || str[i] == '-') stop_idx = 0;
		else if(str[i] == '*' || str[i] == '/') stop_idx = 1;
		else if(str[i] == ')') stop_idx = 2;
		else throw -1;
		if (0 <= stop_idx && stop_idx <= 2){
			bool find;
			while(stack_op.countt()){
				op = stack_op.top();
				find = false;
				for (int j = 0;j < 4 && stop[stop_idx][j] && !find;j ++)
					if (op == stop[stop_idx][j]) find = true;
				if (find) break;
				stack_op.pop();
				if (stack_num.countt() < 2) throw -1;
				numr = stack_num.pop();
				numl = stack_num.pop();
				num = calculate(op, numl, numr);
				stack_num.push(num);
			}
			if (str[i] == ')' && op != '(') throw -1;
			if (str[i] != ')') stack_op.push(str[i]);
			else stack_op.pop();
		}
	}
	while(stack_op.countt()){
		if (stack_num.countt() < 2) throw -1;
		op = stack_op.pop();
		numr = stack_num.pop();
		numl = stack_num.pop();
		num = calculate(op, numl, numr);
		stack_num.push(num);
	}
	if (stack_num.countt() != 1) throw -1;
	num = stack_num.pop();
	return num;
}

int main(int argc, char const *argv[])
{
	char *str = "(4+2)";
	printf("%s=%d\n", str, expression(str));
	return 0;
}
