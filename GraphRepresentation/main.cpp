#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int key;
    node* next;
};

int** matrixAdjacency(ifstream &, int);
node** listAdjacency(ifstream &, int );
int ** matrixIncidence(ifstream &, int, int );

int main()
{
    int numVertex = 0;
    ifstream fin("example.txt");
    if(!fin)
    {
        cout<<"Ошибка! Невозможно открыть файл!\n";
        return 1;
    }

    fin >> numVertex;

    /*  Матрица смежности */


    int** matrAdjacency = matrixAdjacency(fin, numVertex);

    for(int i=0; i<numVertex; ++i)
    {
        for(int j=0; j<numVertex; ++j)
            cout<<matrAdjacency[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    /*  Cписок смежности */

    fin.clear();
    fin.seekg(4, ios_base::beg);

    node** listAdjacen = listAdjacency(fin, numVertex);

    int x=0;
    while(x < numVertex)
    {
        if(listAdjacen[x] == 0)
        {
            cout << endl;
            x++;
        }
        else
        {
            node* temp = listAdjacen[x];
            while(temp)
            {
                cout << temp->key << " ";
                temp = temp->next;
            }
            cout << endl;
            x++;
        }
    }

    fin.clear();
    fin.seekg(0, ios_base::beg);

    int numEdge = 0;
    int z,y;
    fin >> z;
    numVertex = z;

    while(!fin.eof())
    {
        fin >> z >> y;
        numEdge++;
    }

    fin.clear();
    fin.seekg(4, ios_base::beg);

    /*  Матрица инцедентности */

    int** matrIncidence = matrixIncidence(fin, numVertex, numEdge);
    cout << endl;

    for(int i = 0; i < numVertex; i++)
    {
        for(int j = 0; j < numEdge; j++)
            cout << matrIncidence[i][j] << " ";
        cout << endl;
    }
}

int	** matrixAdjacency(ifstream &fin, int numVertex)
{
    int i,j;

    int** arrSmezn=new int*[numVertex];
    for(int i=0; i<numVertex; i++)
        arrSmezn[i]=new int[numVertex];
    for(int i=0; i<numVertex; i++)
        for(int j=0; j<numVertex; j++)
            arrSmezn[i][j]=0;
    while(!fin.eof())
    {
        fin>>i;
        fin>>j;
        arrSmezn[i-1][j-1]=1;
        arrSmezn[j-1][i-1]=1;
    }

    return arrSmezn;
}

node** listAdjacency(ifstream & fin, int numVertex)
{
    node ** listAdjacen = new node*[numVertex];
    for(int i = 0; i < numVertex; i++)
        listAdjacen[i] = new node;

    for(int i = 0; i < numVertex; i++)
        listAdjacen[i] = 0;

    while(!fin.eof())
    {
        int a, b;
        fin>>a;
        fin>>b;

        if(listAdjacen[a-1] == 0)
        {
            node* temp = new node;
            listAdjacen[a-1] = temp;
            listAdjacen[a-1]->key = b;
            listAdjacen[a-1]->next = 0;
        }
        else
        {
            node* temp = listAdjacen[a-1];
            while(temp->next)
            {
                temp = temp->next;
            }
            node* point = new node;
            temp->next = point;
            temp->next->key = b;
            temp->next->next = 0;
        }

        if(listAdjacen[b-1] == 0)
        {
            node* temp = new node;
            listAdjacen[b-1] = temp;
            listAdjacen[b-1]->key = a;
            listAdjacen[b-1]->next = 0;
        }
        else
        {
            node* temp=listAdjacen[b-1];
            while(temp->next)
            {
                temp = temp->next;
            }
            node* point = new node;
            temp->next = point;
            temp->next->key = a;
            temp->next->next = 0;
        }
    }
    return listAdjacen;
}

int ** matrixIncidence(ifstream & fin, int numVertex, int numEdge)
{

    int ** matrIncidence = new int* [numVertex];
    for(int i = 0; i < numVertex; i++)
        matrIncidence[i] = new int[numEdge];
    for(int i = 0; i < numVertex; i++)
        for(int j = 0; j < numEdge; j++)
            matrIncidence[i][j] = 0;
    int z, y, k = 0;
    while(!fin.eof())
    {
        fin >> z >> y ;
        matrIncidence[z-1][k] = 1;
        matrIncidence[y-1][k] = 1;
        k++;
    }

    return matrIncidence;
}
