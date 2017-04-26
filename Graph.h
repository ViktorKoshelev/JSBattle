#pragma once
#include <iostream>
using namespace std;
class Graph
{
private:
	int** graph;
	int size;
public:
	Graph();
	~Graph();
	Graph(int, int**);
	int getAllArcs();
	int getArcsByNode(int);
	int* deikstra(int);
	void print();
	int getSize();
	int** getMatrix();
	friend ostream& operator << (ostream&, const Graph&);
};

