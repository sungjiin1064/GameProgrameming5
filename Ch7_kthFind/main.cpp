
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

void EmergencyExample()
{
	std::vector<int> people = { 14,51,24,75,54,63 };
	std::vector<int> answer;
	answer.assign(people.size(), 0);
	std::map<int, int> sheets;

	for (int i = 0; i < people.size(); i++)
	{
		sheets.insert({people[i],i });
	}
	//sheets.insert(0, { people[0] });
	//sheets.insert(1, { people[1] });
	//sheets.insert(2, { people[2] });
	//sheets.insert(3, { people[3] });
	//sheets.insert(4, { people[4] });
	//sheets.insert(5, { people[5] });

	std::sort(people.begin(), people.end());

	for (int i = 0; i < people.size(); i++)
	{
		auto it = sheets.find(people[people.size() - 1 - i]);
		int index = it->second;
		answer[index] = i + 1;
	}
	
	cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	cout << "]" << endl;
}

int main()
{
	EmergencyExample();
}