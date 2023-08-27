#include<iostream>
using namespace std;

template <typename T> class Node{
private:
	T data;
	Node<T>* next;
	Node<T>* previous;

public:
	Node(){
		this->next = NULL;
		this->previous = NULL;
	}

	Node(T data){
		this->data = data;
		this->next = NULL;
		this->previous = NULL;
	}

	Node<T>* getNext(){
		return this->next;		
	}

	void setNext(Node<T>* node){
		this->next = node;
	}

	Node<T>* getPrevious(){
		return this->previous;		
	}

	void setPrevious(Node<T>* node){
		this->previous = node;
	}

	T getData(){
		return this->data;
	}
};

template <typename T> class DoublyLinkedList{
private:
	Node<T> *head;

public:
	DoublyLinkedList(){
		this->head = NULL;
	}

	void insertNode(T data){
		Node<T> *current = head;
		Node<T> *temp = new Node(data);
		if(head == NULL){
			head = temp;
			return;	
		}
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		current->setNext(temp);
		temp->setPrevious(current);
	}	
	void deleteNode(T data){
		Node<T> *current = head;

		while(current != NULL){
			if(current->getData() == data){
				if(current->getPrevious() == NULL){
					head = current->getNext();
					head->setPrevious(NULL);
				}
				else if(current->getNext() == NULL){
					current->getPrevious()->setNext(NULL);
					current->setPrevious(NULL);
				}
				else{
					current->getPrevious()->setNext(current->getNext());
					current->getNext()->setPrevious(current->getPrevious());
					current->setPrevious(NULL);
				}

				// if current node has a next
				if(current->getNext())
					current->setNext(NULL);	
			}
			current = current->getNext();
		}
	}

	bool search(T data){
		Node<T> *current = head;
		while(current != NULL){
			if(current->getData() == data)
				return true;
			current = current->getNext();
		}
		return false;
	}

	void print(){
		Node<T> *current = head;
		while(current->getNext() != NULL){
			cout << current->getData() << " -> ";
			current = (current->getNext());
		}
		cout << current->getData() << endl;

		cout<<"Reverse -> "<<endl;
		while(current->getPrevious() != NULL){
			cout << current->getData() << " -> ";
			current = (current->getPrevious());
		}
		cout << current->getData() << endl;

	}

};

int main(){
	
	DoublyLinkedList<int> list;
	
	list.insertNode(1);
	list.insertNode(8);
	list.insertNode(0);
	list.insertNode(8);
	list.insertNode(2);
	/*
	if(list.search(9))
		cout<<"present"<<endl;
	else
		cout<<"Not present"<<endl;

	list.deleteNode(2);	
	*/
	list.print();
	
	if(list.search(9))
		cout<<"present"<<endl;
	else
		cout<<"Not present"<<endl;

	list.deleteNode(8);	
	list.print();
}
