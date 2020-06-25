#include <stdio.h>
#include <stdlib.h>
void get_next_str(char *ans) {
    char *ans_after =(char *)malloc(10000);
    int k=0;
    (void)memset(ans_after,0,10000);
    ans_after[0]='\0';
    for (int j=0; j<strlen(ans); j++) {
        int count=0;
        ans_after[k] = ans[j];
        while(ans[j] == ans_after[k]) {
            count++;
            j++;
        }
        ans_after[k+1] = ans_after[k];
        ans_after[k] = '0'+count;
        if (j == strlen(ans)-1){
            k+=2;
            ans_after[k] = ans[j];
            ans_after[k+1] = ans_after[k];
            ans_after[k] = '1';
            continue;
        }
        k+=2;
        j--;
    }
    ans_after[k+2]='\0';
    for (int z=0;z<k+3;z++) {
        ans[z]=ans_after[z];
    }
    free(ans_after);
}
char * countAndSay(int n){
    char *ans_before =(char *)malloc(10000);
    (void)memset(ans_before,0,10000);
    ans_before[0]='1';
    ans_before[1]='\0';
    if (n==1){
        return ans_before;
    }
    for (int i=2;i<=n;i++) {
        get_next_str(ans_before);
        printf("%d\n",i);
    }
    return ans_before;
}
int main(){
    char *ans=countAndSay(30);
    printf("%s",ans);
    getchar();
    return 0;
}