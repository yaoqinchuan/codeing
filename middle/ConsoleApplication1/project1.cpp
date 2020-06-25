#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//动态规划
int ipsec_get_max_sub_str(char *s, int s_len,int * max_len) {
	int max_len_position = 0;
	int** dp = (int**)malloc(s_len * sizeof(int*));
	for (int i = 0; i < s_len; i++) {
		dp[i] = (int*)malloc(s_len * sizeof(int));
	}
	//初始化边界值
	for (int j = 0; j < s_len-1; j++) {
		dp[j][j] = 1;
		if (s[j] == s[j + 1]) {
			dp[j][j+1] = 1;
			*max_len = 2;
			max_len_position = j;
		}
	}
	dp[s_len-1][s_len-1] = 1;
	//使用动态规划：在循环固定起始点转态转移方程就可以确定了
	for (int len = 3; len < s_len+1; len++) {
		for (int start = 0; start < s_len - len+1; start++) {
			if (s[start] == s[start + len-1]&&(dp[start+1][start+len-2] == 1)) 
			{
				dp[start][start+len-1] = 1;
				*max_len =len;
				max_len_position = start;
			}
		}
	}
	return  max_len_position;
}
char* longestPalindrome(char* s) {

	if (s == NULL)
		return NULL;
	int s_len = strlen(s);
	if (s_len == 0 || s_len == 1) {
		return s;
	}
	int max_len = 1;
	int max_len_position = ipsec_get_max_sub_str(s, s_len, &max_len);
	char* new_str = (char*)malloc((max_len+1) * sizeof(char));
	(void)memcpy(new_str, s+ max_len_position, max_len);
	new_str[max_len] = '\0';
	return new_str;
}
int main() {
	char s[] = "aaaaa";
	char* s_new = longestPalindrome(s);
	printf("%s", s_new);
	return 0;

}