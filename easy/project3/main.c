/*
题目：给定一个整形数组，求出整形数组中不相邻元素最大的和的值是多少？
[4,1,1,9,1]
当决定是否需要选择最后一个的时候
       |opt[6]   不选7，此时选择6
opt[7]=|
       |opt[5]+num[7]  选择7，6不能选，只能等于选5的最大值
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int max_sum (int *num,int number) {
    int * opt=(int *)malloc(number*sizeof(int));
    memset(opt,0,number*sizeof(int));
    opt[0]=num[0];
    opt[1]=num[1]>num[0]?num[1]:num[0];
    for (int i=2;i<number;i++){
        opt[i]=opt[i-1]>(opt[i-2]+num[i])? opt[i-1]:(opt[i-2]+num[i]);
        opt[i]=opt[i];
        printf("%d,%d\n",i,opt[i]);
    }
    return opt[number-1];
}
int main(){
    int numbers[5]={4,1,1,9,1};
    int sum=max_sum(numbers,5);
   // getchar();
    return 0;
}