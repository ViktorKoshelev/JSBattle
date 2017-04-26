#include "Graph.h"

Graph::Graph()
{
	graph = new int*[2];
	graph[0] = new int[2];
	graph[1] = new int[2];
	graph[0][0] = 0;
	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[1][1] = 0;
	size = 2;
}


Graph::~Graph()
{
	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete[] graph;
}

Graph::Graph(int s, int** m)
{
	if (!m || !s)
		throw "Matrix is empty";
	if (s < 0)
		throw "Size is non-negative";
	graph = m;
	size = s;
}

void Graph::print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << graph[i][j]<< " ";
		cout << endl;
	}
}

int Graph::getSize(){ return size; }

int Graph::getAllArcs(){
	int k = 0;
	for (int i = 0; i < size; i++)
		k += getArcsByNode(i);
	return k/2;
}

int Graph::getArcsByNode(int n){
	int k = 0;
	for (int i = 0; i < size; i++)
		if (graph[n][i]) k++;
	return k;
}

int* Graph::deikstra(int n){
	int* paths = new int[size];
	for (int i = 0; i < size; i++)
		paths[i] = 0;

	int* flags = new int[size];
	for (int i = 0; i < size; i++)
		flags[i] = 0;
	
	for (; flags[n] == 1;)
	{
		int k = 0;
		int newN = 0;
		for (int i = 0; i < size; i++)
		{
			if (!paths[i] || paths[n]+graph[n][i] < paths[i])
				paths[i] = paths[n] + graph[n][i];
			if (!k && !flags[i]){
				k = graph[n][i];
				newN = i;
			}
			if (k > graph[n][i] && !flags[i])
			{
				k = graph[n][i];
				newN = i;
			}
		}
		flags[n] = 1;
		n = newN;
	}

	return paths;
}

ostream& operator << (ostream& os, const Graph& g)
{
	for (int i = 0; i < g.size; i++)
		for (int j = 0; j < g.size; j++)
			os << g.graph[i][j] << " ";
	return os;
}

int** Graph::getMatrix(){
	return graph;
}
