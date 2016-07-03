/**
 * 注意：不是4的倍数而是4的幂次
 * 
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        if (num == 0 || num & 0x3) return false;
        int temp = num;
        while (temp /= 4) {
            if (temp & 0x3 && m != 1) return false;
        }
        return true;
    }
};

