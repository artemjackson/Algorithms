#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;


int ** matrixAdjacency(ifstream &, int, int );
void showMatrix(int**, int , int);
bool isEulerianCycle(int**, int, int);
void findEulerianCycle(int**, int, int, int);

int main()
{
    int numVertex , numEdge;
    ifstream fin("example.txt");
    if(!fin)
    {
        cout<<"file is not open\n";
    }
    fin >> numVertex;
    fin >> numEdge;
    int** matrAdjacency = matrixAdjacency(fin, numVertex, numEdge);
    showMatrix(matrAdjacency, numVertex, numEdge);

    if(isEulerianCycle(matrAdjacency, numVertex, numEdge))
        cout << "Graph is eulerian\n";
    else
        cout << "Graph is not eulerian\n";

    int top;
    cout << "Enter vertex of cycle begining\n";
    cin >> top;



    //stack *cycle =
    findEulerianCycle(matrAdjacency, numVertex, numEdge, top-1);
    return 0;
}



int ** matrixAdjacency(ifstream & fin, int numVertex, int numEdge)
{
    int** arrAdjacency = new int*[numVertex];
    for(int i = 0; i < numVertex; i++)
        arrAdjacency[i] = new int[numEdge];
    for(int i = 0; i < numVertex; i++)
        for(int j = 0; j < numEdge; j++)
            fin >> arrAdjacency[i][j];
    return arrAdjacency;
}

void showMatrix(int**  matrAdjacency, int numVertex, int numEdge)
{
    for(int i = 0; i < numVertex; i++)
    {
        for(int j = 0; j < numEdge; j++)
            cout << matrAdjacency[i][j] <<" ";
        cout << endl;
    }
}

bool isEulerianCycle(int**  matrAdjacency, int numVertex, int numEdge)
{
    int degree = 0;
    for(int i = 0; i < numVertex; i++)
    {
        for(int j = 0; j < numEdge; j++)
        {
            if(matrAdjacency[i][j] == 1) degree++;
        }
        if(degree%2)
            return  false;
        else degree = 0;
    }
    return true;
}

void findEulerianCycle(int** matrAdjacency, int numVertex, int numEdge, int top)
{
    for(int i = 0; i < numVertex; i++)
    {
        for(int j = 0; j < numEdge; j++)
            cout << matrAdjacency[i][j] <<" ";
        cout << endl;
    }

    stack temp, end;
    temp.push(top);
    int* arrayOfEdge = new int[numEdge];
    for(int i = 0; i < numEdge; i++)
        arrayOfEdge[i] = 0;

    int vertex;

    while(temp.isNotEmpty())
    {
        vertex = temp.getElement();
        for(int j = 0; j < numEdge; j++)
        {
            if(matrAdjacency[vertex][j] == 1 && arrayOfEdge[j] == 0 )
            {
                for(int i = 0; i < numVertex; i++)
                    if(matrAdjacency[i][j]==1 && i != vertex)
                    {
                        arrayOfEdge[j] = 1;
                        temp.push(i);
                        break;
                    }

                break;
            }
            else if(j < numEdge-1)
                continue;

            else
            {
                int key = temp.getElement();
                temp.pop();
                end.push(key);
            }
        }
    }
    cout<<endl;
    end.showall();

}
