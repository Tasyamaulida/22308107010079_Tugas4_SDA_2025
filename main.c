#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "utils.h"

#define MAX_DATA 2000000
#define WORD_MAX_LENGTH 25

void cetak_tabel_benchmark(const char* jenis_data, int jumlah_data,
    double t_bubble, double t_selection, double t_insertion,
    double t_merge, double t_quick, double t_shell,
    double mem_MB)
{
    printf("\n>>> Benchmark untuk %d %s\n\n", jumlah_data, jenis_data);
    printf("+---------------+-------------+----------------+-------------+\n");
    printf("|   Algoritma   | Jumlah Data | Waktu Eksekusi | Memori (MB) |\n");
    printf("+---------------+-------------+----------------+-------------+\n");
    printf("| BubbleSort    | %11d | %14.3f | %10.2f |\n", jumlah_data, t_bubble, mem_MB);
    printf("| SelectionSort | %11d | %14.3f | %10.2f |\n", jumlah_data, t_selection, mem_MB);
    printf("| InsertionSort | %11d | %14.3f | %10.2f |\n", jumlah_data, t_insertion, mem_MB);
    printf("| MergeSort     | %11d | %14.3f | %10.2f |\n", jumlah_data, t_merge, mem_MB);
    printf("| QuickSort     | %11d | %14.3f | %10.2f |\n", jumlah_data, t_quick, mem_MB);
    printf("| ShellSort     | %11d | %14.3f | %10.2f |\n", jumlah_data, t_shell, mem_MB);
    printf("+---------------+-------------+----------------+-------------+\n");
}

void proses_data_angka(int *original_angka, int jumlah_data) {
    double mem_MB = (jumlah_data * sizeof(int)) / (1024.0 * 1024.0);

    int *a = copy_array(original_angka, jumlah_data);
    double t_bubble = time_sort(bubble_sort, a, jumlah_data);
    free(a);

    int *b = copy_array(original_angka, jumlah_data);
    double t_selection = time_sort(selection_sort, b, jumlah_data);
    free(b);

    int *c = copy_array(original_angka, jumlah_data);
    double t_insertion = time_sort(insertion_sort, c, jumlah_data);
    free(c);

    int *d = copy_array(original_angka, jumlah_data);
    double t_merge = time_sort(merge_sort, d, jumlah_data);
    free(d);

    int *e = copy_array(original_angka, jumlah_data);
    double t_quick = time_sort(quick_sort, e, jumlah_data);
    free(e);

    int *f = copy_array(original_angka, jumlah_data);
    double t_shell = time_sort(shell_sort, f, jumlah_data);
    free(f);

    cetak_tabel_benchmark("angka", jumlah_data, t_bubble, t_selection, t_insertion, t_merge, t_quick, t_shell, mem_MB);
}

void proses_data_kata(char **original_kata, int jumlah_data) {
    double mem_MB = (jumlah_data * WORD_MAX_LENGTH) / (1024.0 * 1024.0);

    char **a = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_bubble = time_sort_str(bubble_sort_str, a, jumlah_data);
    free_words(a, jumlah_data);

    char **b = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_selection = time_sort_str(selection_sort_str, b, jumlah_data);
    free_words(b, jumlah_data);

    char **c = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_insertion = time_sort_str(insertion_sort_str, c, jumlah_data);
    free_words(c, jumlah_data);

    char **d = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_merge = time_sort_str(merge_sort_str, d, jumlah_data);
    free_words(d, jumlah_data);

    char **e = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_quick = time_sort_str(quick_sort_str, e, jumlah_data);
    free_words(e, jumlah_data);

    char **f = copy_words(original_kata, jumlah_data, WORD_MAX_LENGTH);
    double t_shell = time_sort_str(shell_sort_str, f, jumlah_data);
    free_words(f, jumlah_data);

    cetak_tabel_benchmark("kata", jumlah_data, t_bubble, t_selection, t_insertion, t_merge, t_quick, t_shell, mem_MB);
}

int main() {
    int *original_angka = malloc(sizeof(int) * MAX_DATA);
    char **original_kata = malloc(sizeof(char *) * MAX_DATA);
    for (int i = 0; i < MAX_DATA; i++) original_kata[i] = malloc(WORD_MAX_LENGTH);

    load_data("data_angka.txt", original_angka, MAX_DATA);
    load_words("data_kata.txt", original_kata, MAX_DATA);

    int pilihan;
    printf("===== MENU BENCHMARK SORTING =====\n");
    printf("1. Jalankan benchmark DATA ANGKA\n");
    printf("2. Jalankan benchmark DATA KATA\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);

    int ukuran[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
    int total = sizeof(ukuran) / sizeof(ukuran[0]);

    for (int i = 0; i < total; i++) {
        if (pilihan == 1)
            proses_data_angka(original_angka, ukuran[i]);
        else if (pilihan == 2)
            proses_data_kata(original_kata, ukuran[i]);
    }

    free(original_angka);
    free_words(original_kata, MAX_DATA);
    return 0;
}