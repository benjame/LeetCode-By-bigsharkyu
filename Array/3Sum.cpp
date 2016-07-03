/**
 * Given an array S of n integers,
 * are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 */

/**
 * 以下代码思考有欠缺，有漏解情况
 * 我的思路是：先找出所有的2值和（不一样的），其实这是有问题的
 * 因为有可能俩个不同的值但是他们的和是一样的这样就会忽略掉一些解
 * 解决办法：
 * 关键：一旦确定一个2值和，那么第三个数也就随之确定
 * 橙色算法书有讲，明天看看
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sum2v;
        vector<vector<int>> res;
        vector<int> num2;
        int sum2;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    sum2 = nums[i] + nums[j];
                    if (std::count(sum2v.cbegin(), sum2v.cend(), sum2) == 0) {
                        sum2v.push_back(sum2);
                        num2.push_back(nums[i]);
                        num2.push_back(nums[j]);
                        for (int k = 0; k < nums.size(); ++k) {
                            if (k != i && k != j && (sum2 += nums[k]) == 0) {
                                num2.push_back(nums[k]);
                                res.push_back(num2);
                                num2.clear();
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

/**
 * 按照橙色算法书的思路再撸一遍
 *
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = static_cast<int>(nums.size());
        vector<vector<int>> res;
        std::vector<int> v;
        std::sort(nums.begin(), nums.end());    //O(NlogN)
        for (int i = 0; i < N; ++i) {
            for (int j = (i + 1); j < N; ++j) {
                if (std::binary_search(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j]))) {   //O(logN)
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(-nums[i] - nums[j]);
                    res.push_back(v);
                    v.clear();
                }
            }
        }
        return res;
    }
};

/**
 * GitHub答案
 * 思路：
 *
 */
// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {  // Should decrease sum.
                            --k;
                        } else if (sum < target) {  // Should increase sum.
                            ++j;
                        } else {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }

        return ans;
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
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // two sum;
            int start = i + 1, end = nums.size() - 1;
            int target = -nums[i];
            while (start < end) {
                if (start > i + 1 && nums[start - 1] == nums[start]) {
                    start++;
                    continue;
                }
                if (nums[start] + nums[end] < target) {
                    start++;
                } else if (nums[start] + nums[end] > target) {
                    end--;
                } else {
                    vector<int> triple;
                    triple.push_back(nums[i]);
                    triple.push_back(nums[start]);
                    triple.push_back(nums[end]);
                    result.push_back(triple);
                    start++;
                }
            }
        }

        return result;
    }
};

