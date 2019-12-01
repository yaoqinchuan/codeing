/*斐波那契数列
描述：1 1 2 3 5 8 13 21 .....
求第n个数字是多少？
分析：f(n)=f(n-1)+f(n-2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int Fibonacci(int n) {
    if (n==1) {
        return 1;
    }
    if (n==2) {
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int Fibonacci_dp(int n) {
    int *f=(int *)malloc(sizeof(int)*n);
    memset(f,0,sizeof(int)*n);
    f[0]=1;
    f[1]=1;
    if (n<2) {
        return f[n];
    }
    for (int i=2;i<n;i++) {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1];
}
int main(){
    int number=3;
    int ans=Fibonacci(number);
    printf("%d",ans);
    getchar();
}