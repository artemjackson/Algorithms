#include "HashTable.h"
#include <cstdlib>

int main()
{
    HashTable table(5);
    table.insert("Lena");
    table.insert("Olya");
    table.insert("Nadya");
    table.insert("Kolya");
    table.insert("Semen");
    table.insert("Artem");
     table.insert("Vera");
    table.insert("Andrey");
    table.insert("Vitalik");
    table.insert("Lesha");
    table.insert("Anna");

    table.show();
    system("sleep 1.5");
    table.remove("Vera");
    table.show();

    return 0;
}
