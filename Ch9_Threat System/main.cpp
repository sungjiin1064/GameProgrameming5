
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Character
{
	string name;

	
};

class Boss
{
public:
	string name;
	int currentTurn;
	priority_queue<int> threatQueue;
	Boss(string name) : currentTurn(0) {}

	void clear()
	{		
		while (!threatQueue.empty())
		{
			threatQueue.pop();
		}
	}

	void UpdateThreatQueue(std::vector<Character>& party)
	{
		clear();

		for (auto& character : party)
		{
			int threat = character.getCurrentThreat();
			threatQueue.push(threat);
			character.NextTurn();
		
		}
	}

	int* FindMostThreatCharacter(std::vector<Character>& party)
	{
		Character* target = nullptr;	

		int MostThreatValue = threatQueue.top();
		return MostThreatValue;
	}
};

void FindkthExample()
{

}

void ThreatSystem()
{
	Character a("전사", { 1,2,3,4,5 });
	Character b("도적", { 1,1,1,10,5 });
	Character c("궁수", { 3,3,3,3,3 });
	Character d("마법사", { 0,2,5,6,6 });
	Character e("성직자", { 0,0,10,8,15 });

	std::vector<Character> party;

	party.push_back(a);
	party.push_back(b);
	party.push_back(c);
	party.push_back(d);
	party.push_back(e);

	for (auto& character : party)
	{
		character.PrintStat();
	}

	Boss boss("킹고블린");
	boss.UpdateThreatQueue(party);
	int value = boss.FindMostThreatCharacter(party);
	cout << "첫번째 턴에서 위협도가 가장 큰 수치" << value << endl;

	int nextTurnValue = 3;

	int currentThreat = 0;
	for (int i = 0;i < nextTurnValue;i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}

	cout << "" << currentThreat << endl;
}

int main()
{

}