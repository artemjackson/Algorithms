/*
 * This programm is an example of finding shortest way in graph by using Dejikster Algorithm
 */

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

bool allMarked(vector<bool> v);
int min(vector<int> d, vector<bool> u);

int main()
{
    fstream fin;
    fin.open("input.txt");

    if(!fin)
    {
        cerr<<"Can not to open the file!\n";
        return -1;
    }

    int numOfVertex;
    fin>>numOfVertex;

    vector < vector <int> > matrixOfAdjencety(numOfVertex, vector <int>(numOfVertex));
    for(int i=0; i<numOfVertex; ++i)
        for(int j=0; j<numOfVertex; ++j)
            matrixOfAdjencety[i][j] = 0;

    int i,j,w;
    while(!fin.eof())
    {
        fin>>i;
        --i;
        fin>>j;
        --j;
        fin>>w;
        matrixOfAdjencety[i][j] = matrixOfAdjencety[j][i]= w ;
    }
    fin.close();            /* Because we are good boys :) */

    /* Preparations */

    vector <int> distances(numOfVertex);
    for(int i=0; i<numOfVertex; ++i)
        distances[i] = 0;

    vector <bool> used(numOfVertex);
    for(int i=0; i<numOfVertex; ++i)
        used[i] = false;

    vector <int> parents(numOfVertex);
    for(int i=0; i<numOfVertex; ++i)
        parents[i] = 0;

    int start, finish;
    cout<<"From which vertex to which do you want to go?\n";
    cin>>start;
    --start;
    cin>>finish;
    --finish;

    for(int j=0;  j<numOfVertex; ++j)
        if(matrixOfAdjencety[start][j])
        {
            distances[j] = matrixOfAdjencety[start][j];
            parents[j] = start;
        }
    used[start] = true;

    while(!allMarked(used))
    {
        int current = min(distances, used);
        for(int j=0;  j<numOfVertex; ++j)
        {
            if(matrixOfAdjencety[current][j])
            {
                if(distances[current] + matrixOfAdjencety[current][j] < distances[j] || distances[j] == 0)
                {
                    distances[j] = distances[current] + matrixOfAdjencety[current][j];
                    parents[j] = current;

                }
            }
        }
        used[current] = true;
    }

    stack<int> result;

    int current = finish;
    while(current != start)
    {
        result.push(current);
        current = parents[current];
    }

    cout<<"The shortest way is:\n";
    cout<<start+1;
    while(!result.empty())
    {
        cout<<"->";
        cout<<result.top()+1;
        result.pop();
    }
    cout<<"\nWith distance: "<<distances[finish];

    return 0;
}

bool allMarked(vector<bool> v)
{
    for(unsigned int i=0; i<v.size(); ++i)
        if(!v[i]) return false;
    return true;
}

int min(vector<int> d, vector<bool> u)
{
    int min = 0;

    while(!d[min] || u[min])
        min++;

    for(unsigned int i=0; i<d.size(); ++i)          /* Search min element exept zero */
    {
        if(!u[i] && d[i])
                d[min] > d[i] ? min = i : min = min;
    }
    return min;
}
