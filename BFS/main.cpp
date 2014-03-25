#include<iostream>
#include<fstream>
#include"queue.h"

using namespace std;

int** matrixAdjacency(ifstream &, int);

int** breadthFirstSearch(int**, int, int);

bool isConnected(int**, int);
bool isBipartite(int**, int);

int main()
{
    ifstream fin("example.txt");
    if(!fin)
    {
        cout<<"Ошибка! Невозможно открыть файл!\n";
        return 1;
    }

    int numVertex;
    fin >> numVertex;

    int ** matrAdjacency = matrixAdjacency(fin, numVertex);

    for(int i=0; i<numVertex; i++)
    {
        for(int j=0; j<numVertex; j++)
            cout<<matrAdjacency[i][j]<<" ";
        cout<<endl;
    }

    fin.close();

    int n;
    cout<<"\nВведите стартовую вершину:\n";
    cin>>n;

    if(!isConnected(matrAdjacency, numVertex))
        cout<<"\nГраф несвязанный!\n";
    else
        cout<<"\nГраф связанный!\n";

    if(isBipartite(matrAdjacency, numVertex))
        cout<<"\nГраф двудольный!\n";
    else
        cout<<"\nГраф не является двудольным!\n";
}


int** matrixAdjacency(ifstream &fin, int numVertex)
{
    int i,j;

    int** arrAdjacency=new int*[numVertex];
    for(int i=0; i<numVertex; i++)
        arrAdjacency[i]=new int[numVertex];
    for(int i=0; i<numVertex; i++)
        for(int j=0; j<numVertex; j++)
            arrAdjacency[i][j]=0;
    while(!fin.eof())
    {
        fin>>i;
        fin>>j;
        arrAdjacency[i-1][j-1]=1;
        arrAdjacency[j-1][i-1]=1;
    }
    return arrAdjacency;
}

int** breadthFirstSearch(int** matrAdjacency, int numVertex, int top)
{
    int ** arrNotes = new int* [2];
    for(int i = 0; i<2; i++)
        arrNotes[i] = new int[numVertex];
    for(int i = 0; i < numVertex; i++)
    {
        arrNotes[0][i] = -1;
        arrNotes[1][i] = 5;
    }

    queue a;
    arrNotes[1][top] = 0;
    a.push(top);
    while(a.isNotEmpty())
    {
        for(int j = 0; j < numVertex; j++)
        {
            if(matrAdjacency[top][j] == 1 && j!= top && arrNotes[0][j]!=1)
            {

                a.push(j);
                if(arrNotes[1][j] > arrNotes[1][top]+1)
                    arrNotes[1][j] = arrNotes[1][top]+1;
            }
        }
        arrNotes[0][top] = 1;
        top = a.get();
    }
    return arrNotes;
}

bool isConnected(int** matrAdjacency, int numVertex)
{
    int top = 1;
    int** arrNotes = breadthFirstSearch(matrAdjacency, numVertex, top);
    for(int i = 0; i < numVertex; i++)
    {
        if(arrNotes[0][i] != 1) return false;
    }
    return true;
}

bool isBipartite(int** matrAdjacency, int numVertex)
{
    int top = 1;
    int** arrNotes = breadthFirstSearch(matrAdjacency, numVertex, top);
    for(int i = 0; i < numVertex; i++)
        for(int j = 0; j < numVertex; j++)
        {
            if(matrAdjacency[i][j] == 1 && (arrNotes[1][i]%2 == arrNotes[1][j]%2))
                return false;
        }
    return true;
}
