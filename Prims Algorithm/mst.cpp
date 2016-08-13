#include "Graph.h"
int main() {
	ifstream F;
	int m, ort, start, x, y, z;
	F.open("eg.txt");
	F >> ort;
	F >> m;
	G mygraph(m);//build a graph
	while (!F.eof()) {
		//get a group of triple values as 2 vertice and 1 weight of the edge between them
		F.ignore();
		F >> x;
		F.ignore();
		F >> y;
		F.ignore();
		F >> z;
		mygraph.add_edge(x, y, z);
	}
	cout << "Adjacancy matrix: \n ";
	//Store adjancancy relationship in A[][]
	int A[10][10] = { 0 };
	for (int i = 1; i < m + 1; i++) {
		for (int j = i; j < m + 1; j++) {
			if (mygraph.is_cnt(i, j)) {
				A[i][j] = 1;
				A[j][i] = 1;
			}
		}
	}
	//print out Adjc matix
	cout << " ";
	for (int i = 1; i < m + 1; i++)
		cout << i << " ";//print colomn #
	cout << endl;
	//print each row and its content
	for (int j = 1; j < m + 1; j++)
	{
		cout << j;
		for (int i = 1; i <= m; i++)
			cout << " " << A[j][i];
		cout << endl;
	}
	//print out W matrix
	cout << "Weight matrix" << endl;
	mygraph.printWeightMatrix(ort);
	//print out MST
	cout << "Enter a starting point (1 to " << m << ")";
	cin >> start;
	mygraph.MST(start);
	F.close();
	system("pause");
	return 0;
}
