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