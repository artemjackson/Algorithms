#include<iostream>
#include<fstream>

using namespace std;

struct Vertex {
	int color;
	int timeBegin;
	int timeEnd;
};

int** matrixAdjacency(ifstream &, int);
Vertex* depthFirstSearch(int**, int, int );
void visit(int**, Vertex*, int, int&, int);

int main() {
	ifstream fin("example.txt");
	if(!fin){
		cout<<"Ошибка! невозможно открыть файл!\n";
		return 1;
	}
	int numVertex;
	fin >> numVertex;

	int** matrAdjacency = matrixAdjacency(fin, numVertex);

	for(int i=0;i<numVertex;i++){
		for(int j=0;j<numVertex;j++)
			cout<<matrAdjacency[i][j]<<" ";
		cout<<endl;
	}
	int top;
	cout << "Введите стартовую вершину: ";
	cin >>top;
	Vertex* arrayOfVertex = depthFirstSearch(matrAdjacency, numVertex, --top);

    cout<<"Вершина помечена   Время начала   Время конца\n";
	for(int i = 0; i < numVertex; i++) {
	    cout<<i+1<<".";
		arrayOfVertex[i].color == 1 ? cout<<" true" : cout<<" false";cout<<"              ";
		cout << arrayOfVertex[i].timeBegin<<"             ";
		cout << arrayOfVertex[i].timeEnd<<endl;
	}
}

int** matrixAdjacency(ifstream &fin, int numVertex) {
	int i,j;

	int** arrSmezn=new int*[numVertex];
	for(int i=0;i<numVertex;i++)
		arrSmezn[i]=new int[numVertex];
	for(int i=0;i<numVertex;i++)
		for(int j=0;j<numVertex;j++)
			arrSmezn[i][j]=0;
	while(!fin.eof()){
		fin>>i;  fin>>j;
		arrSmezn[i-1][j-1]=1;
		arrSmezn[j-1][i-1]=1;
	}
	return arrSmezn;
}

Vertex* depthFirstSearch(int** matrAdjacency, int numVertex, int top) {
	Vertex* arrayOfVertex = new Vertex[numVertex];
	for(int i = 0; i < numVertex; i++) {
		arrayOfVertex[i].color = -1;
		arrayOfVertex[i].timeBegin = 0;
		arrayOfVertex[i].timeEnd = 0;
	}
	int time = 1;
	arrayOfVertex[top].color = 0;
	arrayOfVertex[top].timeBegin = time;
	for(int j = 0; j < numVertex; j++) {
		if(arrayOfVertex[j].color == -1 && matrAdjacency[top][j]  == 1)
			visit(matrAdjacency, arrayOfVertex, j, time, numVertex);
	}
	time++;
	arrayOfVertex[top].color = 1;
	arrayOfVertex[top].timeEnd = time;

	return arrayOfVertex;
}

void visit(int** matrAdjacency, Vertex* arrayOfVertex, int i, int& time, int numVertex) {
	arrayOfVertex[i].color = 0;
	time++;
	arrayOfVertex[i].timeBegin = time;
	for(int j = 0; j < numVertex; j++) {
		if(arrayOfVertex[j].color == -1 && matrAdjacency[i][j] == 1)
			visit(matrAdjacency, arrayOfVertex, j, time, numVertex);
	}
	arrayOfVertex[i].color = 1;
	time++;
	arrayOfVertex[i].timeEnd = time;
}
