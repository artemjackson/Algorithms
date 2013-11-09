#include "HashTable.h"
#include <cstdlib>

HashTable::HashTable(int size):
    size(size),
    container(new List<Content>[size])
{
}
HashTable::~HashTable(){
    clear();
    delete []container;
    container = 0;
    size = 0;
}

bool HashTable::find(std::string string){
    int key = hashFunction(string);

    Content content(key,string);

    int i = key % size;
    return container[i].find(content);
}

void HashTable::insert(std::string string){
    show();
    system("sleep 1");

    int key = hashFunction(string);

    Content content(key,string);

    int i = key % size;

    container[i].insert(content);

    show();
}

void HashTable::remove(std::string string){
    int key = hashFunction(string);

    Content content(key, string);

    int i = key % size;
    container[i].remove(content);
}

void HashTable::clear(){
    for(int i=0; i<size; ++i)
    container[i].clear();
}

void HashTable::show(){
    system("clear");
    for(int i=0; i<size; ++i){
        std::cout<<i<<". "; container[i].show();
    }
    std::cout<<"\n";
}

int HashTable::hashFunction(std::string string){
    int key = 0;

    for(int i = 0; string[i] != '\0'; ++i)
        key+=string[i];
    return key;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

Content::Content(int key,std::string string):
    key(key),
    string(string)
    {

    }

bool Content::operator<=(const Content &right){
    return this->key <= right.key;
}


bool Content::operator==(const Content &right){
    return this->key == right.key;
}

std::ostream &operator<<(std::ostream &output, const Content &content){
    output<<"["<<content.string<<" | "<<content.key<<"]";
    return output;
}
