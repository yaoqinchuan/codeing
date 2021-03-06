﻿/*最小生成树算法
思路：Kruskal(克鲁斯卡尔）使用并查集
优化：使用路径压缩
1、完全压缩
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct edge {
	int x;
	int y; 
	int weight; // 权重
}edge_s;
edge_s edges[]{
	{0, 1, 4},
	{0, 7, 8},
	{1, 2, 8},
	{1, 7, 11},
	{2, 8, 2},
	{2, 3, 7},
	{2, 5, 4},
	{3, 4, 9},
	{3, 5, 14},
	{4, 5, 10},
	{5, 6, 2},
	{6, 7, 1},
	{7, 8, 7}
};
int  find_root(int x, int* parent, int len)
{
	int root = x;
	while (root != parent[root]) {
		root = parent[root];
	}
	return root;
}
int union_root(edge_s single_edge, int* parent, int* cost, int len)
{
	int root1 = find_root(single_edge.x, parent, len);
	int root2 = find_root(single_edge.y, parent, len);
	if (root1 != root2) {
		parent[root2] = root1;
		(*cost) += single_edge.weight;
		return 0;
	}
	return 1;
}
int cmp(const* void a, const void* b) 
{
	int weight1 = ((edge_s*)a)->weight;
	int weight2 = ((edge_s*)b)->weight;
	return weight1 - weight2;
}
#define MAX_EDGE 1000
int find_path(int *path, int *count,int start, int end) 
{
	int edge_count = sizeof(edges) / sizeof(edge_s);
	int parent[MAX_EDGE] = { 0 };
	int cost = 0;
	int position = 0;
	for (int i = 0; i < MAX_EDGE; i++) {
		parent[i] = i;
	}
	qsort(edge_s, edge_count, sizeof(edge_s), cmp);
	// 录入参数
	for (int i = 0; i < edge_count; i++){
		union_root(edges[i], parent, &cost, MAX_EDGE);
	}
	while (start != parent[start])
	{
		path[position++] = start;
		start = parent[start];
	}
	int index = 0;
	int temp_path[MAX_EDGE] = { 0 };
	while (end != parent[end])
	{
		temp_path[index++] = end;
		end = parent[end];
	}
	for (int i = 0; i < index; i++)
	{
		path[position++] = temp_path[i];
	}
	*count = position;
	return cost;
}
int main() 
{
	int path[MAX_EDGE] = { 0 };
	int count = 0;
	int cost = find_path(path, &count, 0, 4);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", path[i]);
	}
	printf("\r\n");
	printf("total cost is %d \n", count);
	return 0;
}