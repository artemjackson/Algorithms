#include<iostream>
#include<fstream>
#include <cstdlib>

using namespace std;

struct Edge {
	int weight;
	int point1;
	int point2;
	bool operator<(Edge a);
	bool operator>(Edge a);
};

int** matrixIncedence(ifstream&, int);
void showMatrix(int**, int);
Edge* createArrayOfEdges(int**, int, int&);
template <class X> void quickSort(X* ,int ,int);
template <class X> void swap(X &a, X &b);
Edge* Krascal(int**, Edge*, int, int);



int main() {
	int numVertex = 0;
	ifstream fin("matrix.txt");
	if(!fin) {
		cout << "file is not open\n";
	}
	fin >> numVertex;
	int** matrIncedence = matrixIncedence(fin, numVertex);
	cout<<"Matrix\n";
	showMatrix(matrIncedence, numVertex);
	cout << endl;

	int numOfEdges = 0;
	Edge* arrayOfEdges = createArrayOfEdges(matrIncedence, numVertex, numOfEdges);


	quickSort(arrayOfEdges, 0 ,numOfEdges - 1);
	cout << endl;

	cout<<"All edges in order\n";
	for(int i = 0; i < numOfEdges; i++)
		cout << arrayOfEdges[i].point1 << "-" << arrayOfEdges[i].point2 << ":  " << arrayOfEdges[i].weight << endl;

	Edge* skeleton = Krascal(matrIncedence, arrayOfEdges, numVertex, numOfEdges);
	cout << endl;

	cout<<"Skeleton:\n";
	for(int i = 0; i < numVertex - 1; i++)
		cout << skeleton[i].point1 << "-" << skeleton[i].point2 << ": " << skeleton[i].weight << endl;

	return 0;
}

Edge* Krascal(int** matrIncedence, Edge* arrayOfEdges, int numVertex, int numOfEdges ) {
	int* arrayOfConnectedComponents = new int[numVertex];
	for(int i = 0; i < numVertex; i++)
		arrayOfConnectedComponents[i] = i ;
	Edge* skeleton = new Edge[numOfEdges - 1];

	int k = 0;

	for(int i = 0; i < numVertex - 1; i++) {
		while( k < numOfEdges) {
			if(arrayOfConnectedComponents[arrayOfEdges[k].point1] != arrayOfConnectedComponents[arrayOfEdges[k].point2]) {
				skeleton[i] = arrayOfEdges[k];
				k++;
				break;
			}
			else k++;
		}
		for(int j = 0; j < numVertex; j++)
			if(arrayOfConnectedComponents[j] == arrayOfConnectedComponents[arrayOfEdges[k-1].point2])
				arrayOfConnectedComponents[j] = arrayOfConnectedComponents[arrayOfEdges[k-1].point1] ;
	}

	return skeleton;
}






int** matrixIncedence(ifstream& fin, int numVertex) {
	int** matrIncedence = new int*[numVertex];
	for(int i = 0; i < numVertex; i++)
		matrIncedence[i] = new int[numVertex];

	for(int i = 0; i < numVertex; i++)
		for(int j = 0; j < numVertex; j++)
			fin >> matrIncedence[i][j];
	return matrIncedence;
}

void showMatrix(int** matrIncedence, int numVertex ) {
	for(int i = 0; i < numVertex; i++) {
		for(int j = 0; j < numVertex; j++) {
			cout.width(3);
			matrIncedence[i][j] == -1 ? cout << matrIncedence[i][j]+1 : cout<<matrIncedence[i][j];
		}
		cout << endl;
	}
}

Edge* createArrayOfEdges(int** matrIncedence, int numVertex, int& numOfEdges) {
	for(int i = 0; i < numVertex; i++)
		for(int j = i; j < numVertex; j++)
			if(matrIncedence[i][j] != -1)
				numOfEdges++;

	Edge* arrayOfEdges = new Edge[numOfEdges];
	int k = 0;
	for(int i = 0; i < numVertex; i++)
		for(int j = i + 1; j < numVertex; j++)
			if(matrIncedence[i][j] != -1) {
				arrayOfEdges[k].weight = matrIncedence[i][j];
				arrayOfEdges[k].point1 = i;
				arrayOfEdges[k].point2 = j;
				k++;
			}
	return arrayOfEdges;
}

template <class X>
void quickSort(X* arr, int left, int right) {
	int i = left, j = right;
	int separateIndex = rand()%(j-i) + i;
	X separateElement = arr[separateIndex];
	do {
		while(arr[i] < separateElement)
			i++;
		while(arr[j] > separateElement)
			j--;
		if(i <= j) {
			if(i < j)
				::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while(i <= j);
	if(left < j)
		quickSort(arr, left, j);
	if(i < right)
		quickSort(arr, i, right);
}

template <class X>
void swap(X&a, X&b) {
	X temp;
	temp = a;
	a = b;
	b = temp;
}

bool Edge::operator<(Edge a) {
	if (weight < a.weight)
		return true;
	else return false;
}

bool Edge::operator>(Edge a) {
	if(weight > a.weight)
		return true;
	else return false;
}
