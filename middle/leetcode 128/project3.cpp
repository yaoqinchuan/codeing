/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例 :

输入: [100, 4, 200, 1, 3, 2]
输出 : 4
解释 : 最长连续序列是[1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct a {
    int val;
    int idx;
    UT_hash_handle hh;
} Node;

Node* g_map;
int* g_set;

int* MakeSet(int n)
{
    int* set = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }
    return set;
}
int* MakeHash(int* nums, int numsSize, int* returnSize)
{
    Node* s = NULL;
    int* newNums = calloc(numsSize, sizeof(int));
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(g_map, &nums[i], s);
        if (s == NULL) {
            newNums[cnt++] = nums[i];  /* 去掉原数组中重复项，如果已经在hash表中，则不再保存 */
            s = calloc(1, sizeof(Node));
            s->val = nums[i];
            s->idx = cnt - 1;   /* 保存新数组newNums中的索引 */
            HASH_ADD_INT(g_map, val, s);
        }
    }
    *returnSize = cnt;
    return newNums;
}
int Find(int a)
{
    int m = a;
    while (g_set[m] != m) {
        g_set[m] = g_set[g_set[m]];
        m = g_set[m];
    }
    return m;
}
void Merge(int a, int b)
{
    g_set[Find(a)] = Find(b);
}
int longestConsecutive(int* nums, int numsSize)
{
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    g_map = NULL;
    int cnt = 0;
    int* newNums = MakeHash(nums, numsSize, &cnt);
    g_set = MakeSet(cnt);
    Node* s = NULL;
    for (int i = 0; i < cnt; i++) {
        int tmp;
        if (newNums[i] > INT_MIN) { /* 每个数，查找hash表中是否存在前一项 */
            tmp = newNums[i] - 1;
            HASH_FIND_INT(g_map, &tmp, s);
            if (s != NULL) {
                Merge(s->idx, i);
            }
        }
        if (newNums[i] < INT_MAX) {  /* 每个数，查找hash表中是否存在后一项 */
            tmp = newNums[i] + 1;
            HASH_FIND_INT(g_map, &tmp, s);
            if (s != NULL) {
                Merge(s->idx, i);
            }
        }
    }
    int* count = calloc(cnt, sizeof(int));
    for (int j = 0; j < cnt; j++) {  /* 统计最终有多少个集合，每个集合有多少个元素 */
        count[Find(j)]++;
    }
    int max = 0;
    for (int k = 0; k < cnt; k++) { /* 找到最大集合的元素个数就是解 */
        if (count[k] > max) {
            max = count[k];
        }
    }
    Node* tmp;
    HASH_ITER(hh, g_map, s, tmp) {
        HASH_DEL(g_map, s);
        free(s);
    }
    free(newNums);
    return max;
}

}