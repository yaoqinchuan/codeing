#include <stdio.h>
#include <string.h>
#include<stdlib.h>
long plus(int k) 
{
	long ans = 1;
	for (int i = 0; i < k; i++) {
		ans *= 10;
	}
	return ans;
}
void process_head(char **str,int *flag) {
	while (**str == ' ') {
		(*str)++;
	}
	if ((**str == '-') || (**str == '+')) {
		if (**str == '-') {
			*flag = 1;
		}
		str++;
	}
	while (**str == '0') {
		str++;
	}
}
int myAtoi(char* str) {
	int flag = 0;
	char* new_s;
	//去除头部信息
	process_head(&str, &flag);
	//只允许一个负号
	if ((*str > '9')||(*str <'0')){
		return 0;
	}
	int len = 0;;
	long ans = 0;
	for (int i = 0; i < strlen(str); i++) {
		//发现后面有非法数字
		if ((str[i] > '9') || (str[i] < '0')) {
			break;
		}
		len++;
	}
	if (len > 10) {
		if (flag == 0) {
			return 2147483647;
		}
		if (flag == 1) {
			return -2147483648;
		}
	}
	for (int i = 0; i < len; i++) {
		//发现后面有非法数字
		ans += (str[i] - '0') * plus(len - i - 1);
	}
	//检查溢出
	if ((ans > 2147483647) && (flag == 0)) {
		return 2147483647;
	}
	if ((ans > 2147483648) && (flag == 1)) {
		return -2147483648;
	}
	return flag == 1 ? -ans : ans;
}
int main() {
	char s[] = "-20000000000000000000";
	int new_s = myAtoi(s);
	printf("%d", new_s);
	return  0;
}