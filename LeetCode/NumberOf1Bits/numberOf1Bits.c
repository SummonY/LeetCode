#include <stdio.h>

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n);

int main(int argc, const char *argv[])
{
    uint32_t num = 0x0FFF00FF;
    printf("numbers of 1 bits = %d\n", hammingWeight(num));
    return 0;
}

int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n & 1) != 0) {
            ++count;
        }
        n = n >> 1;
    }
    return count;
}
