/**
 *  This code below was written by me.
 *  but I don't use bit_manipulation.
 *  T-O(n^2)
 *  S-O(1)
 */
class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        for (int i : A) {
            bool flag = false;
            for (int j : A) {
                if (i == j) {
                    flag = (!flag);
                }
            }
            if (flag) return i;
        }
    }
};

/**
 * This code was written by Others,which need to be learn by me;
 * @author kamyu104
 * T-O(n)
 * S-O(1)
 */

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        int one = 0, two = 0;
        for (const auto& i : A) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }
        return one;
    }
};