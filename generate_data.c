#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_random_numbers(const char *filename, int count, int max_value) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Gagal membuka file angka");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num = rand() % max_value;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("Berhasil membuat %s\n", filename);
}

void random_word(char *word, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        word[i] = charset[key];
    }
    word[length] = '\0';
}

void generate_random_words(const char *filename, int count, int max_length) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Gagal membuka file kata");
        return;
    }

    srand(time(NULL) + 1);  // seed berbeda dari angka
    char word[100];
    for (int i = 0; i < count; i++) {
        int length = (rand() % (max_length - 3)) + 3; // panjang minimal 3
        random_word(word, length);
        fprintf(fp, "%s\n", word);
    }

    fclose(fp);
    printf("Berhasil membuat %s\n", filename);
}

int main() {
    int jumlah = 2000000;
    generate_random_numbers("data_angka.txt", jumlah, 2000000);
    generate_random_words("data_kata.txt", jumlah, 20);
    return 0;
}
