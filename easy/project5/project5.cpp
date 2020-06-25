#include<stdio.h>
#include<string>
int cmp(const void* elem1, const void* elem2) 
{
    int* p1 = (int*)elem1;
    int* p2 = (int*)elem2;
    return *p1 - *p2;
}
int ** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** new_array = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++)
    {
        new_array[i] = (int*)malloc(3 * sizeof(int));
    }
    int num_col = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int low = 0; low < length; low++)
    {
        if (low > 0) {
            return;
        }
        int midd = low + 1;
        int end = numsSize - 1;
        int flag = 0;
        while (midd != end)
        {
            if (nums[midd] + nums[end] > -nums[low]) {
                end--;
                continue;
            }
            if ((midd <= end)&&(nums[midd] + nums[end] < -nums[low])) {
                midd++;
                continue;
            }
            if ((midd <= end) && (nums[midd] + nums[end] == -nums[low])) {
                new_array[num_col][0] = nums[low];
                new_array[num_col][1] = nums[midd];
                new_array[num_col][2] = nums[end];
                num_col++;
                midd++;
                end--;
                continue;
            }

        }
        low++;
    }
    for (int i = 0; i < num_col; i++)
    {
        *returnColumnSizes[i] = 3;
    }
    *returnSize = num_col - 1;
    return new_array;
}
int main() 
{
    int size =  0;
    int nums[] = {-1, 0, 1, 2, -1, -4};
    threeSum(nums, 6, &size);
	return 0;
}
