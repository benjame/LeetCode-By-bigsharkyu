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
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        return accumulate(A.cbegin(), A.cend(), 0, std::bit_xor<int>());
    }
};

class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        int single = 0;
        for (const auto& i : A) {
            single ^= i;
        }

        return single;
    }
};

/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，BAT国内班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A : an integer array
     * return : a integer 
     */
    int singleNumber(vector<int> &A) {
        int x;
        for (int i = 0; i < A.size(); i++) {
            x ^= A[i];
        }
        return x;
    }
};

