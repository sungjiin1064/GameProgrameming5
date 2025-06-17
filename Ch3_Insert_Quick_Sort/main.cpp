
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)  // ��� cycle���ƾ��ϳ���
	{
		int key = arr[i]; //���� ��
		
		int j = i - 1; //  key�� �� ���� ���� ��

		while (j>=0 && arr[j] > key)  // j�� ���� 0���� ũ�ų� ���� ���� key���� Ŭ�� ���� �ε����� ���� 0���� Ŭ��
		{
			arr[j + 1] = arr[j];   // ������ �����Ϳ� ���� ���� �������� ��ġ�� �����ض�
			j--;                   // ���� key�� ��ġ
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

#pragma region �� ����

void quickSort(int data[], int start, int end)
{
	if (start >= end) // �����Ͱ� 1���� ���� ��, ��� �Լ��� ������ ���� ����
	{
		return;
	}

	int pivot = start;  // ���� ��
	int i = start + 1;  // ���ʿ��� ���� �� ��ġ
	int j = end;        // �����ʿ��� ���� �� ��ġ
	int temp;           // swap ����ϱ� ����

	while (i <= j)
	{
		while (data[i] >= data[pivot]) // �ǹ����� ū���� ������ ����  �� ���� ã�ƶ�
		{
			i++; // ���� �� ��� i�� �����ض�
		}
		while (j > start && data[j] <= data[pivot]) // �ǹ����� �������� ������ �� ���� �����ض�
		{
			j--; // j�� ���� �������ִ� �ڵ�
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

		// quickSort(������Ʈ)     quickSort(��������Ʈ)
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
	cout << "���� ���� �迭 ����" << endl;
	int arr1[10] = { 4,3,6,5,8,10,9,7,1,2 };
	InsertSort(arr1,10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl;
	cout << "���� ���� ���� ����" << endl;
	std::vector<int> nums1 = { 4,3,6,5,8,10,9,7,1,2 };
	InsertSort(nums1);
	for (int n : nums1)
	{
		cout << n << " ";
	}
	
	cout << endl;
	cout << "�� ���� �迭 ����" << endl;
	int arr2[10] = { 4,3,6,5,8,10,9,7,1,2 };
	quickSort(arr2, 0, 9);
	for (int n : arr2)
	{
		cout << n << " ";
	}

	/*cout << endl;
	cout << "�� ���� ���� ����" << endl;
	std::vector<int> nums2 = { 4,3,6,5,8,10,9,7,1,2 };
	quickSort(nums2, 0, nums2.size()-1);
	for (int num : nums2)
	{
		cout << num << " ";
	}*/
}