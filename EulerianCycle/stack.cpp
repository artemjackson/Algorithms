#include<iostream>
#include"stack.h"
using namespace std;


stack::stack() {
	top = NULL;
}

void stack::push(int A) {
	if(top == 0) {
		node* temp = new node;
		temp->data = A;
		temp->next = 0;
		top = temp;
	}
	else {
		node* temp = new node;	
		temp->data = A;
		temp->next = top;
		top = temp;
	}
}

void stack::pop() {
	if(top == 0)return;
	else{
		node* temp = top->next;

		delete top;
		top = temp;
	}
}

void stack::showall() {
	node *s=top;
	while(s) {
		cout << s->data+1 << endl;
		s = s->next;	
	}
}

bool stack::isNotEmpty() {
	if(top) return true;
	else return false;
}

int stack::getElement() {
	if(top)
		return top->data;
	else 
		return -1;
}