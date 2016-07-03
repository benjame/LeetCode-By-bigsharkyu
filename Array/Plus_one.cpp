/*
* Given a non-negative number represented as an array of digits, plus one to the number.
* The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.cbegin(), digits.cend());
        int carry = 1;
        for (auto it = result.rbegin(); it != result.rend(); it++) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }      
        if (carry == 1) {
            result.emplace(result.begin(), carry);
        }
        return result;
    }
};