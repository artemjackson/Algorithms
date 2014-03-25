#include<iostream>
#include<fstream>
using namespace std;

struct node {
	node* next;
	int edge;
	int weight;
};

node** listAdjacency(ifstream &, int );
int** createMatrixOfDistance(node**, int);
int** createMatrixOfVertex(int);
void showMatrix(int** ,int);
void showListAdjacency(node**, int);
void FloydAlgorithm(int** , int**, int);



int main() {
	int numVertex = 0;
	ifstream fin("matrix.txt");
	if(!fin){
		cout<<"file is not open\n";

	}
	fin >> numVertex;

	node** listAdjacen = listAdjacency(fin, numVertex);

	showListAdjacency(listAdjacen,numVertex);
	int** matrixOfDistance = createMatrixOfDistance(listAdjacen, numVertex);
	int** matrixOfVertex = createMatrixOfVertex(numVertex);
	cout << "\nMatrix"<<endl;
	showMatrix(matrixOfDistance, numVertex);
	cout << endl;

	cout << "\nInitial Matrix"<<endl;
	showMatrix(matrixOfVertex, numVertex);
	FloydAlgorithm(matrixOfDistance, matrixOfVertex, numVertex);

	cout << "\nMatrix of distance:"<<endl;
	showMatrix(matrixOfDistance, numVertex);

	cout << "\nMatrix of vertex:"<<endl;
	showMatrix(matrixOfVertex, numVertex);

	return 0;
}

void FloydAlgorithm(int** matrixOfDistance, int** matrixOfVertex, int numVertex) {
	for(int k = 0; k < numVertex; k++) {
		for(int i = 0; i < numVertex; i++)
			for(int j = 0; j < numVertex; j++) {
				if(i == k) i++;
				if(j == k) j++;
				if(j == i) j++;
				if(i >= numVertex || j >= numVertex || k >= numVertex) break;
				if(matrixOfDistance[k][j] == -1 || matrixOfDistance[i][k] == -1)
					continue;

				if ( (matrixOfDistance[i][j] > matrixOfDistance[k][j] + matrixOfDistance[i][k]) ||
					((matrixOfDistance[i][j] == -1) && (matrixOfDistance[k][j] != -1) && (matrixOfDistance[i][k] != -1)) ) {
					matrixOfDistance[i][j] = matrixOfDistance[k][j] + matrixOfDistance[i][k];
					matrixOfVertex[i][j] = matrixOfVertex[k][j];
				}
			}
	}
}


void showMatrix(int** matrix, int numVertex) {
	for(int i = 0; i < numVertex; i++) {
		for(int j = 0; j < numVertex; j++ ) {
			cout.width(3);
			matrix[i][j] == -1 ? cout << matrix[i][j]+1:cout << matrix[i][j];
		}
		cout << endl;
	}
}

int** createMatrixOfVertex(int numVertex) {
	int k = 1;
	int** matrixOfVertex = new int*[numVertex];
	for(int i = 0; i < numVertex; i++)
		matrixOfVertex[i] = new int[numVertex];

	for(int i = 0; i < numVertex; i++) {
		for(int j = 0; j < numVertex; j++) {
			matrixOfVertex[i][j] = k;
		}
		k++;
	}
	return matrixOfVertex;
}

int** createMatrixOfDistance(node** listAdjacen, int numVertex) {
	int** matrixOfDistance = new int*[numVertex];
	for(int i = 0; i < numVertex; i++)
		matrixOfDistance[i] = new int[numVertex];

	for(int i = 0; i < numVertex; i++)
		for(int j = 0; j < numVertex; j++) {
			matrixOfDistance[i][j] = -1;
		}


	for(int i = 0; i < numVertex; i++) {
		node* temp = listAdjacen[i];
		while(temp) {
			matrixOfDistance[i][temp->edge - 1] = temp->weight;
			temp = temp->next;
		}
	}
	return matrixOfDistance;
}

void showListAdjacency(node** listAdjacen, int numVertex) {
	cout << endl;
	int x=0;
	while(x < numVertex) {
		if(listAdjacen[x] == 0) {
			cout << endl;
			x++;
		}
		else {
			node* temp = listAdjacen[x];
			while(temp) {
				cout << temp->edge << ": " << temp->weight << "m" << " ";
				temp = temp->next;
			}
			cout << endl;
			x++;
		}
	}
}

node** listAdjacency(ifstream & fin, int numVertex) {
	node ** listAdjacen = new node*[numVertex];
	for(int i = 0; i < numVertex; i++)
		listAdjacen[i] = new node;

	for(int i = 0; i < numVertex; i++)
		listAdjacen[i] = 0;

	cout << "kol-vo vershin: " << numVertex << " ";
	while(!fin.eof()){
		int a, b, distance;
		fin >> a; fin >> b; fin >> distance;

		if(listAdjacen[a-1] == 0) {
			node* temp = new node;
			listAdjacen[a-1] = temp;
			listAdjacen[a-1]->edge = b;
			listAdjacen[a-1]->weight = distance;
			listAdjacen[a-1]->next = 0;
			}
		else {
			node* temp = listAdjacen[a-1];
			while(temp->next) {
				temp = temp->next;
			}
			node* point = new node;
			temp->next = point;
			temp->next->edge = b;
			temp->next->weight = distance;
			temp->next->next = 0;
		}

		if(listAdjacen[b-1] == 0) {
			node* temp = new node;
			listAdjacen[b-1] = temp;
			listAdjacen[b-1]->edge = a;
			listAdjacen[b-1]->weight = distance;
			listAdjacen[b-1]->next = 0;
			}
		else{
			node* temp=listAdjacen[b-1];
			while(temp->next){
				temp = temp->next;
			}
			node* point = new node;
			temp->next = point;
			temp->next->edge = a;
			temp->next->weight = distance;
			temp->next->next = 0;
		}
	}
	return listAdjacen;
}
