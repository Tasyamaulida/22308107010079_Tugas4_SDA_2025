#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// Quick Sort: Memilih pivot dan membagi array ke kiri (lebih kecil) dan kanan (lebih besar)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int n) {
    quick_sort_recursive(arr, 0, n - 1);
}
// Quick Sort untuk string
int partition_str(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char *tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    char *tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quick_sort_str_recursive(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition_str(arr, low, high);
        quick_sort_str_recursive(arr, low, pi - 1);
        quick_sort_str_recursive(arr, pi + 1, high);
    }
}

void quick_sort_str(char **arr, int n) {
    quick_sort_str_recursive(arr, 0, n - 1);
}

#endif
