#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

template <typename T>
class List {
public:
    List();
    ~List();
    bool find(T content);
    void insert(T content);
    void remove(T content);
    void clear();
    void show();

private:
    struct Node {
        Node();
        Node(T content);
        ~Node();
        Node *next;
        T content;
    }*begin;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

template <typename T>
List<T>::List():
    begin(0) {
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
bool List<T>::find(T content) {
    Node *current = begin;
    while(current != 0) {
        if(current->content == content) return true;
        current = current->next;
    }
    return false;
}

template <typename T>
void List<T>::insert(T content) {
    Node *node = new Node;
    node->content = content;

    if(begin) {
        Node *current = begin;
        while(current != 0) {
            if (current->next != 0 && current->content <= content)
                current = current->next;
            else {
                    if(current ==  begin &&  content <= current->content){
                        node->next = begin;
                        begin = node;
                    }else
                    {
                        Node *temp;
                        temp = current->next;
                        node->next = temp;
                        current->next=node;
                    }
                current = 0;
            }
        }
    } else begin = node;
}

template <typename T>
void List<T>::remove(T content) {
    Node *previous = 0, *current = begin;

    while(current != 0){
        if(current->content == content)
        {
            if(previous){
                previous->next = current->next;
                delete current;
                current = 0;
            }
            else{
                current = current->next;
                delete begin;
                begin = current;
            }
        }
        else{
            previous = current;
            current = current->next;
        }
    }
}

template <typename T>
void List<T>::clear() {
    Node *current = begin;
    while(begin){
        current = current->next;
        delete begin;
        begin = current;
    }
}

template <typename T>
void List<T>::show() {
    Node *current = begin;
    while(current != 0) {
        std::cout<<current->content<<" ";
        current = current->next;
    }
    std::cout<<"\n";
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

template <typename T>
List<T>::Node::Node():
    next(0) {
}

template <typename T>
List<T>::Node::Node(T content):
    content(content),
    next(0) {
}

template <typename T>
List<T>::Node::~Node() {
    next = 0;
}

#endif // LIST_H_INCLUDED
