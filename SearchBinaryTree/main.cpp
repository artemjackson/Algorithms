#include <iostream>
#include "SBT.h"


using namespace std;

int main() {
    srand(time(NULL));
    SBT tree;
   // int i;



    for(int i=0; i<10; ++i)
    tree.insertNode(-rand()%100);

    for(int i=0; i<10; ++i)
    tree.insertNode(rand()%100);

    tree.show();
    //std::cin>>i;

    tree.deleteNode(10);
    tree.show();
    //std::cin>>i;

    for(int i=0; i<10; ++i)
    tree.insertNodeToRoot(rand()%100-50);

    //    for(int i=0; i<4; ++i)
        /*
        tree.insertNode(100);
        tree.insertNode(200);
        tree.insertNode(300);
        tree.insertNode(150);
        tree.insertNode(250);
        tree.insertNode(50);
        tree.insertNode(0);
        tree.insertNode(75);
        tree.show();

        tree.insertNodeToRoot(175);
        */

    tree.show();

    return 0;
}
