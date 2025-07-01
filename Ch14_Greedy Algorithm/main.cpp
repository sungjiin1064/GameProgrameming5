
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CoinBack(int amount)
{
	struct Coin
	{
		int value;
		int count;

		Coin(int _value) : value(_value),count(0) {}
	};

	std::vector<int> coins = { 500,100,50,10,5,1 };

	int totalCount2 = 0;

	std::vector<Coin> coinWallet;
	for (int coin : coins)
	{
		coinWallet.emplace_back(coin);
	}
	for (auto& elem : coinWallet)
	{
		int num = amount / elem.value;
		elem.count = num;
		totalCount2 += num;
		amount = amount % elem.value;

		cout << elem.value << "원의 수 : " << elem.count << endl;
	}
	cout << "동전의 총 갯수 : " << totalCount2 << endl;
	

	int totalCount = 0;

	for (int coin : coins)
	{
		int num = amount / coin;
		totalCount += num;
		amount = amount % coin;
		cout << coin << "원의 수 : " << num << endl;
	}

	cout << "동전의 총 갯수 : " << totalCount << endl;	

	//int remain = amount;
    //int a = remain / 500;
	//cout << "500원의 수 : " << a << endl;

	//remain = remain - a * 500;
	//int b = remain / 100;
	//cout << "100원의 수 : " << b << endl;

	//remain -= 100 * b;
	//int c = remain / 50;
	//cout << "50원의 수 : " << c << endl;

	//remain -= 50 * c;
	//int d = remain / 10;
	//cout << "10원의 수 : " << d << endl;

	//int totalCount = a + b + c + d;
	//cout << "동전의 총 갯수 : " << totalCount << endl;

	return totalCount;	
}

int meetingCount(int n)
{
	std::vector<std::pair<int, int>> meeting = { {4,1},{5,3},{6,0},{7,5},{8,3},{9,5},{10,6},{11,8},{12,8},{13,2},{14,12} };

	std::sort(meeting.begin(), meeting.end());

	for (auto& i : meeting)
	{
		cout  << i.first << ", "  << i.second << "||";
	}

	int count = 1;
	int time = meeting[0].first;

	for (int i = 1;i < n;i++)
	{
		if (time <= meeting[i].second)
		{
			count++;
			time = meeting[i].first;
		}
	}
	return count;
}

void FormatTime(int value)
{
	struct TimeV
	{
		int value;
		int count;

		TimeV(int _value) : value(_value) {}
	};
	std::vector<int> times = { 3600,60,1 };
	std::vector<TimeV> T;
	for (int T : times)
	{
		times.emplace_back(T);
	}
	
	for (auto& time : times)
	{
		int num = value / time.value;
		value %= time;
	}
	
}

int main()
{
	int a = 1366;
	cout << "동전 거슬러주기 문제 : " << a << "원을 반환해주세요" << endl;
	cout << "=== 결과값 ===" << endl;
	CoinBack(a);

	cout << "\n\n회의실 최대 갯수 문제" << endl;
	cout << "정답 : " << meetingCount(11) << endl;

	cout << "값을 시간으로 변환하는 문제" << endl;
	FormatTime();
}