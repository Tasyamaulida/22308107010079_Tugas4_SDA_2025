#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

// Selection Sort: Memilih elemen terkecil dari sisa array dan menukarnya ke posisi yang benar
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}
// Selection Sort untuk string
void selection_sort_str(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        char *tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

#endif
