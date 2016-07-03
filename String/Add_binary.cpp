/**
 * 我的初步解法
 */
class Solution {
public:
    string addBinary(string a, string b) {
        unsigned long A = std::stoul(a, 0, 2);
        unsigned long B = std::stoul(b, 0, 2);
        unsigned long sum = A + B;
        // string res = to_string(sum);
        string res = "";
        string res2 = "";
        for (int i = 63; i >= 0; --i) {
            if (sum & 1 << i)
                res.push_back('1');
            else res.push_back('0');
        }
        vector<char> v1 = {'1'};
        auto it_stop = std::find_first_of(v1.cbegin(), v1.cend(), res.cbegin(), res.cend());
        for (auto it = it_stop; it != res.cend(); ++it) {
            res2.push_back(*it);
        }
        return res2;
    }
};

/**
 * GIthub解法
 * 
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        size_t res_len = max(a.length(), b.length()) ;

        size_t carry = 0;
        for (int i = 0; i < res_len; ++i) {
            const size_t a_bit_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            const size_t b_bit_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            size_t sum = carry + a_bit_i + b_bit_i;
            carry = sum / 2;
            sum %= 2;
            res.push_back('0' + sum);
        }
        if (carry) {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

// Iterator solution.
class Solution2 {
public:
    string addBinary(string a, string b) {
        size_t carry = 0;
        string res;

        for (auto a_it = a.rbegin(), b_it = b.rbegin(); a_it != a.rend() || b_it != b.rend();) {
            const size_t a_bit_i = (a_it != a.rend()) ? *a_it - '0' : 0;
            const size_t b_bit_i = (b_it != b.rend()) ? *b_it - '0' : 0;
            size_t sum = a_bit_i + b_bit_i + carry;
            carry = sum / 2;
            sum %= 2;
            res.push_back('0' + sum);

            if (a_it != a.rend()) {
                ++a_it;
            }
            if (b_it != b.rend()) {
                ++b_it;
            }
        }
        if (carry) {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};