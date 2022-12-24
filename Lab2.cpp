#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node<T>* next;
};

template <typename T>
void init(Node <T>* &stack){
    stack = NULL;
}


template <typename T>
int isEmpty(Node <T>* stack){
    return stack==NULL;
}

template <typename T>
void push(Node <T>*& stack,  T value){
    if(isEmpty(stack)){
        stack = new Node <T>;
        stack->value=value;
        stack->next=NULL;
    }
    else{
        Node <T>* tmp = stack;
        stack = new Node <T>;
        stack->value = value;
        stack->next = tmp;
    }
    
}

template <typename T>
T pop(Node <T>* &stack){
    if(!isEmpty(stack)){
        T tmp = stack->value;
        Node <T> *item = stack->next;
        delete stack;
        stack=item;
        return tmp;
    }
    T temp;
    return temp;
}

int main()
{
    Node<string>* stack_first;
    Node<string>* stack_second;
    init(stack_first);
    init(stack_second);
    cout<<"Введіть кількість книжок: ";
	int n;
	cin>>n;
	string x;
	for(int i=0; i<n; i++){
        cin >> x;
        push(stack_first, x);
	}
	string *mas = new string[n];
	for(int i=0; i<n; i++){
	    mas[i]=pop(stack_first);
	}
	for (int i=0; i < n; i++) {
        for (int j=0; j < n-i-1; j++) {
            if (mas[j].length() > mas[j+1].length()){
                swap(mas[j], mas[j+1]);
            }
        }
    }
    cout<<"Сортований список: "<< endl;
    for(int i=0; i<n; i++){
	    cout<< mas[i] << " ";
	    push(stack_second, mas[i]);
	}
	delete[] mas;
    return 0;
}


