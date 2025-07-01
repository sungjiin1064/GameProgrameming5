
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

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

		cout << "DFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
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

	void dfsCount(int& count, int startV)
	{		
		visited[startV] = true;
		count++;

		for (int e : adj[startV])
		{
			if (!visited[e])
			{
				visited[e] = true;
				dfsCount(count, e);
			}
		}

	}

	bool IsConnected(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		int count = 0;

		dfsCount(count, startV);
		return count == V;
	}

	void CheckGraphIsConnected()
	{
		if (IsConnected(0))
		{
			cout << "��� �׷����� ����Ǿ����ϴ�." << endl;
		}
		else
		{
			cout << "������� ���� �׷����� �����մϴ�." << endl;
			cout << "-1";
		}
	}

	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end) return path;

		int current = end;
		while (current != -1)
		{
			path.insert(path.begin(), current);
			current = parent[current];
		}
		return path;
	}

	std::vector<int> findShortestPath(int start, int end)
	{
		if (start == end) return { start };

		fill(visited.begin(), visited.end(), false);

		vector<int> parent(V, -1);   // ��ǥ ���������� �迭�� �����Ѵ�.
		vector<int> distance(V, -1); // ����� �Ÿ��� �����ϴ� �迭
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;
		
		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			if (end == c) break;

			for (int e : adj[c])
			{
				if (visited[e])
				{
					visited[e] = true;
					q.push(e);
					parent[e] = c;
					distance[e] = distance[c] + 1;
				}
			}
		}
		return refindPath(parent,start,end);
	}



};

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.CheckGraphIsConnected();

	vector<int> temp = g.findShortestPath(0, 5);

	cout << "0 ���� 5 �� �̵��ϴ� �ּ� �Ÿ�" << endl;
	for (auto& e : temp)
	{
		cout << "->" << e;
	}
}

