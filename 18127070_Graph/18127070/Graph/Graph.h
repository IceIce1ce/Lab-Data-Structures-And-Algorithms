#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<limits.h>
using namespace std;

class Graph
{
private:	
	vector<vector<int>> adjacency_matrix;
	int num_vertices;
public:
	Graph();
	~Graph();
public:
	Graph ReadGraph(const string& file_name);
	Graph DisplayGraph(Graph g);
	bool IsValidGraph(Graph g);
	void traverse(int u, bool visited[]);
	bool IsConnectedGraph(Graph g);
	int CountEdge(Graph g);
	int CountVertices(Graph g, bool flag); //need to check again
	void BFS(Graph g, int begin_vertex);
	void AdjDFS(Graph g, int &vertex, vector<bool> &visited);
	void DFS(Graph g, int begin_vertex);
	int CountConnectedComponents(Graph g);
	int minDistance(int dist[], bool path[]);
	void printPath(int source[], int j);
	void printSolution(int dist[], int n, int source[]);
	void FindShortestPathDijkstra(Graph g, int begin_vertex);
	bool IsUndirectedGraph(Graph g);
};