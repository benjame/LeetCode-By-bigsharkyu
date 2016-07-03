/**
 * Given an integer, write a function to determine if it is a power of two.
 *
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n & 0x1 || n == 0) return false;
        int m = n;
        while (m /= 2) {
            if (m & 0x1 && m != 1) {
                return false;
            }
        }
        return true;
    }
};