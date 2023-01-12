/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#define INIT_NUM 128

int lengthOfLongestSubstring(char *s)
{
    if (s[0] == '\0')
    {
        return 0;
    }
    int maxLength = 1;
    // 声明记录数组,如果字符存在则为1，不存在则为0
    int temp[128];
    // 初始化数组
    for (int i = 0; i < INIT_NUM; i++)
    {
        temp[i] = 0;
    }
    // 左右边界下标值
    int l = 0, r = 0;
    while (s[r] != '\0')
    {
        // 不在子串内，置值为1
        if (temp[s[r]] == 0)
        {
            temp[s[r]] = 1;
            r++;
            // 检查一下边界
            if (temp[s[r]] == 0)
            {
                // 计算当前长度
                maxLength = r - l > maxLength ? r - l : maxLength;
            }
        }
        // 遇到重复字符，计算长度并比较
        else
        {
            int tempLength = r - l;
            maxLength = tempLength > maxLength ? tempLength : maxLength;
            // 右移左边界
            while (l < r)
            {
                // 右移直到遇见相同字符
                if (s[l] == s[r])
                {
                    l++;
                    r++;
                    break;
                }
                else
                {
                    // 从已选子串中移除，即归零
                    temp[s[l]] = 0;
                    l++;
                }
            }
        }
    }

    return maxLength;
}

// @lc code=end
