/*
题目：堆排序
1、大根堆
2、小根堆
*/

#include <stdio.h>
#include <stdlib.h>
void swap(int *tree, int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
void heapify(int *tree, int n, int i)
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
int main(){
    int tree[] = {4, 10, 3, 5, 1, 2};
    int n = 6;
    heapify(tree, n , 0);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tree[i]);
    }
    return 1;
}