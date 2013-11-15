#include <iostream>
#include "SBT.h"


using namespace std;

int main() {
    srand(time(NULL));
    SBT tree;
    int i;

    for(int i=0; i<20; ++i)
    tree.insertNode(i*10);

   // for(int i=0; i<20; ++i)
    //tree.insertNode(-i*10);

    tree.show();
    std::cin>>i;

    //tree.deleteNode(10);
    tree.show();
    //std::cin>>i;
 //tree.insertNode(12);
    for(int i=0; i<20; ++i)
   tree.insertNodeToRoot(rand()%101/*121-60*/);

    //    for(int i=0; i<4; ++i)
       /*
        tree.insertNode(100);
        tree.insertNode(200);
        tree.insertNode(300);
        tree.insertNode(150);
        tree.insertNode(250);
        tree.insertNode(50);

        //tree.insertNode(75);
   //     tree.show();

        tree.insertNodeToRoot(175);
        */

    tree.show();

    return 0;
}
