#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class ArrayStack {
public:
	ArrayStack(int n) {
		items = new int[n];
		size = n;
		count = 0;
	}
	~ArrayStack() {
		delete[] items;
	}
	bool push(int num){
		if (num <= 0){
			return false;
		}
		if (count == size){
			int *new_items = new int[size*2];
			if (new_items == NULL){
				return false;
			}
			memmove(new_items, items, sizeof(int)*size);
			delete items;
			items = new_items;
			size *= 2;
		}
		items[count++] = num;
		return true;
	}
	int pop() {
		if (count == 0){
			return 0;
		}
		return items[--count];
	}
	int get_size(){
		return size;
	}
	int get_count(){
		return count;
	}
private:
	int size;
	int count;
	int *items;
};

int main(int argc, char const *argv[])
{
	ArrayStack stack = ArrayStack(10);
	for (int i = 1;i <= 21;i ++){
		stack.push(i);
		printf("%d ", i);
	}
	printf("\nsize=%d", stack.get_size());
	printf("\ncount=%d\n", stack.get_count());
	while(stack.get_count()){
		printf("%d ", stack.pop());
	}
	printf("\n");
	return 0;
}