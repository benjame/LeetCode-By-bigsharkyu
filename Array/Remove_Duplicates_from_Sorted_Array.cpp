/*
* @Description: Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
* Do not allocate extra space for another array, you must do this in place with constant memory.
* For example,
* Given input array nums = [1,1,2],
* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            nums[i++] = nums[j];
            while (nums[j] == nums[i - 1]) ++j; //keep moving forward until meet another different value
        }
        return i;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = -1;
        for (const auto& num : nums) {
            if (last == -1 || nums[last] != num) {
                nums[++last] = num;
            }
        }
        return last + 1;
    }
};