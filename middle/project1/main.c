#include <stdio.h>
#include <stdlib.h>
int if_appear_before(char c,int position,char *p) { 
    for (int i=0;i<position;i++) {
        if (c==*(p-position+i)) {
            return 1;
        }
    }
    return 0;
}
int lengthOfLongestSubstring(char * s){
    if (strlen(s)==1||strlen(s)==0){
        return strlen(s);
    }
    int *sub_str_len=(int *)malloc(strlen(s));
    memset(sub_str_len,0,strlen(s));
    sub_str_len[0]=1;
    int max_len=1;
    for (int i=1;i<strlen(s);i++) {
        if(if_appear_before(s[i],sub_str_len[i-1],s+i)==1) {
            sub_str_len[i]=1;
            printf("0sub_str_len[%d]=%d\n",i,sub_str_len[i]);
        }else
        {
            sub_str_len[i]=sub_str_len[i-1]+1;
            printf("1sub_str_len[%d]=%d\n",i,sub_str_len[i]);
        }
        if (max_len<sub_str_len[i]) {
            max_len=sub_str_len[i];
        }
    }
    return max_len;
}
int main(){
    char *str="abcabcbb";
    int max_sum_ans=lengthOfLongestSubstring(str);
    printf("%d",max_sum_ans);
    getchar();
    return 0;
}
int find_root(int x, int *parent)
{
    int root = x;
    while(root != parent[root]) {
        root = parent[root];
        parent[root] = parent[parent[root]];
    }
    return root;
}
int union_root(int x, int y, int *parent)
{
    int root1 = find_root(x, parent);
    int root2 = find_root(y, parent);
    if (root1 != root2) {
        parent[root2] = root1;
        return 1;
    }
    return 0;
}
#define MAX_LEN 20
int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int parent[MAX_LEN] = { 0 };
    int flag[MAX_LEN] = { 0 };
    int count = 0;
    for(int i = 0; i < MAX_LEN; i++) {
        parent[i] = i;
     }
    for(int i = 0; i < stonesSize; i++) {
        for(int j = i + 1; j < stonesSize; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                union_root(i, j, parent);
            }
        }
    }
    for(int i = 0; i < MAX_LEN; i++) {
        printf("%d \r\n", parent[i]);
    }
    printf("\r\n");
    for(int i = 0; i < MAX_LEN; i++) {
        if (parent[i] != i) {
            flag[i] = 1;
        }
    }
    for(int i = 0; i < MAX_LEN; i++) {
        if (flag[i] != 0) {
            count++;
        }
    }
    printf("%d",count);
    return stonesSize - count;
}