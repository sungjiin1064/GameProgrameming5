
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region �ð� ���⵵ ����ϱ�

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

#pragma region ���� ����

void bubblesort(int arr[],int n)
{
	// ����Ŭ�� �� �� ���ƾ��ϴ°�?
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
	// ����Ŭ ���� ������ �ؾ��ϴ°�?

	// 1. �迭 ��Ҿ��� �񱳸� �Ѵ�.
	// 2. (k����) (k+1) ū ��쿡 �迭 ��Ҹ� �����Ѵ�.
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

#pragma region ���� ����

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
	// for �ݺ��� ǥ��, j�� �� i+1..
	for (int i = 0; i < nums.size(); i++)
	{
		for(int i=i+1;i<nums.size())
	}

		//arr[min_idx] arr[j]���ؼ� ������ �ʰ� �ּҰ�.
	int n = nums.size();

	// arr[j]�� ���� ���� ���� ��(index) arr[min]

	// swap   arr[��] arr[min]

}

#pragma endregion

#pragma region ���� ����
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

	/*cout << "�������� �ڵ忹��" << endl;

	int arr[5] = { 2,6,3,9,8 };

	bubblesort(arr, 5);

	cout << "�������� �ڵ忹��2" << endl;
	std::vector<int> nums = { 9,7,4,6 };
	bubblesort(nums);*/

	cout << "�������� �ڵ忹��" << endl;
	int arr2[5] = {5,4,3,2,1};
	SelectionSort(arr2, 5);
}