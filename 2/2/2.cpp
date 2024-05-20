#include <iostream>

void quick_sort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int pivot = arr[size / 2];

    int left = 0, right = size - 1;
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    quick_sort(arr, right + 1);
    quick_sort(arr + left, size - left);
}

int main() {
    int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before sorting:";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    quick_sort(arr, size);

    std::cout << "After sorting:";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    return 0;
}