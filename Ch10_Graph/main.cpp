
#include <iostream>
#include <vector>
#include <stack>   // DFS�� stack���� ǥ��
#include <queue>   // BFS�� queue�� ǥ��

using namespace std;

class Graph
{
private:
	int V;
	std::vector< std::vector<int>> adj;

	vector<bool> visited;

	void DFS(int v)
	{
		visited[v] = true;
		cout << v << " ";

		for (auto& i : adj[v])
		{
			if (visited[i] == false) // !visited[i] ����
				DFS(i);
		}
	}

	void DFSIter(int v)
	{
		std::stack<int> stack;		
		stack.push(v);
		
		while (!stack.empty())
		{
			int cVertex = stack.top();			
			stack.pop();

			if (visited[cVertex] = false)
			{
				visited[cVertex] = true;
				cout << cVertex << " ";
			}

			// �̿� ���
			for (int i = adj[cVertex].size() - 1;i >= 0;i--)
			{
				int neighbor = adj[cVertex][i];
				if (visited[neighbor] == false)
				{
					stack.push(neighbor);
				}
			}

			for (auto& elem : adj[cVertex])
			{
				//if (visited[elem] == false)
				//{
				//	stack.push(elem);
				//	visited[elem] = true;
				//	cout << elem << " ";
				//}
			}
						
		}
	}

	void BFSIter(int start)
	{
		std::queue<int> q;
		visited[start] = true;
		q.push(start);

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			cout << c << " ";

			for (auto& e : adj[c])
			{
				if (!visited[e])
				{
					visited[e] = true;
					q.push(e);
				}
			}			
		}
	}

	void BFSRecursive(queue<int>& q)
	{
		if (!q.empty()) return;

		int c = q.front();
		q.pop();
		cout << c << " ";

		for (auto& e : adj[c])
		{
			if (!visited[e])
			{
				visited[e] = true;
				q.push(e);
			}
		}

		BFSRecursive(q);
	}

	void BFS(int start)
	{
		std::queue<int> q;
		visited[start] = true;
		q.push(start);

		BFSRecursive(q);
	}

public:
	Graph(int vertices) : V(vertices)
	{
		adj.resize(V);
		visited.resize(V, false);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void PrintGraph()
	{
		for (int i = 0;i < V;i++)
		{
			cout << "���� " << i << "�� ������ ����Ʈ : ";
			for (auto& elem : adj[i])
			{
				cout << " ->" << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Ž�� ��� (���� ���� : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout<<"DFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void BFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "BFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
		BFSIter(startV);
		cout << endl;
	}

	void BFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "BFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
		BFS(startV);
		cout << endl;
	}

};

class GraphMatrix
{
private:
	int V;
	vector<vector<int>> adj;

public:
	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {}

	void addEdge(int u, int v)
	{
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	void PrintGraph()
	{
		cout << "���� ���" << endl;
		for (int i = 0;i < V;i++)
		{
			for (int j = 0;j < V;j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.DFSTraverse(3);
	g.DFSIterTraverse(3);
	g.PrintGraph();
	//Graph g(4);
	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(1, 3);
	//g.addEdge(2, 4);
	//g.addEdge(2, 5);
	//g.DFSTraverse(2);
	//g.DFSIterTraverse(2);
	//g.BFSIterTraverse(0);
	//g.PrintGraph();

	GraphMatrix gm(4);
	gm.addEdge(0, 1);
	gm.addEdge(0, 2);
	gm.addEdge(0, 3);
	gm.addEdge(1, 2);
	gm.addEdge(1, 3);
	gm.PrintGraph();

}