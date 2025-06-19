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

void LinearSearch(int arr[],int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if(arr[i] == target)
		{
			cout << "해당하는 데이터 : " << target << " 를 찾았습니다." << endl;
			return;
		}		
	}
	cout << "데이터를 찾지 못했습니다." << endl;
}

void LinearSearch(std::vector<int> arr, int target)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			cout << "해당하는 데이터 : " << target << " 를 찾았습니다." << endl;
			return;
		}
	}
	cout << "데이터를 찾지 못했습니다." << endl;
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
			cout << "해당하는 데이터 : " << target << " 를 찾았습니다." << endl;
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
	cout << "데이터를 찾지 못했습니다." << endl;
}

void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{	
	if (left > right)
	{
		cout << "데이터를 찾지 못했습니다." << endl;
		return;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == target)
	{
		cout << "해당하는 데이터 : " << target << " 를 찾았습니다." << endl;
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
	* 1.반환하는 값을 bool타입으로 변경해보세요.
	* 2.LinearSearch(vector<int> -> vector<pair<int, string>>버전으로 변경해보세요.
	* 3.userID를 사용해서 유저의 닉네임을 출력하는 코드를 완성해보세요.
	*/

	LinearSearch(temp, 4);
	cout << "데이터가 존재합니다 : (" << data[4].second << ")" << endl;
}

bool UserDataSearch(std::vector<std::pair<int, string>>data, int userID)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].first == userID)
		{
			cout << "닉네임 : "<< data[i].second <<endl;
			return true;
		}
	}
	cout << "유저 아이디에 해당하는 데이터가 없습니다." << endl;
	return false;

}

int main()
{
	cout << "배열로 구현한 선형 탐색" << endl;

	int arr[5] = { 0,5,2,4,9 };
	LinearSearch(arr, 5, 2);

	cout << endl;
	cout << "백터로 구현한 선형 탐색" << endl;
	std::vector<int> data = { 0,5,2,4,9 };
	LinearSearch(data,2);

	cout << endl;
	cout << "배열로 구현한 이진 탐색" << endl;
	int arr2[5] = { 0,2,4,5,9 };	
	BinarySearch(arr2, 5, 2);

	/*cout << endl;
	cout << "배열로 구현한 이진 탐색" << endl;
	std::vector<int> data1 = { 0,2,4,5,9 };
	BinarySearch(data1, 2);*/

	cout << endl;
	cout << "유저 아이디로 닉네임 검색하기 예제" << endl;
	std::vector<std::pair<int, string>> data3;
	data3.push_back({ 0,"AAA" });
	data3.push_back({ 1,"BBB" });
	data3.push_back({ 2,"CCC" });
	data3.push_back({ 3,"DDD" });
	if (UserDataSearch(data3, 3))
	{
		data3[3].second = "EEE";
	}
	
}