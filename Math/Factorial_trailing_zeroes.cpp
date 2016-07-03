/**
 * 思路分析：
 * 因为所有的trailingZeros（结尾0）都是来自于 2 * 5
 * 对于n!来说，2的数目总是足够的，我们只需要计算5的数目即可
 * 最短的写法就是用递归
 */

class Solution {
public:
    int trailingZeroes(int n) {
         return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

