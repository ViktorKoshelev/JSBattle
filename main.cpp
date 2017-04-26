#include "Graph.h"
#include <iostream>
#include <fstream>
using namespace std;

void printResults(Graph g)
{
	cout << "Все ребра:" << g.getAllArcs() << endl;
	for (int i = 0; i < g.getSize(); i++)
		cout << "У " << i << " точки ребер:" << g.getArcsByNode(i) << endl;
	for (int i = 0; i < g.getSize(); i++)
	{
		int* m = g.deikstra(i);
		for (int j = 0; j < g.getSize(); j++)

			cout << "Дейкстра из " << i << " в " << j << ": " << m[j] << endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream fin("Matrix.txt");
	int size;
	
	fin >> size;
	int** matr = new int*[size];
	for (int i = 0; i < size; i++)
		matr[i] = new int[size];
	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				fin >> matr[i][j];
			}
		}
	Graph g(size, matr);
	printResults(g);
	
	return 0;

}

