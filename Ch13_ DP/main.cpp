#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int Fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int FinoDP(int n)
{
	if (n <= 1) return n;
	std::vector<int> dp(n + 1, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

//int FiboDP(int n)
//{
//	if (n <= 1) return
//}

class FiboRecursive
{
private:
	std::vector<int> dp;

public:
	FiboRecursive(int n)
	{
		dp.resize(n + 1, -1);
		dp[0] = 0;
		dp[1] = 1;
	}

	int FiboRecur(int n)
	{
		if (dp[n] != -1)
		{
			return dp[n];
		}

		dp[n] = FiboRecur(n - 1) + FiboRecur(n - 2);

		return dp[n];
	}
};

class GameCache
{
private:

	struct UserData
	{
		int level;
		int exps;
		int damage;
	};

	std::unordered_map<int, int> exps;
	std::unordered_map<int, int> damage;

	//std::unordered_map<int, UserData> exps;
	//std::unordered_map<int, UserData> damage;

public:
	int CalculateDanage(int level)
	{
		if (damage.find(level) != damage.end())
		{
			cout << "�ɽÿ��� �����͸� ������" << "(���� " << " : " << damage[level] << endl;
			return damage[level];
		}

		int damages = level * (level + 1);
		damage[level] = damages;
		return damages;

	}

	int CalculateExp(int level)
	{
		if (exps.find(level) != exps.end())
		{
			cout << "ĳ�ÿ��� �����͸� ������" << "(���� " << level << " : " << exps[level] << endl;
			return exps[level];
		}

		int exp = level * (level + 100);
		exps[level] = exp;
		return exp;
	}

};

int CountStep(int n)
{
	std::vector<int> dp(n + 1, -1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2;i <= n;i++)
	{
		dp[n] = dp[n - 1] + dp[n - 2];
	}

	return dp[n];

}

int main()
{
	cout << "===== �Ǻ���ġ ��� ���� =====" << endl;

	cout << "��� �� : " << Fibonacci(2) << endl;

	cout << "�Ǻ���ġ�� 25��° ���ڸ� ����غ�����." << Fibonacci(25) << endl;

	cout << "===== �Ǻ���ġ DP bottom up ���� =====" << endl;
	cout << "��� �� : " << FinoDP(6) << endl;

	//int count = 0;
	//cout << "n��° ������ �Է����ּ���" << endl;
	//cout << "" << endl;

	//FiboRecursive fibo(6);
	//cout << "��� �� : " << fibo.FiboRecur(6) << endl;


	//cout << "��� ������ ����� �� ���" << endl;

	//cout << "n��° ����� ������ ���� �ʿ��� ����� �� :"<< CountStep(5) << endl;

	//cout << "���� ĳ�� ������ ����" << endl;

	//GameCache gameCache;

	//cout << "1���� ����ġ : " << gameCache.CalculateExp(1);
	//cout << "1���� ����ġ : " << gameCache.CalculateExp(1);	

}
// (06-30)������ȹ���� ���� �̷а� ���� ����