#include <iostream>
#include<vector>

void merge_sort(int* arr, int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
   
    int* left = new int[mid];

    int* right = new int[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int j = mid; j < size; j++) {
        right[j-mid] = arr[j];
    }
    for (int j = 0; j < mid; j++) {
        for (int i = 0; i < mid-1; i++) {
            if (left[i] > left[i + 1]&&i!= mid-1) {
                int num = left[i];
                left[i] = left[i + 1];
                left[i + 1] = num;
            }
            if (right[i] > right[i + 1] && i != mid - 1) {
                int num = right[i];
                right[i] = right[i + 1];
                right[i + 1] = num;
            }
        }
    }
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < mid) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size-mid) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

int main() {
    int arr1[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size = sizeof(arr1) / sizeof(arr1[1]);
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr1[i];
    }
    std::cout << "\n";
    merge_sort(arr1, size);
    
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr1[i];
    }
}
