#include<iostream>
#include "LinkedList.cpp"
using namespace std;

template <typename T> class Stack{
private:
	LinkedList<T> stack;
public:
	Stack(){
		//stack = new LinkedList<T>();
	}

	void push(T data){
		// insert node at head 
		stack.insertNodeAtIndex(1,data);
	}

	void pop(){
		if(stack.isEmpty()){
			cout << "stack is empty!!" << endl;
			return;
		}
		stack.deleteNode(stack.getHead()->getData());
	}

	bool isEmpty(){
		return stack.isEmpty();
	}

	T top(){
		if(stack.isEmpty()){
			return -1;
		}
		return stack.getHead()->getData();
	}
};

int main(){
	Stack<int> st;
	st.push(1);
	st.push(2);
	cout << st.top() << endl;
	st.pop();

	st.pop();

	st.pop();

	cout << st.top() << endl;
	return 0;
}
