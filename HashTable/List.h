#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


template <typename T>
class List{
public:
    List();
    ~List();
    bool find(T content);
    void insert(T content);
    void remove(T content);
    void clear();
    void show();

private:
    struct Node{
        Node();
        Node(T content);
        ~Node();
        Node *next;
        T *content;
    }*begin;

    Node* search(T content);
};

#endif // LIST_H_INCLUDED
