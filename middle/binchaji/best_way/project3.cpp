/*检查一个图是否存在环路
思路：使用并查集
*/
#include <stdio.h>
#include <stdlib.h>
int  find_root(int x, int* parent, int len)
{
	int root = x;
	while (root != parent[root]) {
		root = parent[root];
	}
	return root;
}
int union_root(int x_1, int x_2, int *parent, int len) 
{
	int root1 = find_root(x_1, parent, len);
	int root2 = find_root(x_2, parent, len);
	if (root1 != root2) {
		parent[root1] = root2; // 合并
		return 0;
	}
	return 1;
}
typedef struct edge {
	int x;
	int y;
}edge_s;
edge_s edges[]{
	{0, 1},
	{3, 4},
	{1, 2},
	{1, 3},
	//{2, 4},
	{2, 5}
};
#define MAX_EDGE 1000
bool if_exist_cycle() 
{
	int edge_count = sizeof(edges) / sizeof(edge_s);
	int parent[MAX_EDGE] = { 0 };
	for (int i = 0; i < MAX_EDGE; i++) {
		parent[i] = i;
	}
	// 录入参数
	for (int i = 0; i < edge_count; i++){
		if (union_root(edges[i].x, edges[i].y, parent , MAX_EDGE)) {
			printf("cycle detected!\r\n");
			return true;
		}
	}
	printf("no cycle detected.\r\n");
	return false;
}
int main() 
{
	(void)if_exist_cycle();
	return 0;
}