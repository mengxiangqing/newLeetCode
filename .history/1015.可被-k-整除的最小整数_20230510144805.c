/*
 * @lc app=leetcode.cn id=1015 lang=c
 *
 * [1015] 可被 K 整除的最小整数
 */

// @lc code=start

int smallestRepunitDivByK(int k)
{
    int len = 0;
    int n = 1;
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
