#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int nodes;
    vector<bool> visited;
    list<int> *adj;
    
    public:
    Graph(int n);
    void createGraph();
    void addEdge(int start, int end);
    void BFS(int start);
    void DFS(int start);
};

Graph::Graph(int n)
{
    this->nodes = n;
    this->adj = new list<int>[n];
    for (int i = 0; i < n; i++)
        visited.push_back(false);
}

void Graph::addEdge(int start, int end)
{
    adj[start].push_back(end);
}

void Graph::createGraph()
{
    this->addEdge(0,1);
    this->addEdge(0,2);
    this->addEdge(1,2);
    this->addEdge(2,0);
    this->addEdge(2,3);
    this->addEdge(3,3);
}

void Graph::BFS(int start)
{
    cout << "\n BFS Tree Traversal : \t";
    int key;
    queue<int> trav;
    trav.push(start);
    this->visited[start] = true;

    while (!trav.empty())
    {
        key = trav.front();
        this->visited[key] = true;
        trav.pop();
        cout << "\t" << key;
        for (list<int>::iterator iter = adj[key].begin(); iter != adj[key].end(); iter++)
        {
            if (!visited[*iter])
                trav.push(*iter);
        }
    }
    cout << endl;
}

void Graph::DFS(int start)
{
    //cout << "\n DFS Tree Traversal : \t";
    this->visited[start] = true;

    cout << "\t" << start;
    for (list<int>::iterator iter = adj[start].begin(); iter != adj[start].end(); iter++)
    {
        if (!visited[*iter])
            this->DFS(*iter);
    }
}
int main()
{
    Graph *g = new Graph(5);
    g->createGraph();
    //g->BFS(2);
    g->DFS(2);
    return 1;
}
