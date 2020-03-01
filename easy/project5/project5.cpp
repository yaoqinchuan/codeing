#include<stdio.h>
void get_next_array(char* pattern, int* next, int total_len) {
	int k = 0;
	int i = 1;
	next[0] = -1;
	next[1] = 0;
	while (i < total_len) {
		while (pattern[i] != pattern[k] && k > 0)
		{
			k = next[k - 1];
			if ((k == -1)&&(pattern[i]==pattern[0])) {
				k = 0;
			}
		}
		if (pattern[i] == pattern[k]) {
			k++;
		}
		next[i] = k;
		i++;
	}
}
int main() 
{
	char s[] = { 'a','b','c','d', 'a','b' };
	int next[6] = { 0 };
	get_next_array(s, next, 6);
	return 0;
}
int strStr(char* haystack, char* needle) {
	return 1;
}