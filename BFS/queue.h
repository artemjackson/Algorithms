#ifndef QUEUE_H
#define QUEUE_H

struct node {
	node* next;
	int key;
};

class queue {

		node* tail;
	public:
		node* head;
		queue();
		void push(int );
		bool isNotEmpty();
		int get();
};

#endif // QUEUE_H
