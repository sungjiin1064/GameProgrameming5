
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)  // 몇번 cycle돌아야하나요
	{
		int key = arr[i]; //현제 값
		
		int j = i - 1; //  key의 값 이전 값과 비교

		while (j>=0 && arr[j] > key)  // j의 값이 0보다 크거나 같을 때만 key값이 클때 도는 인덱스의 값이 0보다 클때
		{
			arr[j + 1] = arr[j];   // 왼쪽의 데이터와 새로 들어온 데이터의 위치를 변경해라
			j--;                   // 현제 key의 위치
		}
		arr[j + 1] = key;
	}
}

void InsertSort(std::vector<int>& nums)
{		
	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		int key = nums[i];
		int j = i - 1;
		while (j>=0 && nums[j]>key)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
	
}

#pragma region 퀵 정렬

void quickSort(int data[], int start, int end)
{
	if (start >= end) // 데이터가 1개만 있을 때, 재귀 함수를 끝내기 위한 조건
	{
		return;
	}

	int pivot = start;  // 기준 값
	int i = start + 1;  // 왼쪽에서 변경 할 위치
	int j = end;        // 오른쪽에서 변경 할 위치
	int temp;           // swap 사용하기 위해

	while (i <= j)
	{
		while (data[i] >= data[pivot]) // 피벗보다 큰값을 만날때 까지  그 값을 찾아라
		{
			i++; // 작은 때 계속 i를 증가해라
		}
		while (j > start && data[j] <= data[pivot]) // 피벗보다 작은값을 만날때 그 값을 선택해라
		{
			j--; // j의 값을 변경해주는 코드
		}
		
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
			//std::swap(data[pivot],data[j])
		}
		else
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			//std::swap(data[i], data[j]);
		}

		// quickSort(왼쪽파트)     quickSort(오른쪽파트)
		quickSort(data, start, j-1); 
		quickSort(data, j+1, end);
	}
}

void quickSort(std::vector<int>& nums, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int pivot = start;  
	int i = start + 1;  
	int j = end;        
	int temp;
	while (i <= j)
	{
		while (nums[i] <= nums[pivot])
		{
			i++;
		}
		while (nums[j] > start && nums[j] >= nums[pivot])
		{
			j--;
		}
		if (i > j)
		{
			temp = nums[j];
			nums[j] = nums[pivot];
			nums[pivot] = temp;
			//std::swap(nums[pivot],nums[j])
		}
		else
		{
			temp = nums[j];
			nums[j] = nums[i];
			nums[i] = temp;
			//std::swap(nums[i], nums[j]);
		}
		quickSort(nums, start, j - 1);
		quickSort(nums, j + 1, end);
	}
}

#pragma endregion

int main()
{
	cout << "삽입 정렬 배열 형식" << endl;
	int arr1[10] = { 4,3,6,5,8,10,9,7,1,2 };
	InsertSort(arr1,10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl;
	cout << "삽입 정렬 백터 형식" << endl;
	std::vector<int> nums1 = { 4,3,6,5,8,10,9,7,1,2 };
	InsertSort(nums1);
	for (int n : nums1)
	{
		cout << n << " ";
	}
	
	cout << endl;
	cout << "퀵 정렬 배열 형식" << endl;
	int arr2[10] = { 4,3,6,5,8,10,9,7,1,2 };
	quickSort(arr2, 0, 9);
	for (int n : arr2)
	{
		cout << n << " ";
	}

	/*cout << endl;
	cout << "퀵 정렬 백터 형식" << endl;
	std::vector<int> nums2 = { 4,3,6,5,8,10,9,7,1,2 };
	quickSort(nums2, 0, nums2.size()-1);
	for (int num : nums2)
	{
		cout << num << " ";
	}*/
}