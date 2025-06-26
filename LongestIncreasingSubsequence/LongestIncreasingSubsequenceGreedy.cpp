class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> ans;

        ans.push_back(nums[0]);

        for (int index = 1; index < numsSize; index++) {
            int currNum = nums[index];
            if (currNum > ans.back()) {
                ans.push_back(nums[index]);
            }
            else {
                size_t low = 0;
                while (ans[low] < currNum) ++low; // can replace with binSearch std::lower_bound

                ans[low] = currNum;
            }
        }
        
        return ans.size();
    }
};

// https://www.geeksforgeeks.org/dsa/longest-monotonically-increasing-subsequence-size-n-log-n/
