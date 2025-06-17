class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, size_t> numsToIndex;
        for(size_t index = 0; index < nums.size(); ++index) {
            int curr = nums[index];
            std::unordered_map<int, size_t>::iterator reciprocalIndexItor = numsToIndex.find(target - curr);
            if (reciprocalIndexItor != numsToIndex.end()) {
                return {static_cast<int>(reciprocalIndexItor->second), static_cast<int>(index)};
            }

            numsToIndex[curr] = index;
        }

        return {-1, -1};
    }
};
