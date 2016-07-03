/**
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 */


/**
 * 利用KMP算法硬钢的方法
 * 思路比较常规
 */
class Solution {
public:
    int strStr(string haystack, string needle) {

    }
};


/**
 * 一种简练的方法
 * 相当于做一个"needle的卡尺"
 * 卡尺在haystack上滑动
 * 
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};