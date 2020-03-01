/*
题目：给定一个整形字符串，求出最大的子串和
思路：一道简单的dp问题，只要当前的子串的和不为负值就有加的意义
       |sum[n-1]+num[i] if sum[n-1]>0;
sum[n]=|
       |num[i]          if sum[n-1]<0;
max_sum=max{sum[1],sum[2],...sum[n]};
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int max_sum(int* num,int numbers) {
    int max_value=num[0];
    int *sum=(int*)malloc(sizeof(int)*numbers);
    sum[0]=0;
    for (int i=1;i<numbers;i++) {
        if (sum[i-1]>0) {
            sum[i]=sum[i-1]+num[i];
        }else
        {
            sum[i]=num[i];
        }
        if(sum[i]>max_value){
            max_value=sum[i];
        }   
    }
    return max_value;
}
int main(){
    int numbers[8]={1,2,-1,-2,5,7,-2,3};
    int max_sum_ans=max_sum(numbers,8);
    return 0;
}