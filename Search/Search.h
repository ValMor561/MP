#pragma once
#include <iostream>
#include <vector>
template<typename T>
int SimpleSearch(T* arr, T key, size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == key)
			return i;
	}
	return -15;
}

template<typename T>
int BinSearch(T* arr, T key, size_t n)
{
	int	left = 0;
	int right = n;
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;	
	}
	return -15;
}

int min(int x, int y) { return (x <= y) ? x : y; }

template<typename T>
int FibSearch(T* arr, T x, size_t n)
{
	int fibM2 = 0;
	int fibM1 = 1;
	int fibM = fibM2 + fibM1;
	while (fibM < n) {
		fibM2 = fibM1;
		fibM1 = fibM;
		fibM = fibM2 + fibM1;
	}
	int offset = -1;
	while (fibM > 1) {
		int i = min(offset + fibM2, n - 1);
		if (arr[i] < x) {
			fibM = fibM1;
			fibM1 = fibM2;
			fibM2 = fibM - fibM1;
			offset = i;
		}
		else if (arr[i] > x) {
			fibM = fibM2;
			fibM1 = fibM1 - fibM2;
			fibM2 = fibM - fibM1;
		}
		else
			return i;
	}
	if (fibM1 && arr[offset + 1] == x)
		return offset + 1;
	return -15;
}

template<typename T>
int InterpolSearch(T* arr, T key, size_t n)
{
	int low = 0;
	int hight = n - 1;
	int mid;
	while (arr[low] <= key && key <= arr[hight])
	{
		mid = low + ((key - arr[low])* (hight - low) / (arr[hight] - arr[low]));
		if (arr[mid] < key) 
			low = mid + 1;
		else if (arr[mid] > key) 
			hight = mid - 1;
		else 
			return mid;
	}
	if (arr[low] == key) 
		return low;
	else return -15;
}

template<typename T>
int IndexSearch(T* arr, T key, size_t n)
{
	int m = 50000;
	int i,res, offset;
	std::vector<T> kindex;
	std::vector<int> pindex;
	for (i = m -1; i < n; i += m)
	{
		pindex.push_back(i);
		kindex.push_back(arr[i]);
	}
	int size = pindex.size() - 1;
	for (i = 0; i < size; ++i)
	{
		if (kindex[i] >= key)
			break;
	}
	offset = i == 0 ? 0 : pindex[i - 1] + 1;
	res = BinSearch<T>(arr + offset, key, m);
	return (res == -15 ? -15 : res + (i)*m);
}
