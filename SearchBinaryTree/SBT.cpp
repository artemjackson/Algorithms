#include "SBT.h"

SBT::Node::Node(T data):
    left(0),
    right(0),
    data(data) {
}

SBT::Node::~Node() {
    left = 0;
    right = 0;
    data = 0;
}

SBT::SBT():
    root(0) {
}


SBT::~SBT() {
    clear();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

bool SBT::findNode(T key) {
    Node *current = root;
    while(current != 0) {
        if(key == current->data)
            return true;
        else
            current = key < current->data ?
                      current->left : current->right;
    }
    return false;
}

void SBT::insertNode(T data) {
    Node *node = new Node(data);
    insertNode(node);
}

void SBT::insertNode(Node *node) {
    Node *current, *parent;
    current = root;
    parent = 0;

    while(current !=0) {
        if(node->data == current->data) return;
        parent = current;
        current = node->data < current->data ?
                  current->left : current->right;
    }

    if(parent) {
        if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
    } else {
        root = node;
    }
}

void SBT::insertNodeToRoot(T data) {

    if(!findNode(data)) {
        //int i;
        //std::cout<<"\nInsertion value "<<data<<" to root: press any key while node doesn't come to root\n";

        Node* node = new Node(data);

        insertNode(node);

        while(root->left != node && root->right != node ) {

            system("sleep 0.5");
           // std::cin>>i;
            show();
            insertFixup(node);
        }

        show();
       // std::cin>>i;
       // show();

        if(root->left == node) {
            Node* q = root->left;

            if( root->left )
                root->left = q->right;
            q->right = root;
            root = q;

        } else {
            Node* p = root->right;
            root->right = p->left;
            p->left = root;

            root = p;
        }
    }
}

void SBT::insertFixup(Node *node) {
    Node *parent = findParent(node);


    if(parent->left == node)

        rotateRight(parent);
    else
        rotateLeft(parent);
}

SBT::Node* SBT::findParent(Node* node) {
    if(node == root) return 0;

    Node *current = root;
    while(current->left != node && current->right != node)
        current = node->data < current->data ? current->left: current->right;
    return current;
}


void SBT::rotateRight(Node *p) { // правый поворот вокруг узла p
    Node* q = p->left;

    if( p->left )
        p->left = q->right;
    q->right = p;


    Node *parent = findParent(p);
    if(parent->left == p)
        parent->left = q;
    else
        parent->right = q;
}



void SBT::rotateLeft(Node *q) { // левый поворот вокруг узла q
    Node* p = q->right;
    q->right = p->left;
    p->left = q;

    Node *parent = findParent(q);
    if(parent->left == q)
        parent->left = p;
    else
        parent->right = p;

}

void SBT::deleteNode(T key) {
    Node *current, *parent, *x;
    current = root;
    parent = 0;

    while(current != 0) {
        if(key == current->data)
            break;
        else {
            parent = current;
            current = key < current->data ?
                      current->left : current->right;
        }
    }

    if(current) {
        if (current->left == 0 || current->right == 0) {
            x = current->left != 0 ?
                current->left : current->right;

            if(current == root) {
                delete root;
                root = x;
            } else {
                if(parent->left == current)
                    parent->left = x;
                else parent->right = x;

                delete current;
                current = 0;
            }
        } else {
            x = current->right;

            while(x->left != 0)
                x = x->left;

            T data = x->data;

            deleteNode(x->data);

            current->data = data;
        }
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::show() {
    system("clear");
    if(root)
        inOrder(root, consoleOutput);
    else
        std::cout<<"Tree is empty\n";
}

void SBT::clear() {
    if(root)
        postOrder(root,remove);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::inOrder(Node *node, void (*function)(Node *node, int level), int level) {
    if (node->right != 0) {
        inOrder(node->right, function, level+1);
    }
    function(node,level);
    if (node->left != 0) {
        inOrder(node->left, function, level+1);
    }
}

void SBT::postOrder(Node *node, void (*function)(Node *node)) {
    if (node->left != 0) postOrder(node->left, function);
    if (node->right != 0) postOrder(node->right, function);
    function(node);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::consoleOutput(Node *node, int level) {
    for(int i=0; i<level; ++i )
        std::cout<<"   ";
    std::cout<<node->data<<"\n";
}

void SBT::remove(Node *node) {
    delete node;
    node =0;
}
