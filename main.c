#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 0
#define MAX 5
#define TAB_SIZE 10

void fillTab(int *tab, int min, int max);

int sumaTab(int *tab);

float sredniaTab(int *tab);

void generujHistogram(int *tab, int *histogram);

void wypiszTab(int *tab);

void wypiszStats(int *tab, int suma, float srednia, int *histogram);

int sum = 0;
float avg = 0;

int main() {
    int tablica[TAB_SIZE];
    int histogram[(MAX - MIN)];
    for (int i = 0; i <= (MAX - MIN); i++) {
        histogram[i] = 0;
    }
    fillTab(tablica, MIN, MAX);
    wypiszTab(tablica);
    sumaTab(tablica);
    sredniaTab(tablica);
    generujHistogram(tablica, histogram);
    wypiszStats(tablica, sum, avg, histogram);
}

void fillTab(int *tab, int min, int max) {
    srand(time(0));
    for (int i = 0; i < TAB_SIZE; i++) {
        tab[i] = min + rand() % (max + 1);
    }
}

void wypiszTab(int *tab) {
    printf("\n[");
    for (int i = 0; i < TAB_SIZE; i++) {
        printf(" %d", tab[i]);
    }
    printf(" ]\n");
}

int sumaTab(int *tab) {
    for (int i = 0; i < TAB_SIZE; i++) {
        sum = sum + tab[i];
    }
}

float sredniaTab(int *tab) {
    avg = sum / (float) TAB_SIZE;
}

void generujHistogram(int *tab, int *histogram) {
    for (int i = 0; i < TAB_SIZE; i++) {
        histogram[tab[i]] = histogram[tab[i]] + 1;
    }
}

void wypiszStats(int *tab, int suma, float srednia, int *histogram) {
    printf("Suma elementow tabeli: %i\n", suma);
    printf("Średnia elementów tabeli: %0.1f\n", srednia);
    printf("Histogram: \n");
    for (int i = 0; i <= (MAX - MIN); i++) {
        printf("%d -> %d \n", i, histogram[i]);
    }
}
