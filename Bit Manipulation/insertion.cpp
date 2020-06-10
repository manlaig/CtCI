#include "utils.h"

/*
    1. create a mask that will decide which elements will be inserted from M
    2. clear all bits OUTSIDE the [i, j] range in M
    3. clear all bits INSIDE the [i, j] range in M
    4. OR M and N together
*/

// insert M into N from index i to j
int insert(int N, int M, unsigned i, unsigned j)
{
    // clearing all the bits from i to j
    // -1u means -1 in unsigned, which is all 1s
    uint32_t mask = ~(((-1u << (32 - j)) >> (31 - j + i)) << i);

    // clearing bits outside i and j because we'll be ORing them together
    // shifting mask by i because we want to insert M from index 0
    M &= ~(mask >> i);
    N = (N & mask) | (M << i);
    std::cout << "mask: ";
    Bit::print(mask);
    // Bit::print(N);
    // Bit::print(M);
    return N;
}

int main()
{
    Bit::print(insert(128,31,2,5));
}