
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

#define SIZE 10

int maze[SIZE][SIZE] =
{
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,0,1},
	{1,0,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,1,0,0},
	{1,0,0,0,0,0,0,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

//상하좌우
const int dx[4] = { 0,0,-2,2 };
const int dy[4] = { -1,1,0,0 };

struct Monster
{
	int x, y;
	int prev_x, prev_y;
	int step;
	std::vector<int> direction;

	Monster() = default;
	Monster(int x,int y, std::vector<int> direction) : x(x),y(y), direction(direction) 
	{
		prev_x = x;
		prev_y = y;
		step = 0;
	}
};

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// maze[y][x]의 값이 0이면 ' ', 1이면 '■' 표현하는 코드를 만들어보세요.

int main()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (maze[y][x] == 0)
			{
				cout << "  ";
			}
			else if (maze[y][x] == 1)
			{
				cout << "■";
			}
		}
		cout << endl;
	}

#pragma region 이동할 길을 미리 만들어 둔다.

	//std::vector<int> direction = { 1,1,3,3,3,3,3,3,3,1,1,1,3 };
	//int sx = 2;
	//int sy = 0;
	//GoToXY(sx, sy);
	//cout << "★";

	//int pre_x = sx;
	//int pre_y = sy;

	//for (int i = 0; i < direction.size(); i++)
	//{


	//	GoToXY(pre_x, pre_y);
	//	cout << "  ";

	//	int dir = direction[i];
	//	sx += dx[dir];
	//	sy += dy[dir];
	//	pre_x = sx;
	//	pre_y = sy;
	//	GoToXY(sx, sy);
	//	cout << "★";

	//	Sleep(500);
	//}

#pragma endregion

#pragma region 길을 따라 이동하는 몬스터

	std::vector<int> path = { 1,1,3,3,3,3,3,3,3,1,1,1,3 };
	int monster_count = 5;
	int interval = 2;
	int steps = path.size() + monster_count + interval;
	int sx = 2;
	int sy = 0;

	std::vector<Monster> monsters;

	for (int i = 0; i < steps; i++)
	{
		if (i % interval == 0 && monsters.size() < monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}
	}
	
	GoToXY(sx, sy);
	cout << "★";

	int pre_x = sx;
	int pre_y = sy;

	for (int i = 0; i < monsters.size(); i++)
	{
		Monster& monster = monsters[i];

		if (monster.step >= monster.direction.size()) continue;

		GoToXY(monster.prev_x, monster.prev_y);
		cout << "  ";

		int dir = monster.direction[monster.step];		
		monster.x += dx[dir];
		monster.y += dy[dir];
		monster.prev_x = monster.x;
		monster.prev_y = monster.y;
		monster.step++;
		
		GoToXY(monster.x,monster.y);
		cout << "★";

		Sleep(500);
	}

#pragma endregion
}

