#include <iostream>
#include "HashTable.h"
#include <cstdlib>

using namespace std;

int main()
{

    HashTable table(10);
    table.insert("Lena");
    table.insert("Olya");
    table.insert("Nadya");
    table.insert("Kolya");
    table.insert("Lena");
    table.insert("Olya");
    table.insert("Nadya");
    table.insert("Kolya");
    table.show();
   // std::cout<<table.find("Kolya");
    system("sleep 10");
    table.remove("Nadya");
    table.show();
}
