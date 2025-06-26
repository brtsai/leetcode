class Solution {
public:
    int rob(vector<int>& nums) {
        size_t numsSize = nums.size();
        if (numsSize < 3) {
            int max = 0;
            for (std::vector<int>::iterator itor = nums.begin(); itor != nums.end(); ++itor) {
                if (*itor > max) max = *itor;
            }
            return max;
        }
        std::vector<int> memo(numsSize, 0);
        memo[numsSize - 1] = nums[numsSize - 1];
        memo[numsSize - 2] = std::max(nums[numsSize - 1], nums[numsSize - 2]);

        for (size_t reverseIndex = numsSize - 3; reverseIndex > 0; --reverseIndex) {
            memo[reverseIndex] = std::max(nums[reverseIndex] + memo[reverseIndex + 2], memo[reverseIndex + 1]);
        }

        return std::max(nums[0] + memo[2], memo[1]);
    }
};

/**
 Opt(i) = max(money[i] + Opt(i+2), Opt(i+1))
*/
