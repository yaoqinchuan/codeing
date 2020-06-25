/*
题目：给定一个整形字符串，最长回文字符
思路：一道简单的dp问题，只要当前的子串的和不为负值就有加的意义
               |sub_str_len[n-1]+1 if str[i] not appear;
sub_str_len[n]=|
               |1                  if str[i]  appear;
max_sum=max{sub_str_len[1],sub_str_len[2],...sub_str_len[n]};
*/