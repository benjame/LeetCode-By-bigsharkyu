class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                if (righ(nums[i], nums[i - 1]))
                    continue;
                else
                    return nums[i] - 1;
            }
            else if (i == 0 && nums[0] == 0)
                continue;
            else
                return 0;
        }
        if (N == 1) return nums[0] == 0 ? 1 : 0;
        else {
            return nums[N - 1] + 1;
        }
    }
private:
    bool righ(int val, int val2) {
        val = (val & 0x1);
        val2 = (val2 & 0x1);
        if (val == val2) return false;
        else return true;
    }
};

/**
 * Github答案
 * 思路解析：
 * 
 */
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= nums[i] ^ (i + 1);
        }
        return num;
    }
};


/**
 * Github答案2
 */

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> expected(nums.size());
        iota(expected.begin(), expected.end(), 1);  // Costs extra space O(n)
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>()) ^
               accumulate(expected.cbegin(), expected.cend(), 0, bit_xor<int>());
    }
};
