Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        //计算每一位用与&的方法
        int res = 0;
        int carry = 0;
        int var = 0;
        for (int i = 0; i < 32; i++) {
            int a1 = a & 0x01;
            int b1 = b & 0x01;
            if (a1 == 1 && b1 == 1 && carry == 1) {
                var = 1;
                carry = 1;
            }
            else if ((a1 == 1 && b1 == 1) || (a1 == 1 && carry == 1) || (b1 == 1 && carry == 1)) {
                var = 0;
                carry = 1;
            }
            else if (a1 == 1 || b1 == 1 || carry == 1) {
                var = 1;
                carry = 0;
            }
            else {
                var = 0;
                carry = 0;
            }
            var = var << i;
            res = res | var;
            a = a >> 1;
            b = b >> 1;
        }
        return res;

    }
};
