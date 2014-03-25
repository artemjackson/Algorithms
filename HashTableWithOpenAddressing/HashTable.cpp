#include "HashTable.h"

#include <cstdlib>

HashTable::HashTable(int size):
    size(size),
    container(new Content*[size])
{
    for(int i=0; i<size; ++i)
        container[i] = 0;
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
    int k = 0;

    if(container[i] && k < size)
    {
        if(*container[i] == content)
            return true;
        else{
            i = possition(i);
            ++k;
        }
    }
    return false;
}

void HashTable::insert(std::string string){
    //show();
    //system("sleep 0.5");

    int key = hashFunction(string);

    Content *content = new Content(key,string);

    int i = key % size;

    while(container[i])
        i = possition(i);

    container[i] = content;

}

void HashTable::remove(std::string string){
    int key = hashFunction(string);

    Content content(key,string);

    int i = key % size;
    int k = 0;

    if(container[i] && k < size)
    {
        if(*container[i] == content)
        {
            delete container[i];
            container[i] = 0;
            return;
        }
        else{
            i = possition(i);
            ++k;
        }
    }
}


void HashTable::clear(){
    for(int i=0; i<size; ++i)
    {
        delete container[i];
        container[i] = 0;
    }
}

void HashTable::show(){
    system("clear");
    for(int i=0; i<size; ++i){
        std::cout<<i<<". ";
        if(container[i])
            std::cout<<*container[i];
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int HashTable::hashFunction(std::string string){
    int key = 0;

    for(int i = 0; string[i] != '\0'; ++i)
        key+=string[i];
    return key;
}

int HashTable::possition(int i){
    return (++i%size);
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
    return this->string == right.string;
}

std::ostream &operator<<(std::ostream &output, const Content &content){
    output<<"["<<content.string<<" | "<<content.key<<"]";
    return output;
}
