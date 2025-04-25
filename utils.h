#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==========================
// ======= DATA ANGKA =======
// ==========================

// Load data angka dari file
void load_data(const char *filename, int *arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file angka");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
}

// Copy array angka
int* copy_array(int *src, int n) {
    int *dest = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) dest[i] = src[i];
    return dest;
}

// Hitung waktu sorting angka
double time_sort(void (*sort_fn)(int*, int), int *data, int n) {
    clock_t start = clock();
    sort_fn(data, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// ==========================
// ======= DATA KATA  =======
// ==========================

// Load kata dari file ke array 2 dimensi
void load_words(const char *filename, char **arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file kata");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", arr[i]);
    }

    fclose(fp);
}

// Copy array kata
char **copy_words(char **src, int n, int max_len) {
    char **copy = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        copy[i] = malloc(sizeof(char) * max_len);
        strcpy(copy[i], src[i]);
    }
    return copy;
}

// Bebaskan memori array kata
void free_words(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Hitung waktu sorting kata
double time_sort_str(void (*sort_fn)(char **, int), char **data, int n) {
    clock_t start = clock();
    sort_fn(data, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

#endif
