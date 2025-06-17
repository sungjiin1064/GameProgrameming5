#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

void quicksort(std::vector<int>, int start,int end)
{

}



int main()
{
	/*int n;
	cin >> n;

	std::vector<int> list;
	list.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << list[i] << endl;
	}*/

	cout << "병합 정렬 배열 버전" << endl;
	int arr[6] = { 3,4,7,5,2,8 };
	mergesort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i]<<" ";
	}

	cout << endl;
	cout << "병합 정렬 백터 버전" << endl;
}