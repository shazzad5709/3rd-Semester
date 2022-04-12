#include<iostream>
#include<climits>
#include<queue>

#define V 8

using namespace std;

bool bfs(int rGraph[V][V], int src, int sink, int parent[])
{
    bool visited[V]={0};

    queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v=0; v<V; v++)
        {
            if(visited[v]==false && rGraph[u][v]>0)
            {
                if(v==sink)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V], int src, int sink)
{
    int u, v;
    int rGraph[V][V];

    for(u=0; u<v; u++)
        for(v=0; v<V; v++)
            rGraph[u][v]=graph[u][v];

    int parent[V];
    int maxFlow=0;

    while (bfs(rGraph, src, sink, parent))
    {
        int pathFlow = INT_MAX;
        for (v = sink; v != src; v = parent[v])
        {
            u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (v = sink; v != src; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int graph[V][V]
        = { { 0, 2, 3, 0, 0, 0, 0, 0},
            { 0, 0, 0, 2, 0, 0, 0, 0},
            { 0, 0, 0, 3, 0, 0, 0, 0},
            { 0, 0, 0, 0, 1, 2, 1, 0},
            { 0, 0, 0, 0, 0, 0, 0, 1},
            { 0, 0, 0, 0, 0, 0, 0, 2},
            { 0, 0, 0, 0, 0, 0, 0, 1},            
        };

    cout << "Max Flow: "
         << fordFulkerson(graph, 0, 7);

    return 0;
}