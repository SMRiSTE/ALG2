#include <iostream>

void count_sort(int* arr, int size) {
    int left = 10;
    int right = 24;
    int* counts = new int [left, right]();

    for (int i = 0; i < size; i++) {
        counts[arr[i]] += 1;
    }

    int c = 0;
    for (int i = 0; i < size; i++) {
        while (counts[c] == 0) {
            c += 1;
        }
        arr[i] = c;
        counts[c] -= 1;
    }

}

int main()
{
    int arr[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    int size = sizeof(arr) / sizeof(arr[1]);
    count_sort(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}