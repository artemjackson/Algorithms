#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "List.h"
#include <cstring>


class Content {
public:
    Content(){};
    ~Content(){};
    Content(int key, std::string string );
    bool operator<=(const Content &right);
    bool operator==(const Content &right);
    friend std::ostream &operator<<(std::ostream &output, const Content &content);
private:
    int key;
    std::string string;
};

class HashTable {
public:
    HashTable(int size);
    ~HashTable();
    bool find(std::string string);
    void insert(std::string string);
    void remove(std::string string);
    void clear();
    void show();
private:

    bool find(Content content);
    void insert(Content content);
    void remove(Content content);

    int size;
    List<Content> *container;
    int hashFunction(std::string string);
};
#endif // HASHTABLE_H_INCLUDED
