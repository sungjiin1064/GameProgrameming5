
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
		adj[start].push_back(end);   // 방향이있어서 역순으로 연결은 하지 않는다.
	}

	void printGraph()
	{
		for (int i = 0;i < nodeCount;i++)
		{
			cout << "노드 : " << i << "(" << nodes[i].name << ")" << endl;
			cout << "연결된 노드 : ";

			if (adj[i].empty())
			{
				cout << "없음";
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

		if (parent[end] == -1 && start != end)  // parent -1로 초기화. 접근을 못한다? 길을 못찾았다.
		{
			return path; // 경로가 없는 데이터를 반환.
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

		vector<int> parent(nodeCount, -1);   // 목표 지점까지의 배열을 저장한다.
		vector<int> distance(nodeCount, -1); // 노드의 거리를 저장하는 배열
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while 강제 종료해야하는 조건. (현재 노드가 목표 지점에 도착했을 때)
			if (end == c) break;

			// 도착을 안햇으면?
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

			vector<vector<int>> levels;  // 던전의 층을 저장하는 컨테이너
			vector<bool> processed(nodeCount, false);      // 방문한 노드를 기록

			levels.push_back({ 0 });   // 시작지점 : 0층은 항상 0이다.
			processed[0] = true;       // 시작지점은 방문했습니다.

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
				currentLevel++;  // 다음층을 계산하시오.
			}

			for (int level = 0;level < levels.size();level++)  // 0층 ~ 마지막 층 반복
			{ 
				int nodeLevel = levels[level].size();          // 각 층의 방의 갯수
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
	
	cout << "슬레이더 스파이어의 맵 노드 구현" << endl;

	spire.addNode("시작");       // 0
	spire.addNode("1층 전투방"); // 1
	spire.addNode("1층 전투방"); // 2
	spire.addNode("1층 전투방"); // 3
	spire.addNode("1층 전투방"); // 4
	spire.addNode("1층 전투방"); // 5

	spire.addNode("2층 엘리트방"); // 6
	spire.addNode("2층 전투방");   // 7
	spire.addNode("2층 전투방");   // 8
	spire.addNode("2층 이벤트");   // 9
	spire.addNode("2층 휴식");     // 10

	spire.addNode("3층 휴식");    // 11
	spire.addNode("3층 이벤트");   // 12
	spire.addNode("3층 휴식");    // 13
	spire.addNode("3층 이벤트");   // 14

	spire.addNode("4층 휴식");    // 15
	spire.addNode("5층 보스");    // 16

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