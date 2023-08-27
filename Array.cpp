#include<iostream>
using namespace std;

template <typename T> class Array{
private:
	int size;
	T* arr;

public:
	Array(int size){
		this->size = size;
		arr = new T[size];
	}
	
	void getArray(){
		for(int i=0; i<size; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	int getSize(){
		return size;
	}

	void addElement(int index, T data){
		if(index >= size || index < 0){
			cout << "index out of bounds!" << endl;
			return;
		}
		arr[index] = data;
	}
	
	void deleteElement(T data){
		int flag = 0;
		for(int i = 0;i < size;i++){
			if(arr[i] == data){
				int ind = i+1;
				while(ind < size){
					arr[i] = arr[ind];
					ind++;
					i++;
				}
				size--;
				flag = 1;
			}	
		}
		if(flag == 0){
			cout << "There is no such element in the array!" << endl;
		}
	}
	
	bool search(T data){
		for(int i=0; i<size; i++){
			if(arr[i] == data)
				return true;
		}
		return false;
	}

};

int main(){
	Array<float> a(3);
	a.addElement(0, 1.23);
	a.addElement(1, 3.54);
	a.addElement(2, 4.5);
	
	/*
	if(a.search(3))
		cout << "present" << endl;
	else
		cout << "Not present" << endl;
	*/

	a.getArray();
	cout << "Size of the Array: " << a.getSize() << endl;

	a.deleteElement(1.23);
	a.getArray();
	cout << "Size of the Array: " << a.getSize() << endl;
}
