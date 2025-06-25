
#include <iostream>
#include <vector>
#include <queue>     // priority_queue
#include <utility>   //pair

using namespace std;

bool myLess(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

class MinHeap // 가장 작은 수가 제일 위에 있는 구조
{
private:
	//std::priority_queue<int> pq2;  // 밑에거랑 동일
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // 최소값이 제일위로 가는 형태
public:
	MinHeap() = default;

	void push(int value) 
	{
		pq.push(value);
	}
	bool isEmpty() const
	{
		return pq.empty();
	}
	const int& top() const
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		return pq.top();
	}
	int pop() 
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!"); 
		}
		int minValue = pq.top();
		pq.pop();
		return minValue;
	}
	
};

class Character
{
private:
	string name;
	std::vector<int> threatLevel;
	int currentTurn;

public:
	Character(string name, std::vector<int> TL) : name(name), threatLevel(TL), currentTurn(0) {}

	int getCurrentThreat()
	{
		if (threatLevel.size() < currentTurn)
		{
			throw runtime_error("Out of Range");
		}

		return threatLevel[currentTurn];
	}

	void NextTurn()
	{
		currentTurn++;
	}

	void PrintStat()
	{
		cout << name << "(현제 위협도 : " << getCurrentThreat() << ")" << endl;
	}

	
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

	int FindMostThreatCharacter(std::vector<Character>& party)
	{
		//Character* target = nullptr;	

		int MostThreatValue = threatQueue.top();
		return MostThreatValue;
	}
};

void FindkthExample()
{
	MinHeap myHeap;

	myHeap.push(11);
	myHeap.push(7);
	myHeap.push(5);
	myHeap.push(3);

	cout << "최소 힙의 가장 작은 값 : " << myHeap.top() << endl;

	cout << "k번째 작은 수를 출력하세요." << endl;
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

	boss.UpdateThreatQueue(party);
	int value = boss.FindMostThreatCharacter(party);
	cout << "두번째 턴에서 위협도가 가장 큰 수치" << value << endl;

	int nextTurnValue = 3;

	int currentThreat = 0;
	for (int i = 0;i < nextTurnValue;i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}
		
	cout << "###전사의 3턴 후 위협도 : " << currentThreat << endl;
}

int main()
{
	ThreatSystem();
}