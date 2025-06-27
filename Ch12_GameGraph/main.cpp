
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Spire
{
	struct Node
	{
		int x, y;
		int id;
		string name;

		Node(string _name, int _id, int _x, int _y) : name(_name), id(_id), x(_x), y(_y) {}
	};

private:
	vector<Node> nodes;
	vector<vector<int>> adj;
	vector<bool> visited;
	int nodeCount;

	const int CONSOLEHEIGHT = 40;
	const int CONSOLEWIDTH = 80;

public:
	Spire() : nodeCount(0) {}

	void addNode(string _name, int x=0, int y=0)
	{
		nodes.emplace_back(_name, nodeCount, x, y);
		adj.push_back(vector<int>());
		visited.push_back(false);
		nodeCount++;
	}

	void addEdge(int start, int end)
	{
		adj[start].push_back(end);   // �������־ �������� ������ ���� �ʴ´�.
	}

	void printGraph()
	{
		for (int i = 0;i < nodeCount;i++)
		{
			cout << "��� : " << i << "(" << nodes[i].name << ")" << endl;
			cout << "����� ��� : ";

			if (adj[i].empty())
			{
				cout << "����";
			}
			else
			{
				for (int j = 0;j < adj[i].size();j++)
				{
					cout << adj[i][j] << "(" << nodes[adj[i][j]].name << ")" << endl;

					if (j < adj[i].size() - 1)
					{
						cout << ", ";
					}
				}
			}
			cout << endl;
		}
	}

	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end)  // parent -1�� �ʱ�ȭ. ������ ���Ѵ�? ���� ��ã�Ҵ�.
		{
			return path; // ��ΰ� ���� �����͸� ��ȯ.
		}

		int current = end;
		while (current != -1)
		{
			path.insert(path.begin(), current);
			current = parent[current];
		}

		return path;
	}

	vector<int> findShortestPath(int start, int end)
	{
		if (start == end) return { start };

		fill(visited.begin(), visited.end(), false);

		vector<int> parent(nodeCount, -1);   // ��ǥ ���������� �迭�� �����Ѵ�.
		vector<int> distance(nodeCount, -1); // ����� �Ÿ��� �����ϴ� �迭
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while ���� �����ؾ��ϴ� ����. (���� ��尡 ��ǥ ������ �������� ��)
			if (end == c) break;

			// ������ ��������?
			for (int e : adj[c])
			{
				if (!visited[e])
				{
					visited[e] = true;
					q.push(e);
					parent[e] = c;
					distance[e] = distance[c] + 1;
				}
			}
		}

		return refindPath(parent, start, end);
	}

	private:
		void calculateNodePos() 
		{
			if (nodeCount == 0) return;

			vector<vector<int>> levels;  // ������ ���� �����ϴ� �����̳�
			vector<bool> processed(nodeCount, false);      // �湮�� ��带 ���

			levels.push_back({ 0 });   // �������� : 0���� �׻� 0�̴�.
			processed[0] = true;       // ���������� �湮�߽��ϴ�.

			int currentLevel = 0;
			while (currentLevel < levels.size())
			{
				vector<int> nextLevel;

				for (int node : levels[currentLevel])
				{
					for (int neighbor : adj[node])
					{
						if (!processed[neighbor])
						{
							nextLevel.push_back(neighbor);
							processed[neighbor] = true;
						}
					}
				}

				if (!nextLevel.empty())
				{
					levels.push_back(nextLevel);
				}
				currentLevel++;  // �������� ����Ͻÿ�.
			}

			for (int level = 0;level < levels.size();level++)  // 0�� ~ ������ �� �ݺ�
			{ 
				int nodeLevel = levels[level].size();          // �� ���� ���� ����
				int spacing = CONSOLEHEIGHT / (nodeLevel + 1);

				for (int i = 0; i < nodeLevel;i++)
				{
					int nodeId = levels[level][i];
					nodes[nodeId].x = spacing * (i + 1);
					nodes[nodeId].y = level * 2 + 2;
				}
			}
			

		}
		void DrawCircle(vector<vector<char>>& screen, int x,int y)
		{
			screen[y][x] = '0';
		}
		void DrawLine(vector<vector<char>>& screen, int x1, int y1, int x2, int y2)
		{
			int dx = abs(x2 - x1);
			int dy = abs(y1 - y1);

			int sx = (x1 < x2) ? 1 : -1;
			int sy = (y1 < y2) ? 1 : -1;

			int err = dx - dy;

			int x = x1;
			int y = y1;

			while (true)
			{
				if (x >= 0 && x < CONSOLEWIDTH && y >= 0 && y < CONSOLEHEIGHT)
				{
					if (screen[y][x] == ' ')
					{
						screen[y][x] = '-';
					}
					if (x == x2 && y == y2)
					{
						break;
					}

					int e2 = 2 * err;
					if (e2 > -dy)
					{
						
					}
					if (e2 < dx)
					{

					}
				}
			}
		}
		void DrawEdge(vector<vector<char>>& screen)
		{
			for (int i = 0;i < nodeCount;i++)
			{
				for (int neighbor : adj[i])
				{
					DrawLine(screen, nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y);
				}
			}
		}
		void DrawNode(vector<vector<char>>& screen)
		{
			for (int i = 0;i < nodeCount;i++)
			{
				DrawCircle(screen, nodes[i].x, nodes[i].y);
			}
		}
		void printScreen(vector<vector<char>>& screen)
		{
			cout << endl;
			for (int y = 0;y < CONSOLEHEIGHT;y++)
			{
				for (int x = 0;x < CONSOLEWIDTH;x++)
				{
					cout << screen[y][x];
				}
			}


			cout << endl;
		}

	public:
		void drawGraph()
		{
			vector<vector<char>> screen(CONSOLEHEIGHT, vector<char>(CONSOLEWIDTH, ' '));

			calculateNodePos();
			DrawEdge();
			DrawNode();
			printScreen();
		}


};

int main()
{
	Spire spire;
	
	cout << "�����̴� �����̾��� �� ��� ����" << endl;

	spire.addNode("����");       // 0
	spire.addNode("1�� ������"); // 1
	spire.addNode("1�� ������"); // 2
	spire.addNode("1�� ������"); // 3
	spire.addNode("1�� ������"); // 4
	spire.addNode("1�� ������"); // 5

	spire.addNode("2�� ����Ʈ��"); // 6
	spire.addNode("2�� ������");   // 7
	spire.addNode("2�� ������");   // 8
	spire.addNode("2�� �̺�Ʈ");   // 9
	spire.addNode("2�� �޽�");     // 10

	spire.addNode("3�� �޽�");    // 11
	spire.addNode("3�� �̺�Ʈ");   // 12
	spire.addNode("3�� �޽�");    // 13
	spire.addNode("3�� �̺�Ʈ");   // 14

	spire.addNode("4�� �޽�");    // 15
	spire.addNode("5�� ����");    // 16

	spire.addEdge(0, 1); spire.addEdge(1, 6); spire.addEdge(6, 11); spire.addEdge(11, 15); spire.addEdge(15, 16);

	spire.addEdge(0, 2); spire.addEdge(2, 7); spire.addEdge(7, 11); 

	spire.addEdge(0, 3); spire.addEdge(3, 8); spire.addEdge(8, 12); spire.addEdge(12, 15); 
	spire.addEdge(3, 9); spire.addEdge(9, 12);

	spire.addEdge(0, 4); spire.addEdge(4, 9); spire.addEdge(9, 13); spire.addEdge(13, 15);

	spire.addEdge(0, 5); spire.addEdge(5, 10); spire.addEdge(10, 14); spire.addEdge(14, 15);

	spire.printGraph();
	spire.drawGraph();

	vector<int> temp = spire.findShortestPath(0, 16);
	for (auto& e : temp)
		cout << e << " -> ";

}