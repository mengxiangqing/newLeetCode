/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

// ​uthash 是C的比较优秀的开源代码，已经集成到最新的GCC。它实现了常见的hash操作函数，例如查找、插入、删除等待。该套开源代码采用宏的方式实现hash函数的相关功能，支持C语言的任意数据结构最为key值，甚至可以采用多个值作为key，无论是自定义的struct还是基本数据类型，需要注意的是不同类型的key其操作接口方式略有不同。使用uthash代码时只需要包含头文件"uthash.h"即可。由于该代码采用宏的方式实现，所有的实现代码都在uthash.h文件中，因此只需要在自己的代码中包含该头文件即可。
#include "uthash.h"
#include "stdio.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *res = malloc(sizeof(int) * 2);
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }

    return NULL;
}

struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int ikey)
{
    struct hashTable *tmp;
    HASH_FIND_INT(hashTable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival)
{
    struct hashTable *it = find(ikey);
    if (it == NULL)
    {
        struct hashTable *tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashTable, key,tmp);
    }else{
        it->val = ival;
    }
        
}

// @lc code=end
