#include "List.h"

template <typename T>
List<T>::List():
    begin(0)
    {
    }

template <typename T>
List<T>::~List(){
    clear();
}
/*
template <typename T>
bool List<T>::find(T content){
    Node *current = begin;
    while(current != 0){
        if(current->content == content) return true;
        current = current->next;
    }
    return false;
}

template <typename T>
void List<T>::insert(T content)
{
    Node *current = begin;
    while(current != 0){
        if (current->content <= content)
            current = current->next;
        else
        {
            Node *node, *temp;
            temp = current->next;

            node = new Node;
            node->content = content;
            node->next = temp;

            current->next=node;

        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

template <typename T>
List<T>::Node::Node():
    content(0),
    next(0)
    {
    }

template <typename T>
List<T>::Node::Node(T content):
    content(content),
    next(0)
    {
    }

template <typename T>
List<T>::Node::~Node(){
    content = 0;
    next = 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
*/
