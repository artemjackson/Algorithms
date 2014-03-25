#ifndef KRUSKALALGORITHM_H_INCLUDED
#define KRUSKALALGORITHM_H_INCLUDED
#include <algorithm>

template<typename T>
struct Edge{
    int begin;
    int end;
    T weight;
};

template<typename T>
void KruskalAlgorithm(T **&martixOfAdjacenty, int numOfVertex, int numOfEdges){
    Edge<T> *edges = new Edge<T> [numOfEdges];

    for(int i=0; i<numOfVertex; ++i)
        for(int j=0; j<numOfVertex; ++j)
            if(martixOfAdjacenty[i][j])
            {
                Edge.weight = [];
                Edge.begin = [];
                Edge.end = [];
            }
}

#endif // KRUSKALALGORITHM_H_INCLUDED
