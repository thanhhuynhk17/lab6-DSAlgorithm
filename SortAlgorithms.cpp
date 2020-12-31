#include "SortAlgorithms.h"

void SelectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < n; i++)
        {
            if (a[min_index] > a[j]){
                min_index = j;
            }
        }
        HoanVi(a[i], a[min_index]);
    }   
}

#pragma region MergeSort

// Merge 2 sub arrays on the left and right into a[]
// left array:  a[l...m]
// right array: a[m+1...r]
void MergeArray(int a[], int l, int m, int r){
    // Get array size
    int left_size = m - l + 1;
    int right_size = r - (m+1) + 1;
    // Create temp array to store data
    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];
    // Copy data
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = a[l + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = a[(m + 1) + i];
    }

    // variables to track whether left_arr[] or right_arr[] is remain
    int left_tracker = 0;
    int right_tracker = 0;
    int tracker = l;
    while (left_tracker < left_size && right_tracker < right_size)
    {
        // merge left array
        if (left_arr[left_tracker] <= right_arr[right_tracker])
        {
            a[tracker] = left_arr[left_tracker];
            left_tracker++;   
        }else
        {   // merge right array
            a[tracker] = right_arr[right_tracker];
            right_tracker++;   
        }
        tracker++;
    }
    
    // copy the remaining of 2 sub arrays
    while (left_tracker < left_size)
    {
        a[tracker] = left_arr[left_tracker];
        left_tracker++;
        tracker++;
    }
    while (right_tracker < right_size)
    {
        a[tracker] = right_arr[right_tracker];
        right_tracker++;
        tracker++;
    }


    // delete temp array
    if (left_arr){
        delete[] left_arr;
    }
    if (right_arr){
        delete[] right_arr;
    }
}

void MergeSort(int a[], int l, int r){
    if (l >= r){
        return;
    }

    int m = (l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    MergeArray(a, l, m, r);  
}

#pragma endregion

void HeapSort(){

}

void QuickSort(){

}

void BubbleSort(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n-1; i++)
        {
            if (a[j] > a[j+1]){
                HoanVi(a[j], a[j+1]);
            }
        }
    }
}

void InsertionSort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        int key_value = a[i];
        int j = i-1;

        // move all elements have value larger than key value 1 step foward
        while (j >= 0 && a[j] > key_value)
        {
            a[j+1] = a[j];
            j -=1; 
        }
        // insert key value in right place
        a[j+1] = key_value;
    }
}

#pragma region BinaryInsertionSort

// Get index that value should be in
int BinarySearch(int a[], int value, int l, int r){

    if (l >= r){
        // a[l] >= value :  a = [..., value, a[l],... ]
        // a[l] < value :   a = [..., a[l], value,... ]
        return (a[l] > value)?l:(l + 1);
    }
    
    int m = (l+r)/2;
    if (a[m] == value){
        return m+1;
    }
    if (a[m] < value){
        return BinarySearch(a, value, m+1, r);
    }
    return BinarySearch(a, value, l, m - 1);
}

void BinaryInsertionSort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i-1;

        // Get index that value should be in
        int value_idx = BinarySearch(a, value, 0, j);
        // move all elements have value larger than key value 1 step foward
        while (j >= value_idx)
        {
            a[j+1] = a[j];
            j -=1; 
        }
        // insert key value in right place
        a[j+1] = value;
    }

}
#pragma endregion

