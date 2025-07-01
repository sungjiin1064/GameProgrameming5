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
			cout << "케시에서 데이터를 가져옴" << "(레벨 " << " : " << damage[level] << endl;
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
			cout << "캐시에서 데이터를 가져옴" << "(레벨 " << level << " : " << exps[level] << endl;
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
	cout << "===== 피보나치 재귀 구현 =====" << endl;

	cout << "결과 값 : " << Fibonacci(2) << endl;

	cout << "피보나치의 25번째 숫자를 출력해보세요." << Fibonacci(25) << endl;

	cout << "===== 피보나치 DP bottom up 구현 =====" << endl;
	cout << "결과 값 : " << FinoDP(6) << endl;

	//int count = 0;
	//cout << "n번째 순서를 입력해주세요" << endl;
	//cout << "" << endl;

	//FiboRecursive fibo(6);
	//cout << "결과 값 : " << fibo.FiboRecur(6) << endl;


	//cout << "계던 오르기 경우의 수 출력" << endl;

	//cout << "n번째 계단을 오르기 위한 필요한 경우의 수 :"<< CountStep(5) << endl;

	//cout << "게임 캐싱 데이터 예제" << endl;

	//GameCache gameCache;

	//cout << "1레벨 경험치 : " << gameCache.CalculateExp(1);
	//cout << "1레벨 경험치 : " << gameCache.CalculateExp(1);	

}
// (06-30)동적계획법에 대한 이론과 예제 문제