/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) 
{
    int* number1 = (int*)a;
    int* number2 = (int*)b;
    return (*number1) - (*number2);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    q_sort(nums, numsSize, sizeof(int), cmp); // 先行排序
    for (int i = 0; i < numsSize; i++) {
        int target1 = target - nums[i];
        if (target1 = target - nums[i - 1 < 0 ? 0 : i - 1]) {
            continue;
        }
        for (int j = 0; j < length; j++)
        {
            int target1 = target - nums[i];
            if (target1 = target - nums[i - 1 < 0 ? 0 : i - 1]) {
                continue;
            }
        }
    }
}