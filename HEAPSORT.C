#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    while (l < n && a[l] > a[largest]) {
        largest = l;
    }
    while (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void print(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void heapsort(int a[], int n) {
    int i;
    // Create max heap
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Sort using deletion
    for (i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n, i;
    clock_t st, et;
    float ts;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    // Dynamically allocate the array
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate random values and place them in the array
    for (i = 0; i < n; i++) {
        a[i] = rand();
    }

    st = clock();
    heapsort(a, n);
    et = clock();
    ts = (float)(et - st) / CLOCKS_PER_SEC;

    if (n <= 20) {
        printf("\nAfter sorting elements are\n");
        print(a, n);
    }

    // Free dynamically allocated memory
    free(a);

    printf("\nTime taken: %f seconds\n", ts);
    return 0;
}
