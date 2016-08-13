#pragma once
#include<iostream>
#include<fstream>
#include<utility>
using namespace std;
struct Edge {
	int w;//weight
	pair<int, int> adjc;
};
class G {
private:
	int n;//# of edges
	int m;//# of vertices
	int *node;
	Edge* S;
public:
	G(int c) {
		m = c;
		n = 0;
		node = new int[m];
		//label all vertices from 1 to m
		for (int i = 0; i < m; i++)
			node[i] = i + 1;
		S = new Edge[n];
		//initilize the 0th edge as 0;
		S[0].adjc = { 0,0 };
		S[0].w = 0;
	}
	~G() {
		delete[] S;
		delete[] node;
	}
	//getter to get the # of edges
	int Esize() { return n; }
	//getter to get the array of edges S
	void printWeightMatrix() {
		if (n == 0) {
			cout << "empty graph\n";
			return;
		}
		int i, j;
		//create a table of m x m and initialize to 0
		int **table = new int*[m];
		for (i = 0;i < m;i++)
			table[i] = new int[m];
		for (i = 0;i < m;i++)
			for (j = 0;j < m;j++)
				table[i][j] = 0;
		//store edge weights in the table
		for (i = 0; i < n; i++) {
			table[S[i].adjc.first][S[i].adjc.second] = S[i].w;
			table[S[i].adjc.second][S[i].adjc.first] = S[i].w;
		}

		//colomn #
		for (i = 0;i < m;i++)
			cout << " " << i + 1;
		//print each row
		for (i = 0; i < m; i++) {
			for (j = 0;j < m;j++)
				cout << i + 1 << table[i][j] << " ";
			cout << endl;
		}
	}
	//given a value x, to search if it x is a node in the graph
	bool search_v(int x) {
		if (m < 1)
			return false;
		for (int i = 0; i < m; i++) {
			if (node[i] == x)
				return true;
		}
		return false;
	}
	void add_edge(int x, int y, int z)
	{
		//check vertex legal or not
		if (!search_v(x) || !search_v(y))
		{
			cout << "vertex out of range\n";
			return;
		}
		S[n].adjc = make_pair(x, y);
		S[n].w = z;
		n++;
	}
	bool is_cnt(int x, int y)
	{
		//check vertex legal or not
		if (!search_v(x) || !search_v(y))
		{
			cout << "out of range: not a vertice\n";
			exit(1);
		}
		pair<int, int> foo1 = { x, y };
		pair<int, int> foo2 = { y, x };
		//search the array of egdes for a match
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < n; i++) {
				if (S[i].adjc == foo1 || S[i].adjc == foo2)
					return true;
			}
		}
		return false;
	}
};
