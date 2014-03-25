/*
 * This programm is an example of finding skeleton of graph by using Kruskal Algorithm
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Edge
{
    int beg;
    int end;
    int weight;
};

int comparisonByWight(Edge x, Edge y)
{
    return x.weight<y.weight;
};

using namespace std;

int main()
{
    fstream fin;
    fin.open("input.txt");

    if(!fin)
    {
        cerr<<"Can not to open the file!\n";
        exit(1);
    }

    unsigned int numOfVertex;
    fin>>numOfVertex;

    vector <int> components(numOfVertex);       /* Components of connectability of graph */
    for(unsigned int i=0; i<numOfVertex; ++i)
        components[i] = i;                      /* At the biginning the graph is empty graph & all vertices are components */

    vector <Edge> edges;
    int i,j,w;
    fin>>i;
    --i;                                        /* because it's more conveniently to count from 0 */
    fin>>j;
    --j;
    fin>>w;

    while(!fin.eof())
    {
        Edge temp = {i,j,w};

        edges.push_back(temp);

        fin>>i;
        --i;
        fin>>j;
        --j;
        fin>>w;
    }
    fin.close();                                /* Because we are good boys :) */

    sort (edges.begin(), edges.end(), comparisonByWight);

    vector <Edge> skeleton;

    while(skeleton.size() != numOfVertex-1)     /* Because skeleton is also a tree & tree always has n-1 edges */
        for(unsigned int i = 0; i<edges.size(); ++i)
        {
            Edge current = edges[i];

            if(components[current.beg] != components[current.end])      /* If current edge don't create a cycle */
            {
                skeleton.push_back(current);                            /* add them to skeleton */
                int currentComponet = components[current.end];
                for(unsigned int j = 0; j<components.size(); ++j)
                    if(components[j] == currentComponet)               /* Addition new edges to components of connectability */
                        components[j] = components[current.beg];
            }
        }

    int totalWeight = 0;
    for(unsigned int i = 0; i<skeleton.size(); ++i)
        totalWeight+=skeleton[i].weight;


    cout<<"Skeleton is:\n\n";
    for(unsigned int i = 0; i<skeleton.size(); ++i)
        cout<<skeleton[i].beg+1<<"-"<<skeleton[i].end+1<<": "<<skeleton[i].weight<<"\n";

    cout<<"\nWeight of skeleton is: "<<totalWeight<<"\n";

    return 0;
}
