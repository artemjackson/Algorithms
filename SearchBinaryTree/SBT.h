#ifndef SBT_H_INCLUDED
#define SBT_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SBT.h"

typedef int T;

class SBT {
public:
    SBT();
    ~SBT();
    bool findNode(T key);
    void insertNode(T data);
    void insertNodeToRoot(T data);
    void deleteNode(T key);
    void clear();
    void show();

private:
    struct Node {
        Node(T data = 0);
        ~Node();
        Node *left;
        Node *right;
        T data;
    }*root;

    void insertNode(Node* node);
    void insertFixup(Node *node);
    void rotateRight(Node *node);
    void rotateLeft(Node *node);

    Node* findParent(Node *node);

    static void postOrder(Node *node, void (*function)(Node *node));
    static void inOrder(Node *node, void (*function)(Node *node, int level), int level = 0);

    static void remove(Node *node);
    static void consoleOutput(Node *node, int level);
};

#endif // SBT_H_INCLUDED
