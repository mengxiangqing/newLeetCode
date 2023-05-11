/*
 * @lc app=leetcode.cn id=1015 lang=c
 *
 * [1015] 可被 K 整除的最小整数
 */

// @lc code=start
#include "uthash.h"
typedef struct
{
    int key;
    UT_hash_handle hh;
} HashItem;

int smallestRepunitDivByK(int k)
{
    // 当k为2或5的倍数时，肯定无解，不会产生尾数为1的数字
    if (k % 2 == 0 || k % 5 == 0)
    {
        return -1;
    }
    int len = 0;
    long n = 1;
    for (int i = 1; i < 64; i++)
    {
        if (n % k == 0)
        {
            return i;
        }
        n = n * 10 + n;
    }

    return -1;
}
// @lc code=end
