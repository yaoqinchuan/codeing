/*
题目：给定一个字符串ThisIsAnTest,翻转该字符串的结果为sihTsInAtseT。
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
char * reverse_string(char *string,int len) {
   char * test=(char *)malloc((len+1));
   memcpy(test,string,len+1);
   char *p=&test[1];
   int word_len=0;
   while(*p !='\0') {
       word_len=0;
       while((*p<='z') && (*p !='\0')&&(*p>='a')) {
           word_len++;
           p++;
       }
       if (*p =='\0') {
            char tmp;
             for (int i=0;i<word_len/2+1;i++) {
                tmp=*(p-word_len-1+i);
                 *(p-word_len-1+i)=*(p-i-1);
                 *(p-i-1)=tmp;
             }
       }
       else
       {
            char tmp;
             for (int i=0;i<word_len/2+1;i++) {
                tmp=*(p-word_len-1+i);
                 *(p-word_len-1+i)=*(p-i-1);
                 *(p-i-1)=tmp;
             }
            p++;
       }
       
   }
   return test;
}
int main(){
    char *string ="ThisIsAnTest";
    char *ans = reverse_string(string,strlen(string));
    printf("%s",ans);
    getchar();
    return 0;
}