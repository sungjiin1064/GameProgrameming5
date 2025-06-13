
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 시간 복잡도 계산하기

void Test1()
{
	int sum = 0;

	int n = 0;
	cin >> n;

	for (int i = 1; i <= 5; i++)
	{
		sum += i;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += i * j;
		}
	}
}

#pragma endregion

std::vector<int> solution(std::vector<int> nums)
{
	std::vector<int> answer;
	std::sort(nums.begin(), nums.end());
	answer = nums;

	return answer;
}

#pragma region 버블 정렬

void bubblesort(int arr[],int n)
{
	// 사이클이 몇 번 돌아야하는가?
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	// 사이클 마다 무엇을 해야하는가?

	// 1. 배열 요소씨리 비교를 한다.
	// 2. (k번쨰) (k+1) 큰 경우에 배열 요소를 변경한다.
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void bubblesort(std::vector<int> nums)
{
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = 0; j < nums.size() - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				//std::swap(nums[j], nums[j + 1]);
				int temp;
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j + 1] = temp;
			}
		}
	}

	for (int n : nums)
	{
		cout << n << " ";
	}
}

#pragma endregion

#pragma region 선택 정렬

void SelectionSort(int arr[], int n)
{	
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		if (i != min_idx)
		{
			swap(arr[i], arr[min_idx]);
		}
	}
	for (int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}

void SelectionSort(std::vector<int> nums)
{
	// for 반복문 표현, j의 값 i+1..
	for (int i = 0; i < nums.size(); i++)
	{
		for(int i=i+1;i<nums.size())
	}

		//arr[min_idx] arr[j]비교해서 작으면 너가 최소값.
	int n = nums.size();

	// arr[j]의 값과 가장 작은 값(index) arr[min]

	// swap   arr[값] arr[min]

}

#pragma endregion

#pragma region 삽입 정렬
#pragma endregion

void Execute()
{
	std::vector<int> nums = { 1,3,7,5,4,8 };

	auto v = solution(nums);

	for (auto& elem : v)
	{
		cout << elem<<" ";
	}
}

int main()
{
	//Execute();

	/*cout << "버블정렬 코드예시" << endl;

	int arr[5] = { 2,6,3,9,8 };

	bubblesort(arr, 5);

	cout << "버블정렬 코드예시2" << endl;
	std::vector<int> nums = { 9,7,4,6 };
	bubblesort(nums);*/

	cout << "선택정렬 코드예시" << endl;
	int arr2[5] = {5,4,3,2,1};
	SelectionSort(arr2, 5);
}