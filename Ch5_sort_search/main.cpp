#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<typename T1,typename T2>
struct myPair
{
	T1 first;
	T2 second;
};

void UserDataSearch(std::vector<std::pair<int, string>>data, int userID)
{

}

void LinearSearch(int arr[],int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if(arr[i] == target)
		{
			cout << "�ش��ϴ� ������ : " << target << " �� ã�ҽ��ϴ�." << endl;
			return;
		}		
	}
	cout << "�����͸� ã�� ���߽��ϴ�." << endl;
}

void LinearSearch(std::vector<int> arr, int target)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			cout << "�ش��ϴ� ������ : " << target << " �� ã�ҽ��ϴ�." << endl;
			return;
		}
	}
	cout << "�����͸� ã�� ���߽��ϴ�." << endl;
}

void BinarySearch(int arr[],int n, int target)
{
	int i = 0;
	int j = n-1;

	while (i <= j)
	{
		int mid = i + (j - i) / 2; 

		if (arr[mid] == target)
		{
			cout << "�ش��ϴ� ������ : " << target << " �� ã�ҽ��ϴ�." << endl;
			return;
		}
		else if (arr[mid] > target)  
		{
			j = mid - 1;
		}
		else                         
		{
			i = mid + 1;
		}
	}
	cout << "�����͸� ã�� ���߽��ϴ�." << endl;
}

void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{	
	if (left > right)
	{
		cout << "�����͸� ã�� ���߽��ϴ�." << endl;
		return;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == target)
	{
		cout << "�ش��ϴ� ������ : " << target << " �� ã�ҽ��ϴ�." << endl;
		return;
	}
	else if (arr[mid] > target)
	{
		BinarySearchByRecursive(arr, n, target, left, mid - 1);		
	}
	else
	{
		BinarySearchByRecursive(arr, n, target, mid + 1,right);
	}
}

void Example()
{
	std::vector < std::pair<int, string>> data;

	std::pair<int, string> a = { 1,"BBB" };
	data.push_back({ 0,"AAA" });
	data.push_back(a);
	data.push_back(std::make_pair(2, "CCC"));
	data.push_back({ 3,"DDD" });
	data.push_back({ 4,"EEE" });

	std::vector<int> temp;
	for (int i = 0; data.size(); i++)
	{
		temp.push_back(data[i].first);
	}

	/*
	* 1.��ȯ�ϴ� ���� boolŸ������ �����غ�����.
	* 2.LinearSearch(vector<int> -> vector<pair<int, string>>�������� �����غ�����.
	* 3.userID�� ����ؼ� ������ �г����� ����ϴ� �ڵ带 �ϼ��غ�����.
	*/

	LinearSearch(temp, 4);
	cout << "�����Ͱ� �����մϴ� : (" << data[4].second << ")" << endl;
}

int main()
{
	cout << "�迭�� ������ ���� Ž��" << endl;

	int arr[5] = { 0,5,2,4,9 };
	LinearSearch(arr, 5, 2);

	cout << endl;
	cout << "���ͷ� ������ ���� Ž��" << endl;
	std::vector<int> data = { 0,5,2,4,9 };
	LinearSearch(data,2);

	cout << endl;
	cout << "�迭�� ������ ���� Ž��" << endl;
	int arr2[5] = { 0,2,4,5,9 };	
	BinarySearch(arr2, 5, 2);

	/*cout << endl;
	cout << "�迭�� ������ ���� Ž��" << endl;
	std::vector<int> data1 = { 0,2,4,5,9 };
	BinarySearch(data1, 2);*/
}