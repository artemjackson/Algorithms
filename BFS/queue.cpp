#include<iostream>
#include"queue.h"
using namespace std;

queue::queue()
{
	head=NULL;
	tail=NULL;
}

void queue::push(int a) {
	if(tail==0){
		node* temp=new node;
		temp->key=a;
		temp->next=0;
		tail=temp;
		head=temp;
	}
	else{
		node* temp=new node;
		temp->next=tail;
		temp->key=a;
		tail=temp;	
	}
}

int queue::get() {
	node *s = tail;

	if(tail == 0 && head == tail)
		return 0;
	if(tail == head){
		head = 0;
		tail = 0;	
		return s->key;
	}
	
	while(s->next!=head)
		s=s->next;	
	
	head=s;
	node *ret=s->next;
	s->next=0;

	return ret->key;
}

bool queue::isNotEmpty() {
	if (head == 0)
		return 0;
	else 
		return 1;
}