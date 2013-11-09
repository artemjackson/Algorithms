#include "HashTable.h"

int main()
{
    HashTable table(10);
    table.insert("Lena");
    table.insert("Olya");
    table.insert("Nadya");
    table.insert("Kolya");
    table.insert("Semen");
    table.insert("Artem");
    table.insert("Andrey");
    table.insert("Vitalik");
    table.insert("Lesha");
    table.insert("Annna");
    table.insert("Veranika");
    table.show();
    table.remove("Vera");
    table.show();

    return 0;
}
