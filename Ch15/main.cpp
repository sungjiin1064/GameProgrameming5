
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region Q1

struct Client
{
	int waitId;
	int waitTime;
};

// 3,1,4,3,2
// ATM에 사람들이 줄을 서고 있다. n명의 사람이 모두 기다린 시간이 최소의 시간이 되려면 어떻게해야할까?
// 그리고 그시간은 몇 초인지 값을 출력해주세요.
void Solve1()
{
	int n = 5; // 총 인원
	int totalTime = 0; // 모든 인원이 기다린 시간
	std::vector<int> waitTimeTable;           // 각각이 인원수가 기다리는 시간을 여러개 저장해야 한다.

	waitTimeTable.push_back(3);
	waitTimeTable.push_back(1);
	waitTimeTable.push_back(4);
	waitTimeTable.push_back(3);
	waitTimeTable.push_back(2);

	std::sort(waitTimeTable.begin(), waitTimeTable.end());
	std::vector<int> clients(waitTimeTable.size(), -1);

	clients[0] = waitTimeTable[0]; // 처음 사용하는 사람

	for (int i = 1; i < waitTimeTable.size();i++)
	{
		clients[i] = clients[i - 1] + waitTimeTable[i];
	}
	//clients[i] = waitTimeTable[i];
	//clients[i] = clients[i] + waitTimeTable[i];
	//clients[i] = clients[1] + 4;
	//clients[i] = clients[2] + 3;
	//clients[i] = clients[3] + 2;

	for (int t : clients)
	{
		totalTime += t;
	}

	cout << endl;
	cout << n << "명의 사람들이 모두 기다리는 시간이 최소가 되는 시간은 : " << totalTime << endl;
}

#pragma endregion

#pragma region Q2

// 배낭에 물건이 n개 담을 수 있는 무게가 k가 주어진다.
// 무게를 최대한으로 담았을 때 최대의 가치를 저장할 때의 값을 출력해주세요.
void Solve2()
{
	cout << endl;
	cout << "=== 배낭 문제 풀이 ===" << endl;

	int n = 4;
	int k = 7;
	std::vector<std::pair<int, int>> items{ {6,13},{4,8},{3,6},{5,12} };

	std::vector<int> dp(k + 1, 0);
	//dp[0] = 0;
	//dp[1] = 0;
	//dp[2] = 0;
	//dp[3] = 6;
	//dp[4] = 8;
	//dp[5] = 12;
	//dp[6] = 13;
	//dp[7] = 0;

	for (int i = 0;i < n;i++)
	{
		int weight = items[i].first;
		int value = items[i].second;

		for (int w = k;w >= weight;w--)
		{
			dp[w] = std::max(dp[w], dp[w - weight] + value);
		}
	}

	cout << "가방의 무게가 7까지 담을 수 있을 때 최대 가치 : " << dp[7] << endl;
}

#pragma endregion

class ItemW
{
	string name;
	int weight;
	int value;

public:
	ItemW(string _name, int _weight, int _value) : name(_name), weight(_weight), value(_value) {}

	int GetWeight() const { return weight; }
	int GetValue() const { return value; }
	string GetName() const { return name; }
};

class InventoryW
{
	std::vector<ItemW> Items;
	int maxWeight;
	int currentWeight;

public:
	InventoryW(int max) : maxWeight(max), currentWeight(0) {};

	void AddItem(const ItemW& addItem)
	{
		if (CheckWeight(addItem))
		{
			Items.push_back(addItem);
			currentWeight += addItem.GetWeight();
		}
	}

	bool CheckWeight(const ItemW& addItem)
	{
		return maxWeight < currentWeight + addItem.GetWeight();
	}

	std::pair<int,std::vector<ItemW>> findBestItem(int targetWeight, std::vector<ItemW>& selectableItems)
	{
		std::vector<int> dp(targetWeight + 1, 0);

		std::vector<std::vector<bool>> selected(selectableItems.size(), std::vector<bool>(targetWeight + 1, false));

		for (int i = 0;i < selectableItems.size();i++)
		{
			int weight = selectableItems[i].GetWeight();
			int value = selectableItems[i].GetValue();

			for (int w = targetWeight; w >= weight; w--)
			{
				if (dp[w - weight] + value > dp[w])
				{
					dp[w] = dp[w - weight] + value;
					selected[i][w] = true;
				}
			}
		}
		
		std::vector<ItemW> bestItems;
		int w = targetWeight;

		for (int i = selectableItems.size() - 1; i >= 0 && w > 0;i--)
		{
			if (selected[i][w])
			{
				bestItems.push_back(selectableItems[i]);
				w -= selectableItems[i].GetWeight();
			}
		}

		return std::make_pair(dp[targetWeight], bestItems);
	}

	std::vector<ItemW>& GetInventory() { return Items; }
};

void InventoryWeightSystem()
{
	InventoryW inventory(7);

	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 12);

	std::vector<ItemW> selectableTable{A, B, C, D};

	std::pair<int,std::vector<ItemW>> bestitems = inventory.findBestItem(7, selectableTable);

	cout << "주어진 아이템의 최대 가치 : " << bestitems.first <<endl;

	std::vector<ItemW> ItemC = bestitems.second;

	int i = 0;

	for (auto& item : ItemC)
	{
		i++;
		cout << i << "번째 아이템의 이름 : " << item.GetName() << ", 무게 : " << item.GetWeight() << ", 가치 : " << item.GetValue() << endl;
		inventory.AddItem(item);
	}
	
	//inventory.AddItem(A);
	//inventory.AddItem(B);

	int index = 0;

	for (auto& item : inventory.GetInventory())
	{
		index++;
		cout << index << "번째 아이템 : " << item.GetName() << " , 무게 : " << item.GetWeight() << endl;
	}
}

int main()
{
	//Solve1();
	//Solve2();
	InventoryWeightSystem();
}