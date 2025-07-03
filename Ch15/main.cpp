
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
// ATM�� ������� ���� ���� �ִ�. n���� ����� ��� ��ٸ� �ð��� �ּ��� �ð��� �Ƿ��� ����ؾ��ұ�?
// �׸��� �׽ð��� �� ������ ���� ������ּ���.
void Solve1()
{
	int n = 5; // �� �ο�
	int totalTime = 0; // ��� �ο��� ��ٸ� �ð�
	std::vector<int> waitTimeTable;           // ������ �ο����� ��ٸ��� �ð��� ������ �����ؾ� �Ѵ�.

	waitTimeTable.push_back(3);
	waitTimeTable.push_back(1);
	waitTimeTable.push_back(4);
	waitTimeTable.push_back(3);
	waitTimeTable.push_back(2);

	std::sort(waitTimeTable.begin(), waitTimeTable.end());
	std::vector<int> clients(waitTimeTable.size(), -1);

	clients[0] = waitTimeTable[0]; // ó�� ����ϴ� ���

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
	cout << n << "���� ������� ��� ��ٸ��� �ð��� �ּҰ� �Ǵ� �ð��� : " << totalTime << endl;
}

#pragma endregion

#pragma region Q2

// �賶�� ������ n�� ���� �� �ִ� ���԰� k�� �־�����.
// ���Ը� �ִ������� ����� �� �ִ��� ��ġ�� ������ ���� ���� ������ּ���.
void Solve2()
{
	cout << endl;
	cout << "=== �賶 ���� Ǯ�� ===" << endl;

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

	cout << "������ ���԰� 7���� ���� �� ���� �� �ִ� ��ġ : " << dp[7] << endl;
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

	cout << "�־��� �������� �ִ� ��ġ : " << bestitems.first <<endl;

	std::vector<ItemW> ItemC = bestitems.second;

	int i = 0;

	for (auto& item : ItemC)
	{
		i++;
		cout << i << "��° �������� �̸� : " << item.GetName() << ", ���� : " << item.GetWeight() << ", ��ġ : " << item.GetValue() << endl;
		inventory.AddItem(item);
	}
	
	//inventory.AddItem(A);
	//inventory.AddItem(B);

	int index = 0;

	for (auto& item : inventory.GetInventory())
	{
		index++;
		cout << index << "��° ������ : " << item.GetName() << " , ���� : " << item.GetWeight() << endl;
	}
}

int main()
{
	//Solve1();
	//Solve2();
	InventoryWeightSystem();
}