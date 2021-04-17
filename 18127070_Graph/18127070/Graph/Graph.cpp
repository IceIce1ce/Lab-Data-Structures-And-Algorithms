#include"Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

Graph Graph::ReadGraph(const string& file_name)
{
	Graph g;
	g.num_vertices = 0;
	ifstream fin(file_name);
	if(!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	else
	{
		fin >> num_vertices;
		adjacency_matrix.resize(num_vertices);
		cout << " " << num_vertices << endl;
		for(int i = 0; i < (signed) adjacency_matrix.size(); i++)
		{
			adjacency_matrix[i].resize(adjacency_matrix.size());
			for(int j = 0; j < (signed) adjacency_matrix[i].size(); j++)
			{
				fin >> adjacency_matrix[i][j];
				cout << " " << adjacency_matrix[i][j];
			}
			cout << endl;
		}
		fin.close();
	}
	return g;
}

Graph Graph::DisplayGraph(Graph g)
{
	return g.ReadGraph("Graph.txt");
}

bool Graph::IsValidGraph(Graph g)
{
	for(int i = 0; i < (signed) adjacency_matrix.size(); i++)
	{
		for(int j = 0; j < (signed) adjacency_matrix[i].size(); j++)
		{
			if(num_vertices >= 0 && adjacency_matrix[i][j] >= 0  && adjacency_matrix[i][i] == 0) return true;
		}
	}
	return false;
}

void Graph::traverse(int u, bool visited[])
{
	visited[u] = true;
	for(int v = 0; v < (signed) adjacency_matrix.size(); v++)
	{
		if(adjacency_matrix[u][v])
		{
			if(!visited[v]) traverse(v, visited);
		}
	}
}

bool Graph::IsConnectedGraph(Graph g)
{
	bool *visit = new bool[(signed) adjacency_matrix.size()];
	for(int u = 0; u < (signed) adjacency_matrix.size(); u++)
	{
		for(int i = 0; i < (signed) adjacency_matrix.size(); i++)
			visit[i] = false;
			traverse(u, visit);
		for(int i = 0; i < (signed) adjacency_matrix.size(); i++)
		{
			if(!visit[i]) return false;
		}
	}
	return true;
	delete[] visit;
}

int Graph::CountEdge(Graph g)
{
	int count = 0;
	for(int i = 0; i < num_vertices; i++) count += adjacency_matrix[i].size();
	return count / 2;
}

int Graph::CountVertices(Graph g, bool flag)
{
	int degree = 0;
	if(flag == 1)
	{
		for(int i = 0; i < num_vertices; i++)
		{
			if(i % 2 != 0)
			{
				if(adjacency_matrix[i].size() != 0) degree++;
			}
		}
	}
	if(flag == 0)
	{
		for(int i = 0; i < num_vertices; i++)
		{
			if(i % 2 == 0)
			{
				if(adjacency_matrix[i].size() != 0) degree++;
			}
		}
	}
	return degree;
}

void Graph::BFS(Graph g, int begin_vertex) //result will be true for using gcc to compile
{
	cout << "BFS on adjacency matrix: ";
	int n = (signed) adjacency_matrix.size();
	bool *visited = new bool[(signed) adjacency_matrix.size()];
	visited[n] = { false };
	queue<int> q; 
	q.push(begin_vertex);
	visited[begin_vertex] = true;
	while(q.empty() == false)
	{
		int vertex = q.front();
		q.pop();
		cout << vertex + 1 << " ";
		for(int i = 0; i < (signed) adjacency_matrix[vertex].size(); i++)
		{
			int neighborhood = i;
			int edge = adjacency_matrix[vertex][i];
			if(edge == 0) { continue; }
			if(visited[neighborhood] == false)
			{
				q.push(neighborhood);
				visited[neighborhood] = true;
			}
		}
	}
	cout << endl;
	return;
}

void Graph::AdjDFS(Graph g, int& vertex, vector<bool>& visited)
{
	visited[vertex] = true;
	cout << vertex + 1 << " ";
	for(int i = 0; i < (signed) adjacency_matrix[vertex].size(); i++)
	{
		int edge = adjacency_matrix[vertex][i];
		int neighborhood = i;
		if(edge == 0) { continue; }
		if(visited[neighborhood] == false) AdjDFS(g, neighborhood, visited);
	}
}

void Graph::DFS(Graph g, int begin_vertex)
{
	cout << "DFS on adjacency matrix: ";
	int n = (signed) adjacency_matrix.size();
	vector<bool> visited;
	for(int i = 0; i < n; i++) visited.push_back(false);
	AdjDFS(g, begin_vertex, visited);
	cout << endl;
	return;
}

int Graph::CountConnectedComponents(Graph g)
{
	int count = 0;
	bool* visited = new bool[num_vertices];
	for(int v = 0; v < num_vertices; v++) visited[v] = false;
	for(int v = 0; v < num_vertices; v++)
	{
		if(visited[v] == false)
		{
			traverse(v, visited);
			count++;
		}
	}
	return count;
	delete[] visited;
}

int Graph::minDistance(int dist[], bool path[])
{
	int min = INT_MAX, min_index;
	for(int v = 0; v < num_vertices; v++)
	if(path[v] == false && dist[v] <= min) min = dist[v], min_index = v;
	return min_index;
}

void Graph::printPath(int source[], int j)
{
	if(source[j] == -1) return;
	printPath(source, source[j]);
	cout << " " << j;
}

void Graph::printSolution(int dist[], int n, int source[])
{
	int src = 0;
	for(int i = 1; i < num_vertices; i++)
	{
		printf("\nVertex %d to vertex %d\t(cost: %d)\t%d", src, i, dist[i], src);
		printPath(source, i);
	}
}

void Graph::FindShortestPathDijkstra(Graph g, int begin_vertex)
{
	int *dist = new int[num_vertices];
	dist[num_vertices];
	bool *path = new bool[num_vertices];
	path[num_vertices];
	int *source = new int[num_vertices];
	source[num_vertices];
	for(int i = 0; i < num_vertices; i++)
	{
		source[0] = -1;
		dist[i] = INT_MAX;
		path[i] = false;
	}
	dist[begin_vertex] = 0;
	for(int i = 0; i < num_vertices - 1; i++)
	{
		int u = minDistance(dist, path);
		path[u] = true;
		for(int v = 0; v < num_vertices; v++)
			if(!path[v] && adjacency_matrix[u][v] && dist[u] + adjacency_matrix[u][v] < dist[v])
			{
				source[v] = u;
				dist[v] = dist[u] + adjacency_matrix[u][v];
			}
	}
	printSolution(dist, num_vertices, source);
	delete[] dist;
	delete[] path;
	delete[] source;
}

bool Graph::IsUndirectedGraph(Graph g)
{
	bool *visited = new bool[(signed) adjacency_matrix.size()];
	visited[num_vertices] = true;
	for(int i = 0; i < (signed) adjacency_matrix.size(); i++)
	{
		if(!visited[i]) return false;
	}
	return true;
	delete[] visited;
}

int main()
{
	Graph g;
	//g.DisplayGraph(g);
	g.ReadGraph("Graph.txt");
	if(g.IsValidGraph(g)) cout << "\nGraph is valid\n";
	else cout << "\nGraph isn't valid\n";
	if(g.IsConnectedGraph(g)) cout << "\nThe graph is connected\n";
	else cout << "\nThe graph isn't connected\n";
	cout << "\nNumber of edges: " << g.CountEdge(g) << endl;
	cout << "\nNumber of vertices with odd degrees: " << g.CountVertices(g, 1) << endl << endl;
	g.BFS(g, 1);
	cout << endl;
	g.DFS(g, 1);
	cout << "\nConnected components: " << g.CountConnectedComponents(g) << endl;
	g.FindShortestPathDijkstra(g, 0);
	cout << endl;
	if(g.IsUndirectedGraph(g)) cout << "\nThe graph is undirected\n";
	else cout << "\nThe graph isn't undirected\n";
	return 0;
}