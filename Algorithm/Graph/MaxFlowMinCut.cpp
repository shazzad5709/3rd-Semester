#include <iostream>
#include <climits>
#include <queue>
using namespace std;

#define V 6

int bfs(int rGraph[V][V], int src, int sink, int parent[])
{
	bool visited[V]={0};

	queue <int> q;
	q.push(src);
	visited[src] = true;
	parent[src] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v=0; v<V; v++)
		{
			if (visited[v]==false && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[sink] == true);
}

void dfs(int rGraph[V][V], int s, bool visited[])
{
	visited[s] = true;
	for (int i = 0; i < V; i++)
	if (rGraph[s][i] && !visited[i])
		dfs(rGraph, i, visited);
}

void minCut(int graph[V][V], int src, int sink)
{
	int u, v;

	int rGraph[V][V];
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V];

	while (bfs(rGraph, src, sink, parent))
	{
		int pathFlow = INT_MAX;
		for (v=sink; v!=src; v=parent[v])
		{
			u = parent[v];
			pathFlow = min(pathFlow, rGraph[u][v]);
		}

		for (v=sink; v != src; v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= pathFlow;
			rGraph[v][u] += pathFlow;
		}
	}

	bool visited[V]={0};
	dfs(rGraph, src, visited);

	for (int i = 0; i < V; i++)
	for (int j = 0; j < V; j++)
		if (visited[i] && !visited[j] && graph[i][j])
			cout << i << " - " << j << endl;

	return;
}

int main()
{
	int graph[V][V] = { {0, 16, 13, 0, 0, 0},
						{0, 0, 10, 12, 0, 0},
						{0, 4, 0, 0, 14, 0},
						{0, 0, 9, 0, 0, 20},
						{0, 0, 0, 7, 0, 4},
						{0, 0, 0, 0, 0, 0}
					};

	minCut(graph, 0, 5);

	return 0;
}
