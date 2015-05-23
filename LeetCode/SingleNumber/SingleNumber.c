#include <stdio.h>

int singleNumber(int *nums, int numsSize);


int main(int argc, const char *argv[])
{
    int a[] = {3, 0, 9, 4, 2, 1, 3, 1, 2, 4, 9, 11, 0};
    int sn;

    sn = singleNumber(a, 13);
    printf("%d\n", sn);    
    return 0;
}

int singleNumber(int *nums, int numsSize)
{
    int sn = 0;
    for (int i = 0; i < numsSize; ++i) {
        sn = sn ^ nums[i];
    }
    return sn;
}
