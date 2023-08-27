#include<iostream>
using namespace std;

template <typename T> class Node{
private:
	T data;
	Node<T>* next;

public:
	Node(){
		this->next = NULL;
	}

	Node(T data){
		this->data = data;
		this->next = NULL;
	}

	Node<T>* getNext(){
		return this->next;		
	}

	void setNext(Node<T>* node){
		this->next = node;
	}

	T getData(){
		return this->data;
	}
};

template <typename T> class CircularLinkedList{
private:
	Node<T> *tail;

public:
	CircularLinkedList(){
		this->tail = NULL;
	}

	void insertNode(T data){
		
		Node<T> *temp = new Node(data);
		if(tail == NULL){
			tail = temp;
			tail->setNext(temp);
			return;	
		}
		
		Node<T> *current = tail->getNext();
		/*
		while(current != tail){
			current = current->getNext();
		}
		current->setNext(temp);
		tail = temp;
		tail->setNext(temp->next);
		//delete temp;
		*/
		tail->setNext(temp);
		tail = temp;
		temp->setNext(current);
	}	
	void deleteNode(T data){
		
		if(tail == NULL)
			return;

		Node<T> *current = tail->getNext();
		Node<T> *previous = tail;
		
		while(current != tail){
			if(current->getData() == data){
				if(tail == tail->getNext()){
					tail = NULL;
				}
				else{
					previous->setNext(current->getNext());
					current->setNext(NULL);
				}
				return;
			}
			previous = current;
			current = current->getNext();
		}
		if(current == tail && tail->getData() == data){
			previous->setNext(tail->getNext());
			tail->setNext(NULL);
			tail = previous;
		}
	}

	bool search(T data){
		
		if(tail == NULL){
			return false;
		}

		Node<T> *current = tail->getNext();
		
		while(current != tail){
			if(current->getData() == data)
				return true;
			current = current->getNext();
		}
		if((current == tail) && (tail->getData() == data)){
			return true;
		}
		
		return false;
	}

	void print(){
		Node<T> *current = tail->getNext();
		int i = 0;
		while(i <= 2){
			while(current != tail){
				cout << current->getData() << " -> ";
				current = (current->getNext());	
			}
			cout << current->getData() << " --> " ;
			i++;
			current = current->getNext();
		}
		cout << endl;
	}

};

int main(){
	
	CircularLinkedList<int> list;
	
	list.insertNode(1);
	list.insertNode(8);
	list.insertNode(0);
	list.insertNode(8);
	list.insertNode(2);
	/*
	if(list.search(6))
		cout<<"present"<<endl;
	else
		cout<<"Not present"<<endl;
	*/
	
	list.print();
	list.deleteNode(1);	
	
	list.print();
	/*
	if(list.search(9))
		cout<<"present"<<endl;
	else
		cout<<"Not present"<<endl;

	list.deleteNode(8);	*/
	//list.print();
}
