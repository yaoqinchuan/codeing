/*
题目：堆排序
1、大根堆
2、小根堆
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
void swap(int* tree, int x, int y)
{
    int temp = tree[x];
    tree[x] = tree[y];
    tree[y] = temp;
}
void heapify(int* tree, int n, int i)
{
    int max = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }
    if (max != i) {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
    return;
}
void init_heap(int *tree, int n) 
{
    int k = (n - 2) / 2;
    for (int i = k; i >= 0; i--)
    {
        heapify(tree, n, i);
    }
}
int main() {
    int tree[] = { 2, 5, 3, 1, 10, 4};
    int n = 6;
    init_heap(tree, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(tree, 0, i);
        heapify(tree, i, 0);
        printf("%d ", tree[i]);
    }
    return 1;
}