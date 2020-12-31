#pragma once

#pragma region helper function
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}
#pragma endregion

void SelectionSort(int a[], int n);

#pragma region MergeSort
void MergeArray(int a[], int l, int m, int r);
void MergeSort(int a[], int l, int r);
#pragma endregion

void HeapSort();
void QuickSort();
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void BinaryInsertionSort(int a[], int n);