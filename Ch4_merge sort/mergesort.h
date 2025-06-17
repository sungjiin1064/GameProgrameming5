#pragma once
#include <iostream>
#include <vector>


void merge(int arr[], int n, int left, int mid, int right)
{
	std::vector<int> sorted;
	sorted.assign(n, 0);
	int i = left;
	int j = mid+1;
	int k = left;      // 정렬된 인덱스에서 가장 첫번째 인덱스 번호

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}

	if (i > mid)
	{
		for (int t = j; t <= right;t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}

	for (int t = left; t <= right; t++)
	{
		arr[t] = sorted[t];
	}
}



void mergesort(int arr[], int n, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergesort(arr, n, left, mid);     // 왼쪽 부분
		mergesort(arr, n, mid +1,right);  // 오른쪽 부분

		merge(arr, n, left, mid, right);

	}
}