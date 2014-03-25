

struct node {
	int data;
	node* next; 
};

class stack {
	private:
		node* top;
	public:
		stack();
		void push(int);
		void pop();
		void showall();
		int getElement();
		bool isNotEmpty();
};



