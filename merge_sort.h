#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Merge Sort: Divide and conquer; membagi array dan menggabungkannya secara terurut
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void merge_sort_recursive(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort_recursive(arr, l, m);
        merge_sort_recursive(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge_sort(int arr[], int n) {
    merge_sort_recursive(arr, 0, n - 1);
}
// Merge Sort untuk string
void merge_str(char **arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char **L = malloc(sizeof(char *) * n1);
    char **R = malloc(sizeof(char *) * n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = strcmp(L[i], R[j]) <= 0 ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void merge_sort_str_recursive(char **arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort_str_recursive(arr, l, m);
        merge_sort_str_recursive(arr, m + 1, r);
        merge_str(arr, l, m, r);
    }
}

void merge_sort_str(char **arr, int n) {
    merge_sort_str_recursive(arr, 0, n - 1);
}

#endif
