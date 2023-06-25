#include <stdio.h>

int data[10] = {31, 41, 59, 26, 53, 58, 97, 93, 23, 84};
int nitems = 10;

int median3(int x, int y, int z, int (*compare)(int, int)) {
    if (compare(x,y)) {
        return compare(y,z) ? y
        : compare(x,z) ? z
        : x;
    } else {
        return compare(x,z) ? x
        : compare(y,z) ? z
        : y;
    }
}

void swap (int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int array[], int l, int r, int (*compare)(int, int)) {
    int pivot = median3(array[l], array[r], array[(l+r)/2], compare);
    //  printf(" pivot = %d =med(%d %d %d)\n",pivot,array[l], array[r], array[(l+r)/2]);

    while (1) {
        while (compare(array[l], pivot)) l++;
        while (compare(pivot, array[r])) r--;
        //  printf(" (l,r) = (%d,%d)\n",l,r);
        if (l > r) return l;
        
        swap(&array[l], &array[r]);
        l++; r--;
    }
}

void quick_sort(int array[], int l, int r, int (*compare)(int, int)) {
    //  int i;
    if (l >= r) return;
    //  for (i=0; i<nitems; i++) printf(" %d", data[i]); printf(" [%d,%d]\n",l,r);
    int p = partition(array, l, r, compare);
    //  printf("p = %d\n", p);
    quick_sort(array, l, p-1, compare);
    quick_sort(array, p, r, compare);
}

int isAscending(int a, int b) {
    return a < b ? 1 : 0;
}

int main() {
    int i;
    printf("入力:"); for (i=0; i<nitems; i++) printf(" %d", data[i]); printf("\n");

    quick_sort(data, 0, nitems-1, isAscending);

    printf("結果:"); for (i=0; i<nitems; i++) printf(" %d", data[i]); printf("\n");
    return 0;
}